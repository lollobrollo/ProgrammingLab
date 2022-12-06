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


//taglio di un valore della lista
nodo* elim(nodo * a, nodo *a_index){

    //trovo l'indice precedente a quello duplicato
    while(a->next != a_index) a = a->next;
    //printf("elim pre \n");
    // linko precedente e successivo ed elimino il nodo duplicato
    a-> next = a_index-> next;
    free(a_index);
    //printf("elim post\n");
    return a;
}



//funzione che elimina i valori duplicati di una lista
void duplicati(nodo * a){
    
    //creo lista temporanea per il controllo di duplicati
    nodo* temp = malloc(sizeof(nodo));
    nodo* temp_head = temp;
    temp-> info = -1;
    temp-> next = NULL;
    //puntatore per indicare dove sono nella lista
    nodo * a_index = a;
    //printf("1\n");
    
    while(a_index != NULL)
    {
       
        int valore = a_index-> info;
        int trovato = controllo(valore, temp_head);
        //printf("2\n");
        if(trovato == 1)
        {
            a_index = elim(a, a_index);
            //printf("2.5\n");
        }
        else
        {
            //creo un nuovo blocco e ci metto dentro il valore unico
            nodo* nuovo = malloc(sizeof(nodo));
            nuovo-> info = valore;
            
             //metto il nuovo blocco in coda a temp
            nodo* temp_index = temp_head;
            while(temp_index->next != NULL) temp_index = temp_index-> next;
            temp_index-> next = nuovo;
            //printf("3\n");
        }
        
        a_index = a_index-> next;
    }
    //printf("4\n");
    
    //libero lo spazio di temp
    temp = temp_head;
    while(temp != NULL)
    {
        temp = temp-> next;
        free(temp_head);
        temp_head = temp;
        //printf("5\n");
    }
    //printf("6\n");
}


//funzione per la ricerca di una valore in un'altra lista
int controllo(int valore, nodo* lista){
    
    while(lista != NULL)
    {
        if(lista-> info == valore) return 1;  //trovato
        lista = lista-> next;
    }
    
    return 0;  //non trovato
}


/*
la funzione prende la testa di una lista e inverte
tutte le connessioni, restituendo la nuova testa
*/
nodo* inverti_ordine(nodo* old_head){

    //se ho una lista vuota ritorno nulla
    if(old_head == NULL) return NULL;

    // caso in cui o la lista ha un solo elemento
    if(old_head -> next == NULL) return old_head;

    // caso in cui o la lista ha due elementi
    if(old_head->next->next == NULL)
    {
        nodo * new_head = old_head-> next;
        new_head-> next = old_head;
        old_head->next = NULL;
        return new_head;
    }

    //gestisco il caso in cui ho tre o più nodi

    //creo i puntatori di cui ho bisogno
    nodo * temp1 = old_head;
    nodo * temp2 = temp1->next;
    nodo * anchor = temp2->next;

    //taglio il link alla testa originaria
    old_head-> next = NULL;
    
    //qua inverto i collegamenti finchè non ne mancano meno di tre
    while(anchor != NULL)
    {
        //inverto il link dei primi due elementi
        temp2->next = temp1;

        //avanzo con i puntatori
        temp1 = temp2;
        temp2 = anchor;
        anchor = anchor->next;
    }


    // dal ciclo per l'inversione rimangono due elementi, quindi
    //inverto gli untimi due elementi e ritorno la nuova testa
    temp2-> next = temp1;
    return temp2;
}



void main(){
    //chiamo le funzioni per creare le liste
    nodo * a = crea_lista();
    printf("-=-=-=-=-=-\n");
    
    stampa_lista(a);
    printf("-=-=-=-=-=-\n");
    
    // duplicati(a);
    nodo * b = inverti_ordine(a);
    printf("Lista invertita: \n");
    stampa_lista(b);
}