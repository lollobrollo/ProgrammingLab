#include <stdio.h>

int ceck_sum(int *p, int n, int *q, int m)
{
  flag = 0;
  int i = 0;
  while((i < n) && (flag == 0))
  //for(int i = 0; i < n; i++)
      {
        int sommaB = 0;
        for(int j = 0; j < m; j++) sommaB += *(q + j);
        if(sommaB == *(p + i)) flag ++
        i++;
      }
  return flag;
}

void main()
{
    int n = 3;
    int m = 5;
    int a[3] = {1, 2, 3};
    int b[5] = {5, 3, 5, 2, 1};

    if(ceck_sum(&a, n, &b, m)) 
}