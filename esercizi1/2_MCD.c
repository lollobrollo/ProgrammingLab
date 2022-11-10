#include <stdio.h>
//calcolo dell'MCD di due numeri
void main()
{
  int xi;
  int yi;

  a:
  
  //richiedo i due numeri all'utente
  printf("Inserire il primo numero naturale: \n");
  scanf("%d", &xi);
  
  printf("Inserire il secondo numero naturale:\n ");
  scanf("%d", &yi);

  if(xi<=0 || yi<=0)
  {
    printf("Inserire numeri positivi!\n");
    goto a;
  }
  else
  {
    int x = xi;
    int y = yi;
    while(x != y)
    {
      if(x > y)
      {
        x = x-y;
      }
      else
      {
        y = y-x;
      }  
    }
    printf("il MCD tra %d e %d è: %d", xi, yi, x);
  }
}