/**
 * doitgen.c: This file is part of the PolyBench/C 3.2 test suite.
 *
 *
 * Contact: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 * Web address: http://polybench.sourceforge.net
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

  static
void init_array(int nr, int nq, int np,
    double A[nr][nq][np],
    double C4[np][np])
{
  int i, j, k;

  for (i = 0; i < nr; i++)
    for (j = 0; j < nq; j++)
      for (k = 0; k < np; k++)
        A[i][j][k] = ((double) i*j + k) / np;
  for (i = 0; i < np; i++)
    for (j = 0; j < np; j++)
      C4[i][j] = ((double) i*j) / np;
}




  static
void print_array(int nr, int nq, int np,
    double A[nr][nq][np])
{
  int i, j, k;

  for (i = 0; i < nr; i++)
    for (j = 0; j < nq; j++)
      for (k = 0; k < np; k++) {
        fprintf (stderr, "%0.2lf ", A[i][j][k]);
        if (i % 20 == 0) fprintf (stderr, "\n");
      }
  fprintf (stderr, "\n");
}




  static
void kernel_doitgen(int nr, int nq, int np,
    double A[nr][nq][np],
    double C4[np][np],
    double sum[nr][nq][np])
{
  int r, q, p, s;

#pragma scop
  for (r = 0; r < nr; r++)
    for (q = 0; q < nq; q++) {
      for (p = 0; p < np; p++) {
        sum[r][q][p] = 0;
        for (s = 0; s < np; s++)
          sum[r][q][p] = sum[r][q][p] + A[r][q][s] * C4[s][p];
      }
      for (p = 0; p < np; p++)
        A[r][q][p] = sum[r][q][p];
    }
#pragma endscop

}


int main(int argc, char** argv)
{

  int dump_code = atoi(argv[1]);
  int nr = atoi(argv[2]);
  int nq = atoi(argv[3]);
  int np = atoi(argv[4]);

  double (*A)[nr][nq][np]; A = (double(*)[nr][nq][np])malloc((nr) * (nq) * (np) * sizeof(double));;
  double (*sum)[nr][nq][np]; sum = (double(*)[nr][nq][np])malloc((nr) * (nq) * (np) * sizeof(double));;
  double (*C4)[np][np]; C4 = (double(*)[np][np])malloc((np) * (np) * sizeof(double));;


  init_array (nr, nq, np,
      *A,
      *C4);




  kernel_doitgen (nr, nq, np,
      *A,
      *C4,
      *sum);





  if (dump_code == 1) print_array(nr, nq, np, *A);


  free((void*)A);;
  free((void*)sum);;
  free((void*)C4);;

  return 0;
}
