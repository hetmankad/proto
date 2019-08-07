// 'euler_step' code generated by 'edavis' at 08/06/2019 11:10:30
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define abs(x) ((x)<0?-(x):(x))
#define absmin(x,y) ((x)=min(abs((x)),abs((y))))
#define absmax(x,y) ((x)=max(abs((x)),abs((y))))
#define floord(x,y) ((x)/(y))
#define sgn(x) ((x)<0?-1:1)
#define offset2(i,j,M) ((j)+(i)*(M))
#define offset3(i,j,k,M,N) ((k)+((j)+(i)*(M))*(N))
#define offset4(i,j,k,l,M,N,P) ((l)+((k)+((j)+(i)*(M))*(N))*(P))
#define arrinit(ptr,val,size) for(unsigned __i__=0;__i__<(size);__i__++) (ptr)[__i__]=(val)
#define arrprnt(name,arr,size) {\
fprintf(stderr,"%s={",(name));\
for(unsigned __i__=0;__i__<(size);__i__++) fprintf(stderr,"%lg,",(arr)[__i__]);\
fprintf(stderr,"}\n");}
#define tid omp_get_thread_num()
#define C 4
#define D 2
#define G 4
#define N 64
#define T 8
#define U(c,y,x) U[offset3((c),(y)+4,(x)+4,(N+3+4+1),(N+3+4+1))]
#define W_bar(c,y,x) array1[tid][offset3((c),(y)+4,(x)+4,(N+3+4+1),(N+3+4+1))]
#define u(c,y,x) array2[tid][(c)]
#define W(c,y,x) array3[tid][offset3((c),(y)+3,(x)+3,(N+2+3+1),(N+2+3+1))]
#define umax(y,x) scalar8[tid]
#define retval retval_[tid]
//#define W_ave(c,y,x) array0[tid][offset3((c),(y)+3,(x)+3,(N+2+3+1),(N+2+3+1))]
#define W_ave(c,y,x) array9[tid][offset3((c),(y)+3,(x)+3,(N+2+3+1),(N+2+3+1))&1023]
#define W_aveL_d1(c,y,x) array7[tid][offset3((c),(y)+3,(x),(N+2+3+1),(N+1+1))]
#define W_aveH_d1(c,y,x) array6[tid][offset3((c),(y)+3,(x)+1,(N+2+3+1),(N+1+1))]
#define W_aveL_d2(c,y,x) array5[tid][offset3((c),(y),(x)+3,(N+1+1),(N+2+3+1))]
#define W_aveH_d2(c,y,x) array4[tid][offset3((c),(y)+1,(x)+3,(N+1+1),(N+2+3+1))]
//#define W_ave_f_d1(c,y,x) array0[tid][offset3((c),(y)+3,(x),(N+2+3+1),(N+1))]
#define W_ave_f_d1(c,y,x) array9[tid][offset3((c),(y)+3,(x),(N+2+3+1),(N+1))&1023]
//#define F_bar_f_d1(c,y,x) array1[tid][offset3((c),(y)+3,(x),(N+2+3+1),(N+1))]
#define F_bar_f_d1(c,y,x) array10[tid][offset3((c),(y)+3,(x),(N+2+3+1),(N+1))&1023]
#define W_f_d1(c,y,x) array2[tid][(c)]
//#define F_ave_f_d1(c,y,x) array3[tid][offset3((c),(y)+2,(x),(N+1+2+1),(N+1))]
#define F_ave_f_d1(c,y,x) array11[tid][offset3((c),(y)+2,(x),(N+1+2+1),(N+1))&1023]
#define rhs(c,y,x) rhs[offset3((c),(y),(x),(N-1+1),(N-1+1))]
//#define W_ave_f_d2(c,y,x) array0[tid][offset3((c),(y),(x)+3,(N+1),(N+2+3+1))]
#define W_ave_f_d2(c,y,x) array9[tid][offset3((c),(y),(x)+3,(N+1),(N+2+3+1))&1023]
//#define F_bar_f_d2(c,y,x) array1[tid][offset3((c),(y),(x)+3,(N+1),(N+2+3+1))]
#define F_bar_f_d2(c,y,x) array10[tid][offset3((c),(y),(x)+3,(N+1),(N+2+3+1))&1023]
#define W_f_d2(c,y,x) array2[tid][(c)]
//#define F_ave_f_d2(c,y,x) array3[tid][offset3((c),(y),(x)+2,(N+1),(N+1+2+1))]
#define F_ave_f_d2(c,y,x) array11[tid][offset3((c),(y),(x)+2,(N+1),(N+1+2+1))&1023]

