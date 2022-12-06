#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int info;
    struct nodo * next;
};

//ogni volta che scrivo elementoLista intendo struct nodo
typedef struct nodo nodo;



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


//funzione per unire le liste:
// se j > 0 b in coda ad a 
// se j <= 0 a in coda ad b
node * merge(node* a, node*b){
    //variabile testa della lista finale
    node * head;

    //chiedo il valore j
    int j;
    printf("inserire j: \n");
    scanf("%d", &j);
    
    if(j > 0){
        //salvo la testa
        head = a;
        //arrivp alla fine di a
        while(a != NULL)
            a = a -> next;

        //linko la fine di a all'inizio di b
        a-> next = b;
    }
    else{
        //salvo la testa
        head = a;
        //arrivo alla fine di b
        while(b != NULL)
            b = b -> next;
        
        //linko la fine di b ad a
        b-> next = a;
    }

    return head;
}



void main(){
    //chiamo le funzioni per creare le liste
    nodo * a = crea_lista();
    //stampa_lista(a);
    nodo * b = crea_lista();
    //unisco le liste
    nodo * c = merge(a, b);
}