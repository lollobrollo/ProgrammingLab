#include <stdio.h>
#include <math.h>


double distanza(double a, double b, double c, double d)
{
  //calcolo in passaggi i valori che servono per la distanza
  double X = (a - c) * (a - c);
  double Y = (b - d) * (b - d);
  return sqrt(X + Y);
}

void main()
{
  double x1, y1;
  double x2, y2;
  
  //aquisisco le coordinate dei punti
  printf("inserire x1: \n");
  scanf("%lf", &x1);
  printf("inserire y1: \n");
  scanf("%lf", &y1);
  printf("inserire x2: \n");
  scanf("%lf", &x2);
  printf("inserire y2: \n");
  scanf("%lf", &y2);

  //calcolo la distanza
  double d = distanza(x1, y1, x2, y2);
  printf("la distanza tra (%lf, %lf) e (%lf, %lf) vale: %lf", x1, y1, x2, y2, d);
}
