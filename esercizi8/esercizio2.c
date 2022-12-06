#include <stdio.h>
#include <stdlib.h>
/*
void swap(int a[], int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
*/

 int conta(int a[], int n, int j)
{
    int conta = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] <= j) conta++;
    }
    if(conta == j) return 1;
    return 0;
}

void ordina(int a[], int n, int j)
{
    if((j >= 0) && (j < n) && (conta(a, n, j) == 1))
    {
        int min[j], mag[j], dim_min = 0, dim_mag = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] <= j)
            {
                min[dim_min] = a[i];
                dim_min ++;
            }
            else
            {
                mag[dim_mag] = a[i];
                dim_mag ++;
            }
        }
        
        for(int i = 0; i < (dim_min-1); i++) a[i] = min[i];
        for(int i = 0; i < dim_mag; i++) a[i+dim_min] = mag[i];
    }
    else printf("l'array non può essere ordinato.\n");
}


void main()
{
    //dichiaro l'array
    int n = 5;
    int a[5] = {4, 5, 1, 3, 2};
    int j = 3;
    //chiamo la funzione
    ordina(a, n, j);

    for(int i = 0; i < n; i++) printf("%d\n", a[i]);
}
