#include <stdio.h>

int triangolare(int *p, int n)
{
    //caso base
    if(n == 1) 
    {
        *p = 1;
        return 1;
    }
    //chiamata ricorsiva
    *(p + n - 1) = n + triangolare(p, n-1);
    return *(p + n - 1);
}

void main()
{
    int n = 3;
    int a[3];
    int b = triangolare(&a, n);
    for(int i = 0; i<n; i++) printf("%d\n", a[i]);
}