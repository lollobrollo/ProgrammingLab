#include <stdio.h>
#include <math.h>

double successione(int b)
{
  if(b == 1)
    return 0.5;
  else
    return ((successione(b-1) + 1) / 2);
}


void main()
{
int n;

printf("inserire n: \n");
scanf("%d", &n);
for(int i = 1; i <= n; i++)
  {
    double S = successione(i);
    printf("%lf\n", S);
  }
}