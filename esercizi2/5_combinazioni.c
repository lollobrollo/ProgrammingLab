#include <stdio.h>

//calcolo le combinazioni di n su k
void main()
{
  int n;
  int k;
  printf("inserire i valori del coefficente binomiale;\n inserire n: \n");
  scanf("%d", &n);
  printf("inserire k: \n");
  scanf("%d", &k);

  int N = 1; //variabile per contenere n!
  for(int i = 1; i<=n; i++)
    {
      N *= i;
    }
  
  int K = 1; //variabile per contenere k!
  for(int i = 1; i<=k; i++)
    {
      K *= i;
    }
  
  int s = n - k;
  int S = 1; //variabile per contenere s!
  for(int i = s; i>=1; i--)
    {
      S *= i;
    }

  int res = N/(K*S); //calcolo il valore del coefficente binomiale
  printf("il risultato di %d su %d vale: %d\n", n, k, res);
}