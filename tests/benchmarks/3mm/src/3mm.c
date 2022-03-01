/**
 * 3mm.c: This file is part of the PolyBench/C 3.2 test suite.
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
void init_array(int ni, int nj, int nk, int nl, int nm,
    double A[ni][nk],
    double B[nk][nj],
    double C[nj][nm],
    double D[nm][nl])
{
  int i, j;

  for (i = 0; i < ni; i++)
    for (j = 0; j < nk; j++)
      A[i][j] = ((double) i*j) / ni;
  for (i = 0; i < nk; i++)
    for (j = 0; j < nj; j++)
      B[i][j] = ((double) i*(j+1)) / nj;
  for (i = 0; i < nj; i++)
    for (j = 0; j < nm; j++)
      C[i][j] = ((double) i*(j+3)) / nl;
  for (i = 0; i < nm; i++)
    for (j = 0; j < nl; j++)
      D[i][j] = ((double) i*(j+2)) / nk;
}




  static
void print_array(int ni, int nl,
    double G[ni][nl])
{
  int i, j;

  for (i = 0; i < ni; i++)
    for (j = 0; j < nl; j++) {
      fprintf (stderr, "%0.2lf ", G[i][j]);
      if ((i * ni + j) % 20 == 0) fprintf (stderr, "\n");
    }
  fprintf (stderr, "\n");
}




  static
void kernel_3mm(int ni, int nj, int nk, int nl, int nm,
    double E[ni][nj],
    double A[ni][nk],
    double B[nk][nj],
    double F[nj][nl],
    double C[nj][nm],
    double D[nm][nl],
    double G[ni][nl])
{
  int i, j, k;

#pragma scop

  for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++)
    {
      E[i][j] = 0;
      for (k = 0; k < nk; ++k)
        E[i][j] += A[i][k] * B[k][j];
    }

  for (i = 0; i < nj; i++)
    for (j = 0; j < nl; j++)
    {
      F[i][j] = 0;
      for (k = 0; k < nm; ++k)
        F[i][j] += C[i][k] * D[k][j];
    }

  for (i = 0; i < ni; i++)
    for (j = 0; j < nl; j++)
    {
      G[i][j] = 0;
      for (k = 0; k < nj; ++k)
        G[i][j] += E[i][k] * F[k][j];
    }
#pragma endscop

}


int main(int argc, char** argv)
{

  int dump_code = atoi(argv[1]);
  int ni = atoi(argv[2]);
  int nj = atoi(argv[3]);
  int nk = atoi(argv[4]);
  int nl = atoi(argv[5]);
  int nm = atoi(argv[6]);


  double (*E)[ni][nj]; E = (double(*)[ni][nj])malloc((ni) * (nj) * sizeof(double));;
  double (*A)[ni][nk]; A = (double(*)[ni][nk])malloc((ni) * (nk) * sizeof(double));;
  double (*B)[nk][nj]; B = (double(*)[nk][nj])malloc((nk) * (nj) * sizeof(double));;
  double (*F)[nj][nl]; F = (double(*)[nj][nl])malloc((nj) * (nl) * sizeof(double));;
  double (*C)[nj][nm]; C = (double(*)[nj][nm])malloc((nj) * (nm) * sizeof(double));;
  double (*D)[nm][nl]; D = (double(*)[nm][nl])malloc((nm) * (nl) * sizeof(double));;
  double (*G)[ni][nl]; G = (double(*)[ni][nl])malloc((ni) * (nl) * sizeof(double));;


  init_array (ni, nj, nk, nl, nm,
      *A,
      *B,
      *C,
      *D);




  kernel_3mm (ni, nj, nk, nl, nm,
      *E,
      *A,
      *B,
      *F,
      *C,
      *D,
      *G);





  if (dump_code == 1) print_array(ni, nl, *G);


  free((void*)E);;
  free((void*)A);;
  free((void*)B);;
  free((void*)F);;
  free((void*)C);;
  free((void*)D);;
  free((void*)G);;

  return 0;
}
