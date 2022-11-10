#include <stdio.h>

// 2^n con n numero naturale; ricorsiva
int sn(int n)
{
  if(n == 1) return 2;
  return 2 * sn(n-1);
}

// produttoria tra a -> b/2
float P(int a, int b)
{
  int prod = 1;
  
  for(int i = a; i <= b/2; i++)
    {
      prod *= (sn(i) / a);
    }

  prod -= b;
  return prod;
}

int main()
{
  int a, b;
  printf("inserire a: \n");
  scanf("%d", &a);
  printf("inserire b: \n");
  scanf("%d", &b);

  float x = P(a, b);
  
  printf("la sommatoria con a = %d, b = %d vale: %f\n", a, b, x);

}