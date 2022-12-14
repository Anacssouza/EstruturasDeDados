#include<stdio.h>
#include<stdlib.h>

#define MAXTAM 10

// Cria a estrutura da fila contendo um vetor de tamanho 10, que foi definido pelo MAXTAM, e uma variável para indicar o fim da fila
typedef struct filaVetor{
    int item[MAXTAM];
    int fim;
}FilaVetor;

//inicia a fila zerando tudo
void inicia(FilaVetor *f){
    for(int i = 0; i < MAXTAM; i++){
        f->item[i] = 0;
    }
    f->fim = 0;
}

int vazia(FilaVetor *f){
    if(f->fim == 0)
        return 1;
    else
        return 0;
}

int cheia(FilaVetor *f){
    if(f->fim == MAXTAM)
        return 1;
    else
        return 0;
}

// insere um valor no final da fila
void insere(int num, FilaVetor *f){
    if(cheia(f) == 1)
        printf("\nErro, Fila cheia!\n");
    else{
        f->item[f->fim] = num;
        f->fim++;
    }
}

// retira o valor do início da fila
void retira(FilaVetor *f){
    int num;
    if(vazia(f) == 1)
        printf("\nErro, Fila vazia!\n");
    else{
        num = f->item[0];
        for(int i = 0; i < f->fim; i++){
            f->item[i] = f->item[i+1];
        }
        f->fim--;
        return num;
    }
}

//procedimento para imprimir a fila
void imprime(FilaVetor *f){
    for(int i = 0; i < f->fim; i++){
        printf(" %d ||", f->item[i]);
    }
    printf("\n");
}

int main(){
    FilaVetor *f = (FilaVetor*)malloc(sizeof(FilaVetor)); //aloca memória

    inicia(f); //inicia a fila

    insere(10,f); // insere valores
    insere(20,f);
    insere(30,f);

    imprime(f); // imprime os 3 valores inseridos

    retira(f); // retira o valor do início da fila

    imprime(f); // imprime os 2 valores restantes na fila

}
