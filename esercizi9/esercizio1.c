#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int info;
    struct nodo * next;
};

//ogni volta che scrivo elementoLista intendo struct nodo
typedef struct nodo elementoLista;
//scrivendo lista intendo il puntatore a elementoLista
typedef elementoLista * lista;

//funzione che ritorna il puntatore alla testa della lista
lista crea_lista(){
    lista a = NULL;
    int n;
    printf("Inserire un numero: \n");
    scanf("%d", &n);
    if(n == -1) return a;
    elementoLista * nuovo = malloc(sizeof(elementoLista));
    
    //accedo a info di nodo
    //(*nuovo).info = n;   due scritture equivalenti
    nuovo -> info = n;
    //quando la lista finisce il puntatore al 
    //prossimo nodo deve essere null
    nuovo -> next = NULL;
    a = nuovo;

    //creo nuovo puntatore per la coda della lista
    elementoLista * coda;
    coda = nuovo;
    
    //chiedo altri valori
    printf("Inserire un nuovo numero: \n");
    scanf("%d", &n);
    while(n != -1){
        //creo un nuovo nodo e gli do n
        nuovo = malloc(sizeof(elementoLista));
        nuovo -> info = n;
        nuovo -> next = NULL;

        //collego l'elemento precedente a questo
        coda -> next = nuovo;
        //collego il puntatore coda della lista
        //all'ultimo nodo creato
        coda = nuovo;
        printf("Inserire un nuovo numero: \n");
        scanf("%d", &n);
    }
    return a;
}



//stampa lista in maniera ricorsiva
void stampa_lista(lista a){
    //se non ho valori nella lista finisco la funzione
    if(a == NULL) return;
    //stampo il valore attuale e passo al prossimo
    printf("%d\n", a -> info);
    stampa_lista(a -> next);
        
}



//stampa lista iterativa
void stampa_lista_it(lista a){
    while(a != NULL)
    {
        printf("%d\n", a -> info);
        a = a->next;
    }
}



void main(){
    //cliamo le funzioni per creare e stampare la lista
    lista a = crea_lista();
    stampa_lista(a);
}