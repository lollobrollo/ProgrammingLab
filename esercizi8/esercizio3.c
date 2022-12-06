#include <stdio.h>
#include <stdlib.h>

//funzione per unire due array ordinati in un unico array ordinato
 int * fusione(int a[], int b[], int n, int m)
{
    //dimensione e array completo
    int dim = n + m;
    int * c = (int *)malloc(sizeof(int)*dim);
    
    int x = 0; //indice per array a
    int y = 0; //indice per l'array b
    //per ogni elemento di c faccio il seguente processo
    for(int i = 0; i < dim; i++)
    {
        //se non ho ancora raggiunto la fine di uno dei due faccio questo
        if((x < n) && (y < m))
            if(a[x] <= b[y])
            {
                c[i] = a[x];
                x++;
            }
            else
            {
                c[i] = b[y];
                y++;
            }
        else
        {
            //se ho finito di inserire gli elementi di a e non di b
            if((x >= n) && (y < m))
            {
                for(int i = (x+y); i < dim; i++)
                {
                    c[i] = b[y];
                    y++;
                }
            }
            //se ho finito di controllare gli elementi di b e non di a
            if((y >= m) && (x < n))
            {
                for(int i = (x+y); i < dim; i++)
                {
                    c[i] = a[x];
                    x++;
                }
            }
        }
    }
    return c;
}


void main()
{
    //dichiaro l'array
    int n = 5;
    int a[5] = {1, 3, 5, 7, 9};
    int m = 4;
    int b[4] = {2, 4, 6, 8};
    //chiamo la funzione
    int * c = fusione(a, b, n, m);

    for(int i = 0; i < (n+m); i++) printf("%d\n", *(c + i));
}
