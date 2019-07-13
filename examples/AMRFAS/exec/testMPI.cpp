#include "LevelData.H"
#include "Proto.H"
#include "AMRData.H"

int main(int argc, char** argv) 
{
#ifdef CH_MPI
    MPI_Init(NULL, NULL);
    int mpi_world_size;
    int mpi_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &mpi_world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &mpi_rank);
    
    double x = 2;
    double X = 0;
    MPI_Reduce(&x, &X, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    std::cout << "Sum on rank " << mpi_rank << " = " << X << std::endl;
#endif

    /*
    int domainSize = 32;
    double L = 2.0*M_PI;
    auto domain = Proto::Box::Cube(domainSize);
    auto fineDomain = Proto::Box::Cube(domainSize / 2).shift(Proto::Point::Ones(domainSize / 4));
    fineDomain = fineDomain.refine(AMR_REFRATIO);
    std::vector<Proto::Box> domainBoxes;
    domainBoxes.push_back(domain);
    domainBoxes.push_back(fineDomain);
    AMRLayout Layout(domainBoxes, Proto::Point::Ones());
    AMRData<1> Data(Layout, Proto::Point::Zeros(), L/domainSize, false);
    Data.initialize([=] PROTO_LAMBDA (Proto::Point a_pt, Proto::Var<Real, 1>& a_data, Real a_dx)
    {
        double x = a_pt[0]*a_dx;
        a_data(0) = sin(x);
    }, L/domainSize);
    Data.write("Data.hdf5");
    if (mpi_rank == 0)
    {
        double max = Data.absMax();
        std::cout << "Max value: " << max << std::endl;
        double integral = Data.integrate();
        std::cout << "Integral value: " << integral << std::endl;
    }
    */
#ifdef CH_MPI
    MPI_Finalize();
#endif
}
