#include <stdio.h>

void main()
{
  //dichiaro e chiedo all'utente i tre numeri
  int x;
  int y;
  int z;
  
  printf("inserire il primo numero: \n");
  scanf("%d", &x);
  printf("inserire il secondo numero: \n");
  scanf("%d", &y);
  printf("inserire il terzo numero: \n");
  scanf("%d", &z);
  
  int temp = minimo(x, y);
  temp = minimo(temp, z);

  printf("il minimo tra i numeri inseriti è %d\n", temp);

  
  //uso una funzione di test per controllare il minimo di una tripletta
  printf("si testa ora la funzione minimo tra %d e %d:\n", x, y);
  test(x, y);
}


int minimo(int a, int b)
{
  if(a < b)
    return a;
  else
    return b;
}

int massimo(int a, int b)
{
  if(a > b)
    return a;
  else
    return b;
}

void test(int a, int b)
{
  int temp;
   for(int w = 1; w <= massimo(a, b); w++)
    {
      temp = minimo(a, b);
      temp = minimo(temp, w);
      printf("tripletta(%d, %d, %d) - minimo: %d\n", a, b, w, temp);
    }
}