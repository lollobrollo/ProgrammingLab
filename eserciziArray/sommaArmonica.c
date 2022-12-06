#include <stdio.h>

void main()
{
  int n;
  printf("inserire n: \n");
  scanf("%d", &n);

  double h;
  somma_armonica(n, &h); 

  printf("somma armonica: %lf", h);
}


void somma_armonica(int n, double * p)
{
  if(n == 1) * p = 1.0;
  else 
  {
    somma_armonica(n - 1, p);
    * p += 1.0 / n;
  }
}