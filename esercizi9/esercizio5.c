#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int info;
    struct nodo * next;
};

//ogni volta che scrivo elementoLista intendo struct nodo
typedef struct nodo nodo;


//funzione che restituisce la lunghezza della lista
int lunghezza(nodo * a){
    int len = 0;
    
    if (a == NULL) return len;
    while(a != NULL)
    {
        len ++;
        a = a -> next;
    }
    return len;
}


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


// taglio lunghezza lista
nodo * taglio(nodo * a){
    // prendo il valore k
    int flag = 0;
    int len = lunghezza(a);
    int k;
    while(flag == 0)
    {
        printf("Inserire il valore di taglio: \n");
        scanf("%d", &k);
        if((k <= len) && (k >= 1)) flag = 1;
    }

    // cerco il k-esimo valore e lo memorizzo
    nodo * cut = a;
    int conta = 1;
    flag = 0;
    while(flag == 0)
    {
        if(conta <= k)
        {
            conta ++;
            cut = cut-> next; 
        }
        else flag ++;
    }

    // elimino i valori precedenti
    while(cut != a)
    {
        nodo * temp = a;
        a = a-> next;
        free(temp);
    }
    return cut;
}


void main(){
    //chiamo le funzioni per creare le liste
    nodo * a = crea_lista();
    printf("\n");
    
    stampa_lista(a);
    printf("\n");
    
    nodo * b = taglio(a);
    printf("\n");
    
    printf("Valori tagliati: \n");
    stampa_lista(b);
}