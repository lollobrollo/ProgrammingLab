#include <stdio.h>

//calcolare il valore massimo e minimo di un insieme di n numeri inseriti da tastiera

void main()
{
  int n;

  printf("Quanti numeri si vuole inserire? \n");
  scanf("%d", &n);

  int max;
  int min;
  int temp;
  
  for(int i = 1; i <= n; i++)
    {
      printf("Inserire il %d' numero: \n", i);
      scanf("%d", &(temp));

      if(i == 1)
      {
        min = temp;
        max = temp;
      }
      else
      {
        if(temp >= max)
        { max = temp; }
      
        if(temp <= min)
        { min = temp; }
      }
      
    }
  if(n == 0)
  { printf("Non sono stati inseriti numeri"); }
  else
  { printf("Tra i numeri inseriti, il massimo vale %d e il minimo vale %d", max, min); }
  

}