double euler_step(const double* U, double* rhs);
inline double euler_step(const double* U, double* rhs) {
    int t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15;
    int tnum = 1;
    #pragma omp parallel num_threads(1)
    {
        tnum = min(max(tnum, omp_get_max_threads()), N/T);
    }
    double retval__ = 0.0;
    double* __restrict retval_ = (double*) malloc(tnum*sizeof(double));
    double* __restrict scalar8 = (double*) malloc(tnum*sizeof(double));
    double** __restrict array1 = (double**) malloc(tnum*sizeof(double*));
    double** __restrict array2 = (double**) malloc(tnum*sizeof(double*));
    double** __restrict array3 = (double**) malloc(tnum*sizeof(double*));
    double** __restrict array0 = (double**) malloc(tnum*sizeof(double*));
    double** __restrict array7 = (double**) malloc(tnum*sizeof(double*));
    double** __restrict array6 = (double**) malloc(tnum*sizeof(double*));
    double** __restrict array5 = (double**) malloc(tnum*sizeof(double*));
    double** __restrict array4 = (double**) malloc(tnum*sizeof(double*));
    double** __restrict array9 = (double**) malloc(tnum*sizeof(double*));
    double** __restrict array10 = (double**) malloc(tnum*sizeof(double*));
    double** __restrict array11 = (double**) malloc(tnum*sizeof(double*));

    #pragma omp parallel for schedule(auto) private(t1)
    for (t1 = 0; t1 < tnum; t1++) {
      array1[t1] = (double *) malloc(20736 * sizeof(double));
      array2[t1] = (double *) malloc(4 * sizeof(double));
      array3[t1] = (double *) malloc(19600 * sizeof(double));
      array0[t1] = (double *) malloc(19600 * sizeof(double));
      array7[t1] = (double *) malloc(18480 * sizeof(double));
      array6[t1] = (double *) malloc(18480 * sizeof(double));
      array5[t1] = (double *) malloc(18480 * sizeof(double));
      array4[t1] = (double *) malloc(18480 * sizeof(double));

      array9[t1] = (double *) malloc(1024 * sizeof(double));
      array10[t1] = (double *) malloc(1024 * sizeof(double));
      array11[t1] = (double *) malloc(1024 * sizeof(double));
    }

// consToPrim1+deconvolve+consToPrim2+waveSpeedBound1+absMax
#undef s0
#define s0(y,x) {\
W_bar(0,(y),(x)) = U(0,(y),(x));\
W_bar(1,(y),(x)) = U(1,(y),(x))/U(0,(y),(x));\
W_bar(2,(y),(x)) = U(2,(y),(x))/U(0,(y),(x));\
W_bar(3,(y),(x)) = (U(3,(y),(x))-0.500000*U(0,(y),(x))*(((U(1,(y),(x))/U(0,(y),(x)))*(U(1,(y),(x))/U(0,(y),(x))))+((U(2,(y),(x))/U(0,(y),(x)))*(U(2,(y),(x))/U(0,(y),(x))))))*(1.400000-1.000000);\
}
#undef s1
#define s1(c,y,x) u((c),(y),(x))=(1.166667*U((c),(y),(x)))+((-0.041667)*U((c),(y),(x)+1))+((-0.041667)*U((c),(y),(x)-1))+((-0.041667)*U((c),(y)+1,(x)))+((-0.041667)*U((c),(y)-1,(x)))
#undef s2
#define s2(y,x) {\
W(0,(y),(x)) = u(0,(y),(x));\
W(1,(y),(x)) = u(1,(y),(x))/u(0,(y),(x));\
W(2,(y),(x)) = u(2,(y),(x))/u(0,(y),(x));\
W(3,(y),(x)) = (u(3,(y),(x))-0.500000*u(0,(y),(x))*(((u(1,(y),(x))/u(0,(y),(x)))*(u(1,(y),(x))/u(0,(y),(x))))+((u(2,(y),(x))/u(0,(y),(x)))*(u(2,(y),(x))/u(0,(y),(x))))))*(1.400000-1.000000);\
}
#undef s3
#define s3(y,x) {\
umax((y),(x))=(2.000000*sqrt(1.400000*W(3,(y),(x))/W(0,(y),(x))))+W(1,(y),(x))+W(2,(y),(x));\
}
#undef s4
#define s4(y,x) absmax(retval,umax((y),(x)))

