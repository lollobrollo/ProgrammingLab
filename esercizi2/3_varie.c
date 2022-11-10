//letti due interi e da tastiera, determinare e stampare le seguenti informazioni: se è un numero positivo o negativo, se è un numero pari o dispari, il valore di a + b, quale scelta dei segni nell'espressione +-a + +-b porta al risultato massimo ed il suo valore.
#include <stdio.h>

void main()
{
  float a;
  float b;
  
  //aquisisco i valori di a e b
  printf("inserire a: ");
  scanf("%f\n", a);
  printf("inserire b: ");
  scanf("%f\n", b);

  //controllo il segno di b
  int i = segno(b);
  if(i = 0)
    printf("%f è un numero positivo", b);
  else
    if(i = 1)
      printf("%f è un numero negativo", b);
    else
      printf("%f vale 0", b);

  //controllo se a è pari o dispari
  int e = pari(a);
  if(e == 0)
      printf("%f è un numero pari", a);
  else
      printf("%f è un numero positivo", a);

  //calcolo a+b
  float sum = somma(a, b);
   printf("la somma tra %f e %f vale %f", a, b, sum);

  //scelta segni per risultato massimo e somma
  int j = segno(a);
  if(i == j)
    if(a > 0)
    {
      float sum = somma(a, b)
      printf("il valore maggiore della somma si ottiene con %f + %f e vale %f", a, b, sum);
    }
    else
    {
       float sum = somma(-a, -b)
      printf("il valore maggiore della somma si ottiene con %f + %f e vale %f", -a, -b, sum);
    }
  else
    if(a > b)
    {
      float sum = somma(a, -b)
      printf("il valore maggiore della somma si ottiene con %f + %f e vale %f", a, -b, sum);
      }
    else
    {
      float sum = somma(-a, b)
      printf("il valore maggiore della somma si ottiene con %f + %f e vale %f", -a, b, sum);
    }
  
}

int segno(float b) //funzione per trovare il segno di b
{
  if(b > 0)
    return(0);
  if(b < 0)
    return(1);
  else
    return(2);
}

int pari(float a) //funzione per controllo parità di a
{
  if(a%2 == 0)
    return(0);
  else
    return(1);
}

float somma(float x, float y)
{
  return(x+y);
}

