#include <stdio.h>

/*
    Esercizio 12.1 della dispensa.
*/

double media(int a[], int n)
{
    double somma = 0;
    for (int i = 0; i < n; i++)
        somma += a[i]; // somma = somma + a[i]

    return (somma / n);
}

double pow2(double n)
{
    return n * n;
}

double varianza(int a[], int n)
{
    double m = media(a, n);
    double num = 0;

    for (int i = 0; i < n; i++)
        num += pow2(a[i] - m);

    return (num / n);
}

// funzione ausiliaria per stampare i valori di un array
void print_array(int a[], int N)
{
    for (int i = 0; i < N; i++)
        printf("a[%d] = %d\n", i, a[i]);
    printf("\n");
}

void main()
{
    int n = 5;
    int a[5] = {1, 2, 3, 4, 5};

    print_array(a, n);

    double var = varianza(a, n);
    printf("La varianza dell'array è %f\n", var);
}