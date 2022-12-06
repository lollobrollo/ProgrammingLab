#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int info;
    struct nodo * next;
};

//ogni volta che scrivo elementoLista intendo struct nodo
typedef struct nodo nodo;


//stampa lista in maniera ricorsiva
void stampa_lista(nodo * a){
    //se non ho valori nella lista finisco la funzione
    if(a == NULL) return;
    //stampo il valore attuale e passo al prossimo
    printf("%d\n", a -> info);
    stampa_lista(a -> next);   
}


//funzione che ritorna il puntatore alla testa della lista
nodo * crea_lista(){
    nodo* a = NULL;
    int n;
    printf("Inserire un numero: \n");
    scanf("%d", &n);
    if(n == -1) return a;
    nodo * nuovo = malloc(sizeof(nodo));
    
    //accedo a info di nodo
    //(*nuovo).info = n;   due scritture equivalenti
    nuovo -> info = n;
    //quando la lista finisce il puntatore al 
    //prossimo nodo deve essere null
    nuovo -> next = NULL;
    a = nuovo;

    //creo nuovo puntatore per la coda della lista
    nodo * coda;
    coda = nuovo;
    
    //chiedo altri valori
    printf("Inserire un nuovo numero: \n");
    scanf("%d", &n);
    while(n != -1){
        //creo un nuovo nodo e gli do n
        nuovo = malloc(sizeof(nodo));
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



//inserimento elemento k in maniera ordinata
void inserimento(nodo* a){
    //prendo il valore k
    int k;
    printf("Inserire un valore: \n");
    scanf("%d", &k);

    //variabili ausiliarie per l'inserimento
    nodo * precedente = a;
    nodo * successivo = a;
    
    int trovato = 0;
    //ricerco il punto dove inserire il valore
    while(trovato == 0)
    {
        if (successivo -> info <= k)
        {
            successivo = successivo -> next;
            if(successivo == a-> next)
                precedente = a;
            else
                precedente = precedente -> next;
        }
        else trovato = 1;
    }

    //ora spezzo il legame tra i due e ci
    //inserisco un nodo contenente k
    nodo * nuovo = malloc(sizeof(nodo));
    nuovo -> info = k;
    precedente -> next = nuovo;
    nuovo -> next = successivo;
}



void main(){
    //chiamo le funzioni per creare le liste
    nodo * a = crea_lista();
    inserimento(a);
    stampa_lista(a);
}