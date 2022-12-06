#include <stdio.h>

int mia_somma(int *p, int a) //'conta' mi dice da che indice devo partire
{
    int tmp = 0;
    for(int i = a; i < (a + 3); i++) tmp += *(p + i);

    return tmp;
}

void main()
{    
    int n = 5;
    int a[5] = {2, 4, 2, 6, 1};
    int k = 90;
    
    int flag = -1;
    int i = 0;
    while((flag < 0) && (i <= (n - 2)))
        {
            
            int somma = mia_somma(&a, i);
            if(somma == k) flag = i;
            i ++;
        }

    if(flag == (-1)) printf("il predicato è falso\n");
    else printf("il predicato è vero con i = %d\n", flag);
}