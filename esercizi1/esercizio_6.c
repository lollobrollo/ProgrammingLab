#include <stdio.h>

//fare la potenza di un numero attraverso il prodotto dello stesso

void main()
{
  int b;
  printf("Inserire la base della potenza: \n");
  scanf("%d", &b);

  a:
  
  int e;
  printf("Inserire l'esponente della potenza: \n");
  scanf("%d", &e);
  
  if(e <= 0)
  {
    printf("L'esponente deve essere positivo. \n");
    goto a;
  }

  int p = 1;
  for(int i = 1; i <= e; i++)
    {
      p = p * b;      
    }
  
  printf("Il valore di %d elevato alla potenza di %d è uguale a: %d. \n", b, e, p);

}
