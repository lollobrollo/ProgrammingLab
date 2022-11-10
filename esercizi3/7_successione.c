#include <stdio.h>
#include <math.h>

/*

double successione(double x, double y)
{
  if(x == 1)
    return y;
  else
    return (0,5*(successione(x-1, y) + (y / successione(x-1, y))));
}


void main()
{
  int n;
  double p;
  
  printf("inserire n: \n");
  scanf("%d", &n);
  printf("inserire p: \n");
  scanf("%lf", &p);
  
for(int i = 1; i <= n+1; i++)
  {
    double S = successione(i, p);
    printf("%lf\n", S);
  }

  double lim = sqrt(p);
  printf("il limite della succesisone vale: %lf", lim);
}


*/


double a_n(int n, double p)
{
  double a_i = p;
  printf("a_1 = %lf\n", a_i);
  for(int i = 2; i <= n; i++)
  {
    a_i = 0,5*(a_i + p/a_i);
  }
  printf("a_%d = %lf\n", i, a_i)
}

int main()
{
  int n;
  int p;

  printf("inserire n: \n");
  scanf("%d", &n);
  printf("inserire p: \n");
  scanf("%lf", &p);

  double a = a_n(p, n);
}