#pragma omp parallel for schedule(auto) collapse(2) private(t1,t2,t4,t6,t8,t10)
for(t2 = -1; t2 <= floord(N+3,8); t2++) {
  for(t4 = -1; t4 <= floord(N+3,8); t4++) {
    for(t6 = max(8*t2,-4); t6 <= min(N+3,8*t2+7); t6++) {
      #pragma omp simd
      for(t8 = max(-4,8*t4); t8 <= min(N+3,8*t4+7); t8++) {
        s0(t6,t8);
        if (N >= t6-2 && N >= t8-2) {
          if (t6 >= -3 && t8 >= -3) {
            for(t10 = 0; t10 <= C-1; t10++) {
              s1(t10,t6,t8);
            }
            s2(t6,t8);
          }
          if (N >= t6+1 && t2 >= 0 && t4 >= 0 && N >= t8+1) {
            s3(t6,t8);
            s4(t6,t8);
          }
        }
      }
    }
  }
}

for (t1 = 0; t1 < tnum; t1++) {
  absmax(retval__,retval_[t1]);
}

// laplacian+interpL_d1+interpH_d1+interpL_d2+interpH_d2
#undef s0
#define s0(c,y,x) W_ave((c),(y),(x))=(((-0.166667)*W_bar((c),(y),(x)))+(0.041667*W_bar((c),(y),(x)+1))+(0.041667*W_bar((c),(y),(x)-1))+(0.041667*W_bar((c),(y)+1,(x)))+(0.041667*W_bar((c),(y)-1,(x))))+W((c),(y),(x))
#undef s1
#define s1(c,y,x) W_aveL_d1((c),(y),(x))=(0.033333*W_ave((c),(y),(x)-3))+((-0.050000)*W_ave((c),(y),(x)+1))+((-0.216667)*W_ave((c),(y),(x)-2))+(0.450000*W_ave((c),(y),(x)))+(0.783333*W_ave((c),(y),(x)-1))
#undef s2
#define s2(c,y,x) W_aveH_d1((c),(y),(x))=((-0.050000)*W_ave((c),(y),(x)-2))+(0.033333*W_ave((c),(y),(x)+2))+(0.450000*W_ave((c),(y),(x)-1))+((-0.216667)*W_ave((c),(y),(x)+1))+(0.783333*W_ave((c),(y),(x)))
#undef s3
#define s3(c,y,x) W_aveL_d2((c),(y),(x))=(0.033333*W_ave((c),(y)-3,(x)))+((-0.050000)*W_ave((c),(y)+1,(x)))+((-0.216667)*W_ave((c),(y)-2,(x)))+(0.450000*W_ave((c),(y),(x)))+(0.783333*W_ave((c),(y)-1,(x)))
#undef s4
#define s4(c,y,x) W_aveH_d2((c),(y),(x))=((-0.050000)*W_ave((c),(y)-2,(x)))+(0.033333*W_ave((c),(y)+2,(x)))+(0.450000*W_ave((c),(y)-1,(x)))+((-0.216667)*W_ave((c),(y)+1,(x)))+(0.783333*W_ave((c),(y),(x)))

