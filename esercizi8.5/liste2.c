#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int info;
    struct elemento* next;
};

typedef struct elemento ElementoDiLista;

void main()
{
    ElementoDiLista* node = NULL; 
    node = (ElementoDiLista*)malloc(sizeof(ElementoDiLista));
    node -> info = 10;
    node -> next = NULL;
}