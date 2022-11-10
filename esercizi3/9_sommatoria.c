#include <stdio.h>
#include <math.h>

double som(int n, double k)
{
  double som = 0;
  for(int i = 0; i <= n; i++)
    {
      if(i == 0)
        som += 0;
      else
      {
        som += ((i * pow(k, (i + 1))) / pow(3, i));
      }
    }
  return som;
}

int main()
{
  int n;
  double k;
  
  printf("inserire n: \n");
  scanf("%d", &n);
  printf("inserire k: \n");
  scanf("%lf", &k);

  double somma = som(n, k);

  printf("la sommatoria in questione con n = %d e k = %lf vale: %lf\n", n, k, somma);

}