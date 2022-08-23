/**
 * This version is stamped on May 10, 2016
 *
 * Contact:
 *   Louis-Noel Pouchet <pouchet.ohio-state.edu>
 *   Tomofumi Yuki <tomofumi.yuki.fr>
 *
 * Web address: http://polybench.sourceforge.net
 */
/* symm.c: this file is part of PolyBench/C */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>


/* Array initialization. */
static
void init_array(int m, int n,
		double *alpha,
		double *beta,
		double C[m][n],
		double A[m][m],
		double B[m][n])
{
  int i, j;

  *alpha = 1.5;
  *beta = 1.2;
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++) {
      C[i][j] = (double) ((i+j) % 100) / m;
      B[i][j] = (double) ((n+i-j) % 100) / m;
    }
  for (i = 0; i < m; i++) {
    for (j = 0; j <=i; j++)
      A[i][j] = (double) ((i+j) % 100) / m;
    for (j = i+1; j < m; j++)
      A[i][j] = -999; 
  }
}


/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */
static
void print_array(int m, int n,
		 double C[m][n])
{
  int i, j;

  
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++) {
	if ((i * m + j) % 20 == 0) fprintf (stderr, "\n");
	fprintf (stderr, "%0.2lf ", C[i][j]);
    }
}


/* Main computational kernel. The whole function will be timed,
   including the call and return. */
static
void kernel_symm(int m, int n,
		 double alpha,
		 double beta,
		 double C[m][n],
		 double A[m][m],
		 double B[m][n])
{
  int i, j, k;
  double temp2;

//BLAS PARAMS
//SIDE = 'L'
//UPLO = 'L'
// =>  Form  C := alpha*A*B + beta*C
// A is MxM
// B is MxN
// C is MxN
//note that due to Fortran array layout, the code below more closely resembles upper triangular case in BLAS
#pragma scop
   for (i = 0; i < m; i++)
      for (j = 0; j < n; j++ )
      {
        temp2 = 0;
        for (k = 0; k < i; k++) {
           C[k][j] += alpha*B[i][j] * A[i][k];
           temp2 += B[k][j] * A[i][k];
        }
        C[i][j] = beta * C[i][j] + alpha*B[i][j] * A[i][i] + alpha * temp2;
     }
#pragma endscop

}


int main(int argc, char** argv)
{
  int dump_code = atoi(argv[1]);
  int m = atoi(argv[2]);
  int n = atoi(argv[3]);
  

  double alpha;
  double beta;
  double (*C)[n][n]; C = (double(*)[m][n])malloc((m) * (n) * sizeof(double));
  double (*A)[m][m]; A = (double(*)[m][m])malloc((m) * (m) * sizeof(double));
  double (*B)[m][n]; B = (double(*)[m][n])malloc((m) * (n) * sizeof(double));
  

  /* Initialize array(s). */
  init_array (m, n, &alpha, &beta,
	      *C,
	      *A,
	      *B);

  /* Run kernel. */
  kernel_symm (m, n,
	       alpha, beta,
	       *C,
	       *A,
	       *B);


  if (dump_code == 1) print_array(m, n, *C);


  /* Be clean. */
  free((void*)C);
  free((void*)A);
  free((void*)B);

  return 0;
}
