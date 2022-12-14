#include<stdio.h>
#include<stdlib.h>
#define MAXTAM 50   //define um tamanho m�ximo para a pilha


// criando a estrutura da pilha que cont�m um vetor do tamanho MAXTAM que � 50 e uma variavel  indica o topo
typedef struct pilhaVet {
    int item[MAXTAM];
    int topo;
} PilhaVet;

// inicia a pilha com topo = 0
void inicia(PilhaVet *p){
    p->topo = 0;
}

//verifica se a pilha est� vazia ou n�o, caso esteja vazia vai retornar 1 e caso n�o esteja vai retornar 0
int vazia(PilhaVet *p){
    if(p->topo == 0)
        return 1;
    else
        return 0;
}

//verifica se a pilha j� n�o atingiu seu tamanho m�ximo definido pelo MAXTAM
int cheia(PilhaVet *p){
    if(p->topo == MAXTAM-1)
        return 1;
    else
        return 0;
}

//verifica se a pilha est� cheia, caso n�o esteja insere o valor no topo
void insere(PilhaVet *p, int num){
    if(cheia(p) == 1)
        printf("\nErro!!!\n");
    else {
        p->topo++;
        p->item[p->topo] = num;
    }
}

//verifica se a pilha est� vazia, e caso n�o esteja vazia remove o elemento que est� no topo
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

    PilhaVet *p = (PilhaVet*)malloc(sizeof(PilhaVet)); //aloca mem�ria
    inicia(p); // inicia a pilha

    insere(p, 3);   // insere valores
    insere(p, 4);
    insere(p, 5);

    aux = retira(p); // retira valor

    printf("\nFoi retirado: %d", aux);
}
