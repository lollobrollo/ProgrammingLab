/*
Dato un numero 𝑛 ∈ 𝑁, 𝑛 > 0 vogliamo stabilire se sia primo oppure no. Si implementi una funzione che testi la verità del predicato “𝑛 è un numero primo”.
Si crei inoltre un programma che testi la funzione per i valori di input che vanno da 1 a 100 (incluso). Il programma deve stabilire il numero di numeri primi trovati nell’intervallo
*/
#include <stdio.h>

int primo(int n)
{
  //controllo se primo (<100)
  if(((n%2) != 0) && ((n%3) != 0) && ((n%5) != 0) && ((n%7) != 0) || (n == 2) || (n == 3) || (n == 5) || (n == 7))
    return 0;//primo
  else
    return 1;//non primo
}

void main()
{
  int n;
  printf("inserire un numero naturale: \n");
  scanf("%d", &n);
  
  int res = primo(n);
  if(res)
    printf("%d non è un numero primo.\n", n); 
  else
    printf("%d è un numero primo.\n", n);

  //conto i numeri primi fino a 100
  int conta = 0;
  for(int i = 2; i <= 100; i++)
    {
      int b = primo(i);
      if(b == 1)
        conta++;        
    }
  printf("tra 1 e 100 ci sono %d numeri primi.\n", conta);
}