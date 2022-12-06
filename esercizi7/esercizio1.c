#include <stdio.h>

void main()
{
    //dichiaro l'array
  int n = 5;
    int a[5] = {7, 14, 8, 16, 5};
    //chiamo la funzione
    int somma = sommatoria(&a, n);
    printf("%d\n", somma);
}

int sommatoria(int *p, int n)
{
  int somma = 0;
//spazzo tutti i valori dell'array
  for(int i = 0; i < n; i++)
    {
    //controllo se l'indice è pari
      if(i % 2 == 0) somma += *(p + i);
    }
    return somma;
}