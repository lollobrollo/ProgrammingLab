#include <stdio.h>


// FUNZIONE PER IL CALCOLO DI UN NUMERO
double pow2(double x)
{
  return x * x;
}

//FUNZIONE PER IL CALCOLO DELLA MEDIA DI N VALORI
double media(int a[], int n)
{
  double m = 0;
  for(int i = 0; i < n; i++)
    {
      m += a[i];
    }
  return m / n;
}

// FUNZIONE PER LA SOMMATORIA DEI VALORI DI UN ARRAY
double sommatoria(int a[], int dim)
{
  double m = media(a, dim);
  double tmp = 0;
  for(int i = 0; i < dim; i++)
    {
      tmp += a[i] - m;
    }
  return pow2(tmp);
}

//FUNZIONE PER IL CALCOLO DELLA VARIANZA
double varianza(int a[], int dim)
{
  double num = 0;
  double m = media(a, dim);
  for(int i = 0; i < dim; i++)
    {
      num += pow2(a[i] - m);
    } 
  return (num / dim);
}

void main()
{
  int dim = 5;
  int a[5] = {1, 2, 3, 4, 5};
  
  double var = varianza(a, dim);
  printf("La varianza dell'array è %lf", var);
}
