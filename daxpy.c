#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <vectHandling.h>

/**
 * @brief For scalar alpha and vectors y and x, this 
 *        sub-routine performs the following operation -
 *        y = y + (alpha*x) 
 *        and prints y to an output file
 * @param vect1 Pointer to first vector (y) 
 * @param vect2 Pointer to second vector (x)
 * @param alpha Scalar multiplier
 * @param vect_len Length of vectors
 * @param filename Name of output file
 */
void Daxpy(double *vect1, double *vect2, double alpha, long vect_len, char *filename)
{   double t_start,t_end;
    int i;
    t_start=omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < vect_len; i++)
        vect1[i] = vect1[i] + alpha * vect2[i];
    t_end=omp_get_wtime();
    
    printf("Daxy operation done in = %f seconds \n", t_end - t_start);
    print1dvect(vect1, vect_len, filename);
    return;
}
