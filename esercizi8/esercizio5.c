#include <stdio.h>
#include <stdlib.h>
/*
//calcolo dimensione malloc
int dimensione(int a[], int n)
{
    int k = 0;
    int k_ =  0;
    for(int i = 0; i < n; i++)
    {
        if(a[i]>=0) if(a[i] > k) k = a[i];
        else if(a[i] < k_) k_ = a[i];
    }
    int dim = -k_ + k + 1;
    return dim;
}
*/
void my_swap(int a[], int i)
{
    int tmp = a[i];
    a[i] = a[i+1];
    a[i+1] = tmp;
}

//ordinamento array a forma d'onda
 void onda(int a[], int n)
{
    //ordino l'array di partenza
    int i = 0;
    int not_done = 0;
    while(i < n-1)
    {
        if(a[i] > a[i+1])
        {
            my_swap(a, i);
            not_done ++;
        }
        if(not_done == 0) i++;
        else
        {
            not_done --;
            if(i > 0) i--;
        }
    }
    
    int temp[n];
    //metto l'array in forma d'onda
    int down = n-1;
    int up = 0;
    int j = 0;
    while(up < down)
    {
        temp[up] = a[j];
        up++;
        j++;
        temp[up] = a[down];
        down --;
        up++;
    }
    
    while(up < n)
    {
        temp[up] = a[j];
        up++;
        j++;
    }

    //sistemo il caso con n dispari
    if (n%2 != 0) my_swap(temp, n-2);
        
    for(int i = 0; i < n; i++) a[i] = temp[i];
}


void main()
{
    //dichiaro l'array
    //int n = 6;
    //int a[6] = {1, 3, 5, 0, 2, 4};
    int n = 7;
    int a[7] = {1, 3, 5, 0, 2, 4, 6};
    //chiamo la funzione
    onda(a, n);

    for(int i = 0; i < n; i++) printf("%d\n", a[i]);
}
