#include <stdio.h>
#include <stdlib.h>

//funzione counting sort
 void counting_sort(int a[], int n)
{
    //controllo valore massimo
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] > k) k = a[i] + 1;
    }
    //printf("k = %d\n", k);
    //creo array ausiliario e lo azzero
    int * conta = (int *)malloc(sizeof(int)*k);
    for(int i = 0; i < k; i++) *(conta + i) = 0;
    
    //for(int i = 0; i < n; i++) printf("%d\n", *(conta + i));
    
    for(int i = 0; i < n; i++)
    {
        *(conta + a[i]) += 1;
    }
    //for(int i = 0; i < k; i++) printf("%d\n", *(conta + i));
    
    //azzero l'array di partenza e lo ordino
    for(int i = 0; i < n; i++) a[i] = 0;

    //inserisco i valori ordinati nell'array
    int indice_conta = -1;
    int quanti = 0;
    //int flag = 0;
    int i = 0;
    while(i < n)
    {
        //int flag = 0;
        //printf(" quanti = %d,\n", quanti);
        
        while((indice_conta < k) && (quanti == 0))
        {
            if(quanti == 0) indice_conta++;
            quanti = *(conta + indice_conta);
        }
        //printf(" quanti = %d,\n", quanti);
        
        while(quanti > 0)
        {
            a[i] = indice_conta;
            i++;
            quanti--;
        }
        //printf(" indice_conta = %d, quanti = %d\n", indice_conta, quanti);
    }
    
}


void main()
{
    //dichiaro l'array
    int n = 6;
    int a[6] = {1, 7, 5, 3, 9, 3};
    //chiamo la funzione
    counting_sort(a, n);

    for(int i = 0; i < n; i++) printf("%d\n", a[i]);
}
