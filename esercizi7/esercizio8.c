#include <stdio.h>

int predicato(int a[], int n, int indice)
{
    for(int j = 0; j < n; j++)
    //while((flag < 0) && (j < n))
        {
            if((j != indice) && (!((a[indice] % a[j]) != 0))) 
            {
                return j;
            }
        }
    return (-1);
}

void main()
{
    int n = 5;
    int a[5] = {13, 2 , 3, 4, 5};
    int b[5];
    
    for(int i = 0; i < n; i++)
        {
            int test = predicato(a, n, i);
            if(test < 0) b[i] = a[i];
            else b[i] = 0;
        }
    
    printf("a[%d] = ", n);
    for(int i = 0; i < n; i++) printf("%d, ", a[i]);
    printf("\nb[%d] = ", n);
    for(int i = 0; i < n; i++) printf("%d, ", b[i]);
}