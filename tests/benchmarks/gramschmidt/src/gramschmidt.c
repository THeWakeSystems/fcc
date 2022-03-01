/**
 * This version is stamped on May 10, 2016
 *
 * Contact:
 *   Louis-Noel Pouchet <pouchet.ohio-state.edu>
 *   Tomofumi Yuki <tomofumi.yuki.fr>
 *
 * Web address: http://polybench.sourceforge.net
 */
/* gramschmidt.c: this file is part of PolyBench/C */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>



static
void init_array(int m, int n,
		double A[m][n],
		double R[n][n],
		double Q[m][n])
{
  int i, j;

  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++) {
      A[i][j] = (((double) ((i*j) % m) / m )*100) + 10;
      Q[i][j] = 0.0;
    }
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      R[i][j] = 0.0;
}


static
void print_array(int m, int n,
		 double A[m][n],
		 double R[n][n],
		 double Q[m][n])
{
  int i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
	if ((i*n+j) % 20 == 0) fprintf (stderr, "\n");
	fprintf (stderr, "%0.2lf ", R[i][j]);
    }
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++) {
	if ((i*n+j) % 20 == 0) fprintf (stderr, "\n");
	fprintf (stderr, "%0.2lf ", Q[i][j]);
    }
}



static
void kernel_gramschmidt(int m, int n,
			double A[m][n],
			double R[n][n],
			double Q[m][n])
{
  int i, j, k;

  double nrm;

#pragma scop
  for (k = 0; k < n; k++)
    {
      nrm = 0.0;
      for (i = 0; i < m; i++)
        nrm += A[i][k] * A[i][k];
      R[k][k] = sqrt(nrm);
      for (i = 0; i < m; i++)
        Q[i][k] = A[i][k] / R[k][k];
      for (j = k + 1; j < n; j++)
	{
	  R[k][j] = 0.0;
	  for (i = 0; i < m; i++)
	    R[k][j] += Q[i][k] * A[i][j];
	  for (i = 0; i < m; i++)
	    A[i][j] = A[i][j] - Q[i][k] * R[k][j];
	}
    }
#pragma endscop

}


int main(int argc, char** argv)
{
  int dump_code = atoi(argv[1]);
  int m = atoi(argv[2]);
  int n = atoi(argv[3]);
  
  double (*A)[m][n]; A = (double(*)[m][n])malloc((m) * (n) * sizeof(double));
  double (*R)[n][n]; R = (double(*)[n][n])malloc((n) * (n) * sizeof(double));
  double (*Q)[m][n]; Q = (double(*)[m][n])malloc((m) * (n) * sizeof(double));
  
  init_array (m, n,
	      *A,
	      *R,
	      *Q);

  
  kernel_gramschmidt (m, n,
		      *A,
		      *R,
		      *Q);

 
  if (dump_code == 1) print_array(m, n, *A, *R, *Q);

  /* Be clean. */
  free((void*)A);
  free((void*)R);
  free((void*)Q);

  return 0;
}
