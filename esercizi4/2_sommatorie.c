#include <stdio.h>

//sommatoria dei primi n numeri naturali; ricorsiva
int som_ricor(int j)
{
  if(j == 1) return 1;
  return j + som_ricor(j-1);
}

//somma delle sommatorie dei primi n numeri naturali,
//con n che varia nell'intervallo a - b; iterativa
int intervallo_iter(int a, int b) 
{
  int som = 0;
  for(a; a <= b; a++)
    {
      som = som + som_ricor(a);
    }
  return som;
}

int main()
{
  int a, b;
  printf("inserire a: \n");
  scanf("%d", &a);
  printf("inserire b: \n");
  scanf("%d", &b);

  int x = intervallo_iter(a, b);
  printf("la sommatoria con a = %d, b = %d vale: %d\n", a, b, x);

}