#include <stdio.h>

void main()
{
/* dichiariamo la variabile n
numero di elementi da considerare
*/
  int n;
  printf("inserire il valore di n: \n");
  scanf("%d", &n);

  printf("Di seguito ti stamperò i quadrati perfetti fino a %d\n", n);

// trovo il quadrato dei primi n numeri naturali con il for  
int q;
for(int i = 1; i <= n; i++)
  {
    q = i*i;
    printf("Il quadrato di %d è %d\n", i, q);
    
  }
// faccio l'esercizio con il while
int p = 1;
while(n>=p)
{
  
  printf("Il quadrato di %d è %d\n", p, p*p);
  p = p+1;
}
  
}