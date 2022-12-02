#include<stdio.h>
#include<stdlib.h>

struct lista{

    int matricula;
    struct lista* proximo;

};

typedef struct lista Lista;

// Função de inicialização:

Lista* inicializa(void){

    return NULL;

}

// Inserção no início: retorna a lista atualizada

Lista* insere(Lista* l, int i){

    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->matricula = i;
    novo->proximo = l;

    return novo;
}



/* função insere_ordenado: insere elemento em ordem */
Lista* insere_ordenado (Lista* l, int v){

     Lista* novo = insere(l,v); /* cria novo nó */
     Lista* ant = NULL; /* ponteiro para elemento anterior */
     Lista* n = l; /* ponteiro para percorrer a lista*/
     /* procura posição de inserção */

     while (n != NULL && n->matricula < v) {
        ant = n;
        n = n->proximo;
     }
     /* insere elemento */
     if (ant == NULL) { /* insere elemento no início */
        novo->proximo = l;
        l = novo;
     } else { /* insere elemento no meio da lista */
        novo->proximo = ant->proximo;
        ant->proximo = novo;
     }
 return l;
}

// Função Imprime: imprimir os valores dos elementos
void imprime(Lista* l){

    Lista* p; // variavel para percorrer a lista
    for(p = l; p != NULL; p = p->proximo){
        printf("\n Matricula: %d \n", p->matricula);
    }
    printf("\n ------- \n");
    }

// Função vazia: retorna l se vazia ou retorna 0
int vazia(Lista* l){

    if(l == NULL)
        return 1;
    else
        return 0;

}

Lista* retira(Lista* l, int v){

    Lista* anterior = NULL; //ponteiro para elemento anterior
    Lista* p = l; // ponteiro para percorrer a lista

    // procura elemento na lista, guardando o anterior
    while( p != NULL && p->matricula != v){
        anterior = p;
        p = p->proximo;
    }

    // verifica se achou elemento
    if( p == NULL)
        return 1; //Não achou: retornar

    // retira elemento
    if( anterior == NULL){ // retira elemento do início
        l = p->proximo;
    } else {
        // retira elemento do meio da lista
        anterior->proximo = p->proximo;
    }
    free(p);

    return l;
}

void libera(Lista* lista){
    Lista* p = lista;

    while(p != NULL){
        //Lista* temp =  p->proximo; || guarda referencia para o proximo
        free(p);
        //p = temp
    }

}

int main(void){

    Lista* listaEncadeada; // declara uma lista não inicializada
    listaEncadeada = inicializa(); // inicializa lista como vazia
   /* listaEncadeada = insere(listaEncadeada,4); // insere na lista o elemento 4
    listaEncadeada = insere(listaEncadeada,8); // insere na lista o elemento 8

    imprime(listaEncadeada);

    listaEncadeada = insere(listaEncadeada,9); // insere na lista o elemento 9

    listaEncadeada = insere(listaEncadeada,10); // insere na lista o elemento 10

    listaEncadeada = retira(listaEncadeada, 8);
    imprime(listaEncadeada); */



    listaEncadeada = insere_ordenado(listaEncadeada,1);
    listaEncadeada = insere_ordenado(listaEncadeada,9);
    listaEncadeada = insere_ordenado(listaEncadeada,3);
    listaEncadeada = insere_ordenado(listaEncadeada,5);
    listaEncadeada = insere_ordenado(listaEncadeada,7);

    imprime(listaEncadeada);


    return 0;

}
