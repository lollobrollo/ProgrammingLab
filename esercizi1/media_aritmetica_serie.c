#include <stdio.h>

void main()
{
  //prendo un numero naturale dall'utente
  int n;
  printf("inserire un numero intero: \n");
  scanf("%d", &n);

  //faccio la somma dei primi n numeri naturali
  int somma = 0;
  for(int i = 0; i <= n; i++)
    {
      somma = somma+i;
    }

  //divido la somma per n, ottenendo la media aritmetica
  float media = somma/n;
  printf("la media dei primi %d numeri naturali vale: %f", n, media);

}