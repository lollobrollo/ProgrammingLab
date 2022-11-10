#include <stdio.h>
#include <math.h>

double som(int n)
{
  double som = 0;
  for(int i = 0; i <= n; i++)
    {
      if(i == 0)
        som += 1;
      else
      {
        som += (1 / pow((2 * i + 1), (2)));
      }
    }
  return som;
}

int main()
{
  int n;

  printf("inserire n: \n");
  scanf("%d", &n);

  double somma = som(n);

  printf("la sommatoria in questione con n = %d vale: %lf\n", n, somma);

  //dimostro che la serie tende a pi^2/8
  printf("La serie tende a (π^2)/8:\n");
  for(int i =1; i <= 65536; i *= 2)
    {
      double res = som(i);
      printf("%lf <= 1,2337\n", res);
    }
}