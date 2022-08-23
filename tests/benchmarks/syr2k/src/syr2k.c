/**
 * This version is stamped on May 10, 2016
 *
 * Contact:
 *   Louis-Noel Pouchet <pouchet.ohio-state.edu>
 *   Tomofumi Yuki <tomofumi.yuki.fr>
 *
 * Web address: http://polybench.sourceforge.net
 */
/* syr2k.c: this file is part of PolyBench/C */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>



/* Array initialization. */
static
void init_array(int n, int m,
		double *alpha,
		double *beta,
		double C[n][n],
		double A[n][m],
		double B[n][m])
{
  int i, j;

  *alpha = 1.5;
  *beta = 1.2;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      A[i][j] = (double) ((i*j+1)%n) / n;
      B[i][j] = (double) ((i*j+2)%m) / m;
    }
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      C[i][j] = (double) ((i*j+3)%n) / m;
    }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int n,
		 double C[n][n])
{
  int i, j;

 
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
	if ((i * n + j) % 20 == 0) fprintf (stderr, "\n");
	fprintf (stderr, "%0.2lf ", C[i][j]);
    }
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_syr2k(int n, int m,
		  double alpha,
		  double beta,
		  double C[n][n],
		  double A[n][m],
		  double B[n][m])
{
  int i, j, k;

//BLAS PARAMS
//UPLO  = 'L'
//TRANS = 'N'
//A is NxM
//B is NxM
//C is NxN
#pragma scop
  for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++)
      C[i][j] *= beta;
    for (k = 0; k < m; k++)
      for (j = 0; j <= i; j++)
	{
	  C[i][j] += A[j][k]*alpha*B[i][k] + B[j][k]*alpha*A[i][k];
	}
  }
#pragma endscop

}


int main(int argc, char** argv)
{
  int dump_code = atoi(argv[1]);
  int n = atoi(argv[2]);
  int m = atoi(argv[3]);


  double alpha;
  double beta;
  double (*C)[n][n]; C = (double(*)[n][n])malloc((n) * (n) * sizeof(double));
  double (*A)[n][m]; A = (double(*)[n][m])malloc((n) * (m) * sizeof(double));
  double (*B)[n][m]; B = (double(*)[n][m])malloc((n) * (m) * sizeof(double));
  
  /* Initialize array(s). */
  init_array (n, m, &alpha, &beta,
	     *C,
	     *A,
	     *B);


  /* Run kernel. */
  kernel_syr2k (n, m,
		alpha, beta,
		*C,
		*A,
		*B);


  if (dump_code == 1) print_array(n, *C);

  /* Be clean. */
  free((void*)C);
  free((void*)A);
  free((void*)B);

  return 0;
}