#pragma omp parallel for schedule(auto) collapse(2) private(t1,t2,t4,t6,t8,t10)
for(t2 = -1; t2 <= floord(N+2,8); t2++) {
  for(t4 = -1; t4 <= floord(N+2,8); t4++) {
    for(t6 = 0; t6 <= C-1; t6++) {
      for(t8 = max(8*t2,2*t2-1); t8 <= min(N+2,8*t2+7); t8++) {
        if (t8 <= 0) {
          #pragma omp simd
        for(t10 = max(5*t4,-3); t10 <= min(0,8*t4+7); t10++) {
            s0(t6,t8,t10);
          }
        }
        else {
          #pragma omp simd
        for(t10 = max(5*t4,-3); t10 <= min(0,8*t4+7); t10++) {
            s0(t6,t8,t10);
            s3(t6,t8-1,t10);
            s4(t6,t8-2,t10);
          }
        }
        if (t8 <= 0) {
          #pragma omp simd
        for(t10 = max(1,8*t4); t10 <= min(N+2,8*t4+7); t10++) {
            s0(t6,t8,t10);
            s1(t6,t8,t10-1);
            s2(t6,t8,t10-2);
          }
        }
        else {
          #pragma omp simd
        for(t10 = max(1,8*t4); t10 <= min(8*t4+7,N+2); t10++) {
            s0(t6,t8,t10);
            s1(t6,t8,t10-1);
            s2(t6,t8,t10-2);
            s3(t6,t8-1,t10);
            s4(t6,t8-2,t10);
          }
        }
      }
    }
  }
}

// upwindState1+getFlux1+deconvolve_f_d1+getFlux2+smul_d1+lap_f_d1+div_f_d1
#undef s0
#define s0(y,x) {\
W_ave_f_d1(0,(y),(x))=(0.000000 < ((W_aveL_d1(0+1,(y),(x))+W_aveH_d1(0+1,(y),(x))))*0.500000+((W_aveL_d1(3,(y),(x))-W_aveH_d1(3,(y),(x))))/((2.000000*(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000))/(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))))) ? (W_aveL_d1(0,(y),(x))) : (W_aveH_d1(0,(y),(x)));\
W_ave_f_d1(1,(y),(x))=(0.000000 < ((W_aveL_d1(0+1,(y),(x))+W_aveH_d1(0+1,(y),(x))))*0.500000+((W_aveL_d1(3,(y),(x))-W_aveH_d1(3,(y),(x))))/((2.000000*(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000))/(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))))) ? (W_aveL_d1(1,(y),(x))) : (W_aveH_d1(1,(y),(x)));\
W_ave_f_d1(2,(y),(x))=(0.000000 < ((W_aveL_d1(0+1,(y),(x))+W_aveH_d1(0+1,(y),(x))))*0.500000+((W_aveL_d1(3,(y),(x))-W_aveH_d1(3,(y),(x))))/((2.000000*(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000))/(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))))) ? (W_aveL_d1(2,(y),(x))) : (W_aveH_d1(2,(y),(x)));\
W_ave_f_d1(3,(y),(x))=(0.000000 < ((W_aveL_d1(0+1,(y),(x))+W_aveH_d1(0+1,(y),(x))))*0.500000+((W_aveL_d1(3,(y),(x))-W_aveH_d1(3,(y),(x))))/((2.000000*(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000))/(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))))) ? (W_aveL_d1(3,(y),(x))) : (W_aveH_d1(3,(y),(x)));\
W_ave_f_d1(0,(y),(x))+=(0.000000 < sqrt((1.400000*(((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000))/(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))+(-sgn(((W_aveL_d1(0+1,(y),(x))+W_aveH_d1(0+1,(y),(x))))*0.500000+((W_aveL_d1(3,(y),(x))-W_aveH_d1(3,(y),(x))))/((2.000000*(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000))/(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))))))*((W_aveL_d1(0+1,(y),(x))+W_aveH_d1(0+1,(y),(x))))*0.500000) ? (((((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000+((((((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000))/(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))))*(W_aveL_d1(0+1,(y),(x))-W_aveH_d1(0+1,(y),(x))))*0.500000-W_ave_f_d1(3,(y),(x))))/((sqrt((1.400000*(((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000))/(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000)))*sqrt((1.400000*(((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000))/(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000)))) : (0.000000);\
W_ave_f_d1(0+1,(y),(x))=(0.000000 < sqrt((1.400000*(((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000))/(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))+(-sgn(((W_aveL_d1(0+1,(y),(x))+W_aveH_d1(0+1,(y),(x))))*0.500000+((W_aveL_d1(3,(y),(x))-W_aveH_d1(3,(y),(x))))/((2.000000*(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000))/(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))))))*((W_aveL_d1(0+1,(y),(x))+W_aveH_d1(0+1,(y),(x))))*0.500000) ? (((W_aveL_d1(0+1,(y),(x))+W_aveH_d1(0+1,(y),(x))))*0.500000+((W_aveL_d1(3,(y),(x))-W_aveH_d1(3,(y),(x))))/((2.000000*(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000))/(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))))) : (W_ave_f_d1(0+1,(y),(x)));\
W_ave_f_d1(3,(y),(x))=(0.000000 < sqrt((1.400000*(((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000))/(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))+(-sgn(((W_aveL_d1(0+1,(y),(x))+W_aveH_d1(0+1,(y),(x))))*0.500000+((W_aveL_d1(3,(y),(x))-W_aveH_d1(3,(y),(x))))/((2.000000*(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000))/(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))))))*((W_aveL_d1(0+1,(y),(x))+W_aveH_d1(0+1,(y),(x))))*0.500000) ? (((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000+((((((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d1(3,(y),(x))+W_aveH_d1(3,(y),(x))))*0.500000))/(((W_aveL_d1(0,(y),(x))+W_aveH_d1(0,(y),(x))))*0.500000))))*(W_aveL_d1(0+1,(y),(x))-W_aveH_d1(0+1,(y),(x))))*0.500000) : (W_ave_f_d1(3,(y),(x)));\
}
#undef s1
#define s1(y,x) {\
F_bar_f_d1(0,(y),(x))=(W_ave_f_d1(0+1,(y),(x)))*W_ave_f_d1(0,(y),(x));\
F_bar_f_d1(1,(y),(x))=W_ave_f_d1(1,(y),(x))*F_bar_f_d1(0,(y),(x));\
F_bar_f_d1(2,(y),(x))=W_ave_f_d1(2,(y),(x))*F_bar_f_d1(0,(y),(x));\
F_bar_f_d1(0+1,(y),(x))+=W_ave_f_d1(3,(y),(x));\
F_bar_f_d1(3,(y),(x))=((1.400000/(1.400000-1))*W_ave_f_d1(0+1,(y),(x)))*W_ave_f_d1(3,(y),(x))+0.500000*F_bar_f_d1(0,(y),(x))*((W_ave_f_d1(1,(y),(x))*W_ave_f_d1(1,(y),(x)))+(W_ave_f_d1(2,(y),(x))*W_ave_f_d1(2,(y),(x))));\
}
#undef s2
#define s2(c,y,x) W_f_d1((c),(y),(x))=(1.083333*W_ave_f_d1((c),(y),(x)))+((-0.041667)*W_ave_f_d1((c),(y)+1,(x)))+((-0.041667)*W_ave_f_d1((c),(y)-1,(x)))
#undef s3
#define s3(y,x) {\
F_ave_f_d1(0,(y),(x))=(W_f_d1(0+1,(y),(x)))*W_f_d1(0,(y),(x));\
F_ave_f_d1(1,(y),(x))=W_f_d1(1,(y),(x))*F_ave_f_d1(0,(y),(x));\
F_ave_f_d1(2,(y),(x))=W_f_d1(2,(y),(x))*F_ave_f_d1(0,(y),(x));\
F_ave_f_d1(0+1,(y),(x))+=W_f_d1(3,(y),(x));\
F_ave_f_d1(3,(y),(x))=((1.400000/(1.400000-1))*W_f_d1(0+1,(y),(x)))*W_f_d1(3,(y),(x))+0.500000*F_ave_f_d1(0,(y),(x))*((W_f_d1(1,(y),(x))*W_f_d1(1,(y),(x)))+(W_f_d1(2,(y),(x))*W_f_d1(2,(y),(x))));\
}
#undef s4
#define s4(c,y,x) F_bar_f_d1((c),(y),(x))*=0.041667
#undef s5
#define s5(c,y,x) F_ave_f_d1((c),(y),(x))+=((-0.083333)*F_bar_f_d1((c),(y),(x)))+(0.041667*F_bar_f_d1((c),(y)+1,(x)))+(0.041667*F_bar_f_d1((c),(y)-1,(x)))
#undef s6
#define s6(c,y,x) rhs((c),(y),(x))+=((-1.000000)*F_ave_f_d1((c),(y),(x)))+(1.000000*F_ave_f_d1((c),(y),(x)+1))

#pragma omp parallel for schedule(auto) collapse(2) private(t1,t2,t4,t6,t8,t10)
for(t2 = -1; t2 <= floord(N+3,8); t2++) {
  for(t4 = 0; t4 <= floord(N,8); t4++) {
    for(t6 = max(2*t2-1,8*t2); t6 <= min(8*t2+7,N+3); t6++) {
      #pragma omp simd
      for(t8 = 8*t4; t8 <= min(N,8*t4+7); t8++) {
        if (N >= t6-2) {
          s0(t6,t8);
          s1(t6,t8);
        }
        if (t6 <= -2) {
          for(t10 = 0; t10 <= C-1; t10++) {
            s4(t10,t6,t8);
          }
        }
        else {
          if (N >= t6-2) {
            for(t10 = 0; t10 <= C-1; t10++) {
              s2(t10,t6-1,t8);
              s4(t10,t6,t8);
            }
          }
        }
        if (N >= t6-2 && t6 >= -1) {
          s3(t6-1,t8);
        }
        if (t2 >= 0) {
          if (t8 <= 0) {
            for(t10 = 0; t10 <= C-1; t10++) {
              s5(t10,t6-2,t8);
            }
          }
          else {
            if (t2 <= 0 && t6 <= 1) {
              for(t10 = 0; t10 <= C-1; t10++) {
                s5(t10,t6-2,t8);
              }
            }
          }
        }
        if (t8 >= 1) {
          if (N >= t6-1) {
            if (t6 >= 2) {
              for(t10 = 0; t10 <= C-1; t10++) {
                s5(t10,t6-2,t8);
                s6(t10,t6-2,t8-1);
              }
            }
          }
          else {
            for(t10 = 0; t10 <= C-1; t10++) {
              s5(t10,t6-2,t8);
            }
          }
        }
      }
    }
  }
}

// upwindState2+getFlux3+deconvolve_f_d2+getFlux4+smul_d2+lap_f_d2+div_f_d2+muldx
#undef s0
#define s0(y,x) {\
W_ave_f_d2(0,(y),(x))=(0.000000 < ((W_aveL_d2(1+1,(y),(x))+W_aveH_d2(1+1,(y),(x))))*0.500000+((W_aveL_d2(3,(y),(x))-W_aveH_d2(3,(y),(x))))/((2.000000*(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000))/(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))))) ? (W_aveL_d2(0,(y),(x))) : (W_aveH_d2(0,(y),(x)));\
W_ave_f_d2(1,(y),(x))=(0.000000 < ((W_aveL_d2(1+1,(y),(x))+W_aveH_d2(1+1,(y),(x))))*0.500000+((W_aveL_d2(3,(y),(x))-W_aveH_d2(3,(y),(x))))/((2.000000*(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000))/(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))))) ? (W_aveL_d2(1,(y),(x))) : (W_aveH_d2(1,(y),(x)));\
W_ave_f_d2(2,(y),(x))=(0.000000 < ((W_aveL_d2(1+1,(y),(x))+W_aveH_d2(1+1,(y),(x))))*0.500000+((W_aveL_d2(3,(y),(x))-W_aveH_d2(3,(y),(x))))/((2.000000*(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000))/(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))))) ? (W_aveL_d2(2,(y),(x))) : (W_aveH_d2(2,(y),(x)));\
W_ave_f_d2(3,(y),(x))=(0.000000 < ((W_aveL_d2(1+1,(y),(x))+W_aveH_d2(1+1,(y),(x))))*0.500000+((W_aveL_d2(3,(y),(x))-W_aveH_d2(3,(y),(x))))/((2.000000*(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000))/(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))))) ? (W_aveL_d2(3,(y),(x))) : (W_aveH_d2(3,(y),(x)));\
W_ave_f_d2(0,(y),(x))+=(0.000000 < sqrt((1.400000*(((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000))/(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))+(-sgn(((W_aveL_d2(1+1,(y),(x))+W_aveH_d2(1+1,(y),(x))))*0.500000+((W_aveL_d2(3,(y),(x))-W_aveH_d2(3,(y),(x))))/((2.000000*(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000))/(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))))))*((W_aveL_d2(1+1,(y),(x))+W_aveH_d2(1+1,(y),(x))))*0.500000) ? (((((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000+((((((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000))/(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))))*(W_aveL_d2(1+1,(y),(x))-W_aveH_d2(1+1,(y),(x))))*0.500000-W_ave_f_d2(3,(y),(x))))/((sqrt((1.400000*(((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000))/(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000)))*sqrt((1.400000*(((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000))/(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000)))) : (0.000000);\
W_ave_f_d2(1+1,(y),(x))=(0.000000 < sqrt((1.400000*(((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000))/(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))+(-sgn(((W_aveL_d2(1+1,(y),(x))+W_aveH_d2(1+1,(y),(x))))*0.500000+((W_aveL_d2(3,(y),(x))-W_aveH_d2(3,(y),(x))))/((2.000000*(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000))/(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))))))*((W_aveL_d2(1+1,(y),(x))+W_aveH_d2(1+1,(y),(x))))*0.500000) ? (((W_aveL_d2(1+1,(y),(x))+W_aveH_d2(1+1,(y),(x))))*0.500000+((W_aveL_d2(3,(y),(x))-W_aveH_d2(3,(y),(x))))/((2.000000*(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000))/(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))))) : (W_ave_f_d2(1+1,(y),(x)));\
W_ave_f_d2(3,(y),(x))=(0.000000 < sqrt((1.400000*(((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000))/(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))+(-sgn(((W_aveL_d2(1+1,(y),(x))+W_aveH_d2(1+1,(y),(x))))*0.500000+((W_aveL_d2(3,(y),(x))-W_aveH_d2(3,(y),(x))))/((2.000000*(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000))/(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))))))*((W_aveL_d2(1+1,(y),(x))+W_aveH_d2(1+1,(y),(x))))*0.500000) ? (((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000+((((((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))*(sqrt((1.400000*(((W_aveL_d2(3,(y),(x))+W_aveH_d2(3,(y),(x))))*0.500000))/(((W_aveL_d2(0,(y),(x))+W_aveH_d2(0,(y),(x))))*0.500000))))*(W_aveL_d2(1+1,(y),(x))-W_aveH_d2(1+1,(y),(x))))*0.500000) : (W_ave_f_d2(3,(y),(x)));\
}
#undef s1
#define s1(y,x) {\
F_bar_f_d2(0,(y),(x))=(W_ave_f_d2(1+1,(y),(x)))*W_ave_f_d2(0,(y),(x));\
F_bar_f_d2(1,(y),(x))=W_ave_f_d2(1,(y),(x))*F_bar_f_d2(0,(y),(x));\
F_bar_f_d2(2,(y),(x))=W_ave_f_d2(2,(y),(x))*F_bar_f_d2(0,(y),(x));\
F_bar_f_d2(1+1,(y),(x))+=W_ave_f_d2(3,(y),(x));\
F_bar_f_d2(3,(y),(x))=((1.400000/(1.400000-1))*W_ave_f_d2(1+1,(y),(x)))*W_ave_f_d2(3,(y),(x))+0.500000*F_bar_f_d2(0,(y),(x))*((W_ave_f_d2(1,(y),(x))*W_ave_f_d2(1,(y),(x)))+(W_ave_f_d2(2,(y),(x))*W_ave_f_d2(2,(y),(x))));\
}
#undef s2
#define s2(c,y,x) W_f_d2((c),(y),(x))=(1.083333*W_ave_f_d2((c),(y),(x)))+((-0.041667)*W_ave_f_d2((c),(y),(x)+1))+((-0.041667)*W_ave_f_d2((c),(y),(x)-1))
#undef s3
#define s3(y,x) {\
F_ave_f_d2(0,(y),(x))=(W_f_d2(1+1,(y),(x)))*W_f_d2(0,(y),(x));\
F_ave_f_d2(1,(y),(x))=W_f_d2(1,(y),(x))*F_ave_f_d2(0,(y),(x));\
F_ave_f_d2(2,(y),(x))=W_f_d2(2,(y),(x))*F_ave_f_d2(0,(y),(x));\
F_ave_f_d2(1+1,(y),(x))+=W_f_d2(3,(y),(x));\
F_ave_f_d2(3,(y),(x))=((1.400000/(1.400000-1))*W_f_d2(1+1,(y),(x)))*W_f_d2(3,(y),(x))+0.500000*F_ave_f_d2(0,(y),(x))*((W_f_d2(1,(y),(x))*W_f_d2(1,(y),(x)))+(W_f_d2(2,(y),(x))*W_f_d2(2,(y),(x))));\
}
#undef s4
#define s4(c,y,x) F_bar_f_d2((c),(y),(x))*=0.041667
#undef s5
#define s5(c,y,x) F_ave_f_d2((c),(y),(x))+=((-0.083333)*F_bar_f_d2((c),(y),(x)))+(0.041667*F_bar_f_d2((c),(y),(x)+1))+(0.041667*F_bar_f_d2((c),(y),(x)-1))
#undef s6
#define s6(c,y,x) rhs((c),(y),(x))+=((-1.000000)*F_ave_f_d2((c),(y),(x)))+(1.000000*F_ave_f_d2((c),(y)+1,(x)))
#undef s7
#define s7(c,y,x) rhs((c),(y),(x))*=-1.000000

#pragma omp parallel for schedule(auto) collapse(2) private(t1,t2,t4,t6,t8,t10)
for(t2 = 0; t2 <= floord(N,8); t2++) {
  for(t4 = -1; t4 <= floord(N+3,8); t4++) {
    for(t6 = 8*t2; t6 <= min(N,8*t2+7); t6++) {
      #pragma omp simd
      for(t8 = max(2*t4-1,8*t4); t8 <= min(N+3,8*t4+7); t8++) {
        if (N >= t8-2) {
          s0(t6,t8);
          s1(t6,t8);
        }
        if (t8 <= -2) {
          for(t10 = 0; t10 <= C-1; t10++) {
            s4(t10,t6,t8);
          }
        }
        else {
          if (N >= t8-2) {
            for(t10 = 0; t10 <= C-1; t10++) {
              s2(t10,t6,t8-1);
              s4(t10,t6,t8);
            }
          }
        }
        if (N >= t8-2 && t8 >= -1) {
          s3(t6,t8-1);
        }
        if (t8 <= 1) {
          if (t4 == 0) {
            for(t10 = 0; t10 <= C-1; t10++) {
              s5(t10,t6,t8-2);
            }
          }
        }
        else {
          if (N >= t8-1) {
            if (t6 <= 0) {
              for(t10 = 0; t10 <= C-1; t10++) {
                s5(t10,t6,t8-2);
              }
            }
            else {
              for(t10 = 0; t10 <= C-1; t10++) {
                s5(t10,t6,t8-2);
                s6(t10,t6-1,t8-2);
                s7(t10,t6-1,t8-2);
              }
            }
          }
        }
        if (t8 >= N+2) {
          for(t10 = 0; t10 <= C-1; t10++) {
            s5(t10,t6,t8-2);
          }
        }
      }
    }
  }
}

    #pragma omp parallel for schedule(auto) private(t1)
    for (t1 = 0; t1 < tnum; t1++) {
      free(array1[t1]);
      free(array2[t1]);
      free(array3[t1]);
      free(array0[t1]);
      free(array7[t1]);
      free(array6[t1]);
      free(array5[t1]);
      free(array4[t1]);
      free(array9[t1]);
      free(array10[t1]);
      free(array11[t1]);
    }

    free(array1);
    free(array2);
    free(array3);
    free(array0);
    free(array7);
    free(array6);
    free(array5);
    free(array4);
    free(scalar8);
    free(array9);
    free(array10);
    free(array11);

    return (retval__);
}    // euler_step

#undef min
#undef max
#undef abs
#undef absmin
#undef absmax
#undef floord
#undef sgn
#undef offset2
#undef offset3
#undef offset4
#undef arrinit
#undef arrprnt
#undef C
#undef D
#undef G
#undef N
#undef T
#undef U
#undef W_bar
#undef u
#undef W
#undef umax
#undef W_ave
#undef W_aveL_d1
#undef W_aveH_d1
#undef W_aveL_d2
#undef W_aveH_d2
#undef W_ave_f_d1
#undef F_bar_f_d1
#undef W_f_d1
#undef F_ave_f_d1
#undef rhs
#undef W_ave_f_d2
#undef F_bar_f_d2
#undef W_f_d2
#undef F_ave_f_d2

