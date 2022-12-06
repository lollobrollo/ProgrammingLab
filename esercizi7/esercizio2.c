#include <stdio.h>

int doppione(int *p, int n)
{
  int i = 0;
  int j = 1;
  int flag = 1;
  while((i < n) && (j < n) && flag == 1)
  //for(int i = 0; i < n; i++)
    {
      while(j < n)
          {
            if(*(p + i) == *(p + j)) flag--;
            j++;
          }
      i++;
      j = i + 1;
    }
//se j ha raggiunto n e non ha trovato doppioni
  if(flag) return 1;
  return 0;
}

void main()
{
  int n = 5;
  int a[5] = {1, 2, 3, 4, 5};
  int b[5] = {1, 3, 2, 3, 5};

  int test1 = doppione(&a, n);
  int test2 = doppione(&b, n);

  //risultato array a
  if(test1) printf("l'array a non ha doppioni\n");
  else printf("l'array a ha doppioni\n");

  //risultato array b
  if(test2) printf("l'array b non ha doppioni\n");
  else printf("l'array b ha doppioni\n");
    
}