/**
 * covariance.c: This file is part of the PolyBench/C 3.2 test suite.
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
void init_array (int m, int n,
   double *float_n,
   double data[m][n])
{
  int i, j;

  *float_n = 1.2;

  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      data[i][j] = ((double) i*j) / 1000;
}




static
void print_array(int m,
   double symmat[m][m])

{
  int i, j;

  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      fprintf (stderr, "%0.2lf ", symmat[i][j]);
      if ((i * m + j) % 20 == 0) fprintf (stderr, "\n");
    }
  fprintf (stderr, "\n");
}




static
void kernel_covariance(int m, int n,
         double float_n,
         double data[m][n],
         double symmat[m][m],
         double mean[m])
{
  int i, j, j1, j2;

#pragma scop

  for (j = 0; j < m; j++)
    {
      mean[j] = 0.0;
      for (i = 0; i < n; i++)
        mean[j] += data[i][j];
      mean[j] /= float_n;
    }


  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      data[i][j] -= mean[j];


  for (j1 = 0; j1 < m; j1++)
    for (j2 = j1; j2 < m; j2++)
      {
        symmat[j1][j2] = 0.0;
        for (i = 0; i < n; i++)
   symmat[j1][j2] += data[i][j1] * data[i][j2];
        symmat[j2][j1] = symmat[j1][j2];
      }
#pragma endscop

}


int main(int argc, char** argv)
{

  int dump_code = atoi(argv[1]);
  int n = atoi(argv[2]);
  int m = atoi(argv[3]);

  double float_n;
  double (*data)[m][n]; data = (double(*)[m][n])malloc((m) * (n) * sizeof(double));;
  double (*symmat)[m][m]; symmat = (double(*)[m][m])malloc((m) * (m) * sizeof(double));;
  double (*mean)[m]; mean = (double(*)[m])malloc((m) * sizeof(double));;



  init_array (m, n, &float_n, *data);




  kernel_covariance (m, n, float_n,
       *data,
       *symmat,
       *mean);





  if (dump_code == 1) print_array(m, *symmat);


  free((void*)data);;
  free((void*)symmat);;
  free((void*)mean);;

  return 0;
}
