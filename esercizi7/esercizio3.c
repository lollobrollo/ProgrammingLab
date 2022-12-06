#include <stdio.h>

float scal(float a[], float b[], float *p, int n)
{
  for(int i = 0; i < n; i++)
      *(p + i) = a[i] * b[i];
}

void main()
{
  int n = 4;
  float a[4] = {1, 4.6, 14, -4};
  float b[4] = {0.5, -0.9, 0.25, 4};

  float prod[4];
  scal(a, b, &prod, n);

  for(int i = 0; i < n; i++) printf("%lf\n", prod[i]);
}