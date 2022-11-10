#include <stdio.h>

//Dati due interi positivi n e k da tastiera, calcolare la sommatoria (immagine) e stampare a schermo il risultato.



void main()
{
  int n;
  int k;

  printf("inserire la base della potenza: \n");
  scanf("%d", &k);
  printf("inserire il massimo esponente della potenza: \n");
  scanf("%d", &n);

  int sum = 0; //contenitore della sommatoria
  for(int i = 1; i <= n; i++) //passi della sommatoria
    {
      int temp = potenza(k, i); //placeholder della potenza
      sum += temp;
    }
  
  
  printf("la sommatoria di %d elevato alla n che va da 1 a %d vale: %d \n", k, n, sum);
}

int potenza(int x, int y) //funzione per calcolo della singola potenza
{
  int z = 1;
  for(int j = 1; j <= y; j++)
    {
    z = z*x;
    }
  return(z);
}