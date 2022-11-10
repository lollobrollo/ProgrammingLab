#include <stdio.h>
#include <math.h>

int uguaglianza(double a, double b, double c)
{
  double A = a - b;
  if(A < 0)
    A = -A;
  if(A < c)
    return 1;
  else
    return 0;
}

void main()
{
  double x, y, e;
  
  printf("inserire epsilon: \n");
  scanf("%lf", &e);
  printf("inserire x: \n");
  scanf("%lf", &x);
  printf("inserire y: \n");
  scanf("%lf", &y);

  int i = uguaglianza(x, y, e);
  if(i == 0)
    printf("%lf e %lf sono diversi con epsilon %lf", x, y, e);
   else
    printf("%lf e %lf sono uguali con epsilon %lf", x, y, e);
}