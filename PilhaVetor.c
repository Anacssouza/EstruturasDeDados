#include<stdio.h>
#include<stdlib.h>
#define MAXTAM 50   //define um tamanho máximo para a pilha


// criando a estrutura da pilha que contém um vetor do tamanho MAXTAM que é 50 e uma variavel  indica o topo
typedef struct pilhaVet {
    int item[MAXTAM];
    int topo;
} PilhaVet;

// inicia a pilha com topo = 0
void inicia(PilhaVet *p){
    p->topo = 0;
}

//verifica se a pilha está vazia ou não, caso esteja vazia vai retornar 1 e caso não esteja vai retornar 0
int vazia(PilhaVet *p){
    if(p->topo == 0)
        return 1;
    else
        return 0;
}

//verifica se a pilha já não atingiu seu tamanho máximo definido pelo MAXTAM
int cheia(PilhaVet *p){
    if(p->topo == MAXTAM-1)
        return 1;
    else
        return 0;
}

//verifica se a pilha está cheia, caso não esteja insere o valor no topo
void insere(PilhaVet *p, int num){
    if(cheia(p) == 1)
        printf("\nErro!!!\n");
    else {
        p->topo++;
        p->item[p->topo] = num;
    }
}

//verifica se a pilha está vazia, e caso não esteja vazia remove o elemento que está no topo
int retira(PilhaVet *p){
    int aux;

    if(vazia(p) == 1)
        printf("\nErro!!!\n");
    else {
        aux = p->item[p->topo];
        p->topo--;

    return aux;
    }
}

int main(){
    int aux;

    PilhaVet *p = (PilhaVet*)malloc(sizeof(PilhaVet)); //aloca memória
    inicia(p); // inicia a pilha

    insere(p, 3);   // insere valores
    insere(p, 4);
    insere(p, 5);

    aux = retira(p); // retira valor

    printf("\nFoi retirado: %d", aux);
}
