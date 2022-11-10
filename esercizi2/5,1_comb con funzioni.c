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

  int N = fattoriale(n); //calcolo n fattoriale
  int K = fattoriale(k); //calcolo k fattoriale

  int s = n - k;
  int S = fattoriale(s); //calcolo s fattoriale
 
  int res = N/(K*S); //calcolo il valore del coefficente binomiale
  printf("il risultato di %d su %d vale: %d\n", n, k, res);
}

int fattoriale(int a)
{
  int temp = 1;
  for (int i = a; i > 0; i--)
    {
      temp *= i;
    }
  return(temp);
}