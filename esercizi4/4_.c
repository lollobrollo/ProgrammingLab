//11.4 ricorsiva

#include <stdio.h>
#include <math.h>

double P(double n)
{
  return n * n;
}

double s_n(double n)
{
  if(n == 0) return 1;
  return (1 / P(2 * n + 1) + s_n(n-1));
}

int main()
{
  double n;

  printf("inserire n: \n");
  scanf("%lf", &n);

  double somma = s_n(n);

  printf("la sommatoria in questione con n = %lf vale: %lf\n", n, somma);

}
