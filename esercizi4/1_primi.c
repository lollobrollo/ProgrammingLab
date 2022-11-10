 //stabilisco se un numero è primo con una funzione ricorsiva

#include <stdio.h>

int is_prime(int n, int m)
{
  if(n <= m || n == 1) return 1; //caso di uscita
  if(n % m != 0) is_prime(n, m + 1); //controllo divisibilità
  else return 0;
}

void main()
{
  int n;
  a: 
  printf("Inserire un numero naturale: \n");
  scanf("%d", &n);

  if(n < 0)//controllo se il numero è positivo
  {
    printf("Inserire un numero positivo.\n");
    goto a;
  }
  
  int m = 2; //variabile ausiliaria
  
  int res = is_prime(n, m);
  
  if(res) printf("%d è un numero primo.\n", n); 
  else printf("%d non è un numero primo.\n", n);
}