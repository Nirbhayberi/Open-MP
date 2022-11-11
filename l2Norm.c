#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <vectOps.h>
#include <vectHandling.h>

void l2NormErr(double *vect1, double *vect2, long n)
{
    double t_start,t_end;
    double l2n; // L2 norm error 
     t_start=omp_get_wtime();
    Daxpy(vect1, vect2, -1, n, "Daxpy.txt");
    l2n = dotProduct(vect1, vect1, n);
    l2n = sqrt(l2n);
       t_end=omp_get_wtime();
    // printf("L2 Norm of the error vector: %lf\n", l2n);
    printf("L2 opeartion done in = %f seconds\n", t_end - t_start);
    print1dvect(&l2n, 1, "l2error.txt");

    return;
}
