#include "ProtoAMR.H"
#include "InputParser.H"
#include "BoxOp_Laplace.H"
#include "LevelSolver_FASMultigrid.H"

using namespace Proto;

PROTO_KERNEL_START void f_force_0(const Point& a_pt, Var<double> a_data, double a_dx)
{
    double x[DIM];
    
    a_data(0) = 1.0;
    for (int dir = 0; dir < DIM; dir++)
    {
        x[dir] = a_pt[dir]*a_dx + a_dx/2.0;
        a_data(0) = a_data(0)*sin(M_PI*2*(x[dir] + .125));
    }
}
PROTO_KERNEL_END(f_force_0, f_force);

PROTO_KERNEL_START void f_force_avg_0(const Point& a_pt, Var<double> a_data, double a_dx)
{
    double x0[DIM];
    double x1[DIM];
    
    double a = 0.125;
    for (int dir = 0; dir < DIM; dir++)
    {
        x0[dir] = a_pt[dir]*a_dx + a;
        x1[dir] = x0[dir] + a_dx;
    }
    
    double k = M_PI*2;
    a_data(0) = + cos(k*x1[0])*cos(k*x1[1])
                - cos(k*x0[0])*cos(k*x1[1])
                - cos(k*x1[0])*cos(k*x0[1])
                + cos(k*x0[0])*cos(k*x0[1]);
    a_data(0) *= 1.0/(k*k*a_dx*a_dx);
}
PROTO_KERNEL_END(f_force_avg_0, f_force_avg);

PROTO_KERNEL_START void f_soln_0(const Point& a_pt, Var<double> a_data, double a_dx)
{
    double x[DIM];
    
    a_data(0) = -1/(DIM*pow(2.0*M_PI, 2));
    for (int dir = 0; dir < DIM; dir++)
    {
        x[dir] = a_pt[dir]*a_dx + a_dx/2.0;
        a_data(0) = a_data(0)*sin(M_PI*2*(x[dir] + .125));
    }
}
PROTO_KERNEL_END(f_soln_0, f_soln);

PROTO_KERNEL_START void f_soln_avg_0(const Point& a_pt, Var<double> a_data, double a_dx)
{
    double x0[DIM];
    double x1[DIM];
    
    double a = 0.125;
    for (int dir = 0; dir < DIM; dir++)
    {
        x0[dir] = a_pt[dir]*a_dx + a;
        x1[dir] = x0[dir] + a_dx;
    }
    
    double k = M_PI*2;
    a_data(0) = + cos(k*x1[0])*cos(k*x1[1])
                - cos(k*x0[0])*cos(k*x1[1])
                - cos(k*x1[0])*cos(k*x0[1])
                + cos(k*x0[0])*cos(k*x0[1]);
    a_data(0) *= 1.0/(k*k*a_dx*a_dx);
    a_data(0) *= -1.0/(DIM*pow(k, 2.0));
}
PROTO_KERNEL_END(f_soln_avg_0, f_soln_avg);

int MG_LEVEL = 0;
int SOLVE_ITER = 0;

int main(int argc, char** argv)
{
    #ifdef PR_MPI
    MPI_Init(&argc, &argv);
    #endif

    // SETUP
    using Proto::pout;
    HDF5Handler h5;
    InputArgs args;
    args.parse();
    args.print();

    int domainSize = 64;
    int boxSize = 16;
    int numIter = 3;
    int solveIter = 20;
    int numLevels = log(1.0*domainSize)/log(2.0) + 1;
    double tolerance = 1e-10;
    int ghostSize = 1;
    double k = 1;
    int refRatio = 2;
    double physDomainSize = 1;
    std::array<bool, DIM> periodicity;
    for (int dir = 0; dir < DIM; dir++) { periodicity[dir] = true; }

    args.set("domainSize", &domainSize);
    args.set("boxSize",    &boxSize);
    args.set("numIter",    &numIter);
    args.set("numLevels",  &numLevels);
    args.set("solveIter",  &solveIter);
    args.set("tolerance",  &tolerance);
    args.set("refRatio",   &refRatio);
    args.set("periodic_x", &periodicity[0]);
    args.set("periodic_y", &periodicity[1]);
    
    typedef BoxOp_Laplace<double> OP;
    
    double err[numIter];
    for (int nn = 0; nn < numIter; nn++)
    {
        // BUILD GRIDS
        
        double dx = physDomainSize / domainSize;
        std::array<double, DIM> dxVect;
        dxVect[0] = dx;
        dxVect[1] = dx/2;

        // coarse layout
        Point boxSizeV = Point::Ones(boxSize);
        Box domainBox = Box::Cube(domainSize);
        ProblemDomain domain(domainBox, periodicity);
        DisjointBoxLayout layout(domain, boxSizeV);
        
        // solver
        LevelSolver_FASMultigrid<BoxOp_Laplace, double> solver(layout, Point::Ones(refRatio), numLevels, dx);
        solver.setVerbose(true);

        // data holders
        LevelBoxData<double, OP::numState()> Phi(layout, OP::ghost());
        LevelBoxData<double, OP::numState()> PhiSln(layout, Point::Zeros());
        LevelBoxData<double, OP::numState()> PhiErr(layout, Point::Zeros());
        LevelBoxData<double, OP::numState()> G(layout, Point::Zeros());
        Phi.setToZero();
        G.initialize(f_force_avg, dx);
        PhiSln.initialize(f_soln_avg, dx);
       
        h5.writeLevel(dx, PhiSln, "SLN_N%i", nn);
        h5.writeLevel(dx, G,       "G_N%i", nn);
        pout() << "Integral of RHS: " << G.integrate(dx) << std::endl;

        solver.solve(Phi, G, solveIter, tolerance);

        h5.writeLevel(dx, Phi,    "PHI_N%i", nn);
        
        for (auto iter = layout.begin(); iter.ok(); ++iter)
        {
            auto& phi_i = Phi[*iter];
            auto& sln_i = PhiSln[*iter];
            auto& err_i = PhiErr[*iter];
        
            phi_i.copyTo(err_i);
            err_i -= sln_i;
        }
        h5.writeLevel(dx, PhiErr,    "ERR_N%i", nn);
        err[nn] = PhiErr.absMax();
        pout() << "Error: " << err[nn] << std::endl;
        domainSize *= 2;
    }
        
    for (int ii = 1; ii < numIter; ii++)
    {
        pout() << "Convergence Rate: " << log(err[ii-1] / err[ii]) / log(2.0) << std::endl;
    }

    #ifdef PR_MPI
    MPI_Finalize();
    #endif
    return 0;
}

