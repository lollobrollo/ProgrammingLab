#include <stdio.h>
#include <stdlib.h>

//funzione per mettere l'indice nell'intervallo giusto
void abs_value(int *p, int i, int k, int n)
{
    if((i+k) < 0) *p = i + k + n;
    else *p = i + k - n;
}

//funzione per ruotare un array di k posizioni
void rotation(int *a, int n, int k)
{
    //creo array temporaneo e ci metto dentro i valori di a ruotati
    int * tmp = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++)
    {
        int index;
        if(((i + k) < n)&&((i+k)>= 0)) index= i + k;
        else abs_value(&index, i, k, n);
        *(tmp + i) = *(a + index);
    }

    //inserisco i valori ruitati nell'array iniziale
    for(int i = 0; i < n; i++) *(a + i) = *(tmp + i);
    free(tmp);
}



void main()
{
    //dichiaro l'array
    //int n = 6;
    //int a[6] = {1, 3, 5, 0, 2, 4};
    int n = 7;
    int a[7] = {0, 1, 2, 3, 4, 5, 6};
    int k = -3;
    //chiamo la funzione
    rotation(&a, n, k);

    for(int i = 0; i < n; i++) printf("%d\n", a[i]);
}