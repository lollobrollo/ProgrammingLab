#include <stdio.h>

//successione di fibonacci
void main()
{
  int n; //elementi della successione  
  printf("Inserire n: ");
  scanf("%d", &n);
  
  if (n < 0) //caso con n negativo
  {
    printf("inserire un numero positivo.\n");
  }
  
  if (n == 0) //caso con n=0
    printf("F(0): 0\n");

  if (n == 1) //caso con n=1
    printf("F(1): 1\n");

  if(n > 1) //caso generale
  {
    //stampo i primi due valori
    printf("F(0): 0\n");
    printf("F(1): 1\n");

    //calcolo gli altri valori
    int F1 = 0;
    int F2 = 1;
    for(int i = 2; i <= n; i++)
      {
        int temp = F2;
        F2 = fibonacci(F1, F2);
        F1 = temp;
        printf("F(%d): %d\n", i, F2);
      }
  }
}


int fibonacci(int x, int y)
{
  int z = x + y;
  return(z);
}