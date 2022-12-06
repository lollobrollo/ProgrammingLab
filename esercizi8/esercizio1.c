/*
#include <stdio.h>
#include <stdlib.h>

//funzione che crea array copia senza duplicati
int* my_fun(int *p, int n, int *dim) 
{
    int *temp = (int *) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) *(temp + i) = 9876;
    int tmp_dim = 0;
    //spazzo tutti i valori dell'array
    for(int i = 0; i < n; i++)
    {
        int flag = 0;
        int j = 0;
        //controllo se l'i-esimo elemento è gia in temp 
        while((flag == 0) && (j < i))
            {
                if(*(p + i) == temp[i]) flag++;
                j++;
            }
        //controllo se nel ciclo attuale ho trovato doppioni
        if(flag == 0)
        {
            temp[tmp_dim] = *(p + i);
            tmp_dim ++;
        }
    }
    
    *dim = tmp_dim;
    int *copia;
    copia = (int*) malloc(sizeof(int) *(tmp_dim));
    
    //copio gli elementi di temp nell'heap per mantenerli
    for(int i = 0; temp[i] != 9876; i++)
        {
            copia[i] = temp[i];
        }
    free(temp);
    return &copia;
}


void main()
{
    //dichiaro l'array
    int n = 5;
    int a[5] = {7, 14, -8, 8, 5};
    int dim = 0;
    
    //chiamo la funzione
    int *result = my_fun(&a, n, &dim);

    printf("gli elementi dell'array senza duplicati sono: \n");
    for(int i = 0; i < dim; i++) printf("%d\n", *(result + i));
}
*/