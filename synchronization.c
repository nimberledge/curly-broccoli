#include<stdio.h>
#include"omp.h"


static long num_steps = 100000000;
double step;
int main()
{
  double pi = 0.0;
  step = 1.0 / (double) num_steps;
  double timeTaken = omp_get_wtime();
  #pragma omp parallel
  {
  int threadID = omp_get_thread_num();
  int nThreads = omp_get_num_threads();
  double x, sum = 0.0;
  for (int i=threadID;i<num_steps;i=i+nThreads)
  {
    x = (i+0.5) * step;
    sum = sum + 4.0 / (1.0 + x*x);
  }
  sum = sum * step;
  #pragma omp atomic
    pi += sum;
  }
  timeTaken = omp_get_wtime() - timeTaken;
  printf("%f\n%f\n", pi, timeTaken);
}
