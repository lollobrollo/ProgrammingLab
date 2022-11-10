#include <stdio.h>

//successione di fibonacci
void main()
{
  int n; //elementi della successione  
  printf("Inserire n: ");
  scanf("%d", &n);
  
  for (int i = 0; i <= n; i++)
    {
      int F = fibonacci(i);
      printf("F(%d): %d\n", i, F);
    }
}


int fibonacci(int x)
{
  if (x == 0) //caso con n=0
    return(0);
  
  if (x == 1) //caso con n=1
    return(1);
  
  return(fibonacci(x-1) + fibonacci(x-2)); //caso generale
  }