#include <stdio.h>
//fare la media di numeri inseriti dall'utente

void main()
{
  int x= 1;
  float somma = 0;
  int c;
  while (x != 0)
  {
    printf("inserire un numero intero: \n");
    scanf("%d", &x);
    somma = somma + x;
    c++;
  }
  c--;
  somma = somma/c;
  printf("la media dei numeri inseriti vale: %f", somma);
}