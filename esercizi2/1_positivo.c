#include <stdio.h>

//Leggere da tastiera un generico numero e stampare un messaggio che indichi se è positivo o negativo. Dopodichè stampare il valore assoluto . Risolvere l’esercizio senza alcuna variabile di appoggio.

void main()
{
  float x;
  printf("inserire un numero: \n");
  scanf("%f", &x);


  if(x >= 0)
  {
    printf("il valore inserito è positivo;\n");
  }
  else
  {
    printf("il valore inserito è negativo;\n");
    x = -x;
    }
  printf("il valore assoluto del numero inserito vale: %f\n", x);
}