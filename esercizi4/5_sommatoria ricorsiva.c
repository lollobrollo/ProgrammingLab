#include <stdio.h>

int my_pow(int n, int k) //funzione potenza
{
  if(k == 1) return 1;
  return n * my_pow(n, k - 1);
}


int s_n(int n) //funzione successione ricorsiva con k=3
{
  if(n == 1) return 3;
  int num =n * my_pow(3, n + 1);
  int sn = num / my_pow(3, n);
  return sn + s_n(n - 1);
}
/*

int s_n(int n) //funzione successione iterativa con k=3
{
  int tmp;
  for(i nt i = 1; i <= n; i++)
    {
      tmp += (i * my_pow(3, i + 1)) / my_pow(3, i);
    }
  return tmp;
}
*/

int main()
{
  int n;

  printf("inserire n: \n");
  scanf("%d", &n);
  
  int somma = s_n(n); 

  printf("la sommatoria con n = %d e k = 3 vale: %d\n", n, somma);

}
