#include <stdio.h>
//algoritmo per il prodotto di due numeri
void main()
{
  int xi;
  int yi;

  a:
  
  //richiedo i due numeri all'utente
  printf("Inserire il primo numero naturale: \n");
  scanf("%d", &(xi));
  
  printf("Inserire il secondo numero naturale:\n ");
  scanf("%d", &(yi));

  
  if(xi < 0 || yi < 0)
  {
    printf("Inserire numeri positivi!\n");
    goto a;
  }
  else
  {
    int x = xi;
    int y = yi;
    int p = 0;
    
    while(x != 1)
      {
        
        if(x%2 == 0)
        {
          x = x/2;
          y = y*2;
          
        }
        else
        {
          p = p+y;
          x = (x-1)/2;
          y = y*2;
        }
        
      }
      p += y;
    
    printf("il prodotto tra %d e %d vale: %d \n", xi, yi, p);
  }
}