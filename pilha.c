// Empilhar valores inteiros
#include<stdio.h>
#include<stdlib.h>

struct No{
    int numero;
    struct No *atual;
};

typedef struct No no;

int tam;

//interfaces
int menu(void);
void inicia(no *PILHA);
void opcao(no *PILHA, int op);
void exibe(no *PILHA);
void libera(no *PILHA);
void empilhar(no *PILHA);
no *desempilhar(no *PILHA);

int menu(void){

    int opcao;

    printf("\nEscolha a opcao desejada: \n");
    printf("0 - Sair \n");
    printf("1 - Zerar a pilha \n");
    printf("2 - imprimir \n");
    printf("3 - Empilhar \n ");
    printf("4 - Desempilhar\n");
    printf("\nOpcao escolhida: \n");
    scanf("%d", &opcao);

    return opcao;
}

void opcao(no *PILHA, int op){

    no *temp;

    switch(op){
    case 0:
        libera(PILHA);
        break;
    case 1:
        libera(PILHA);
        inicia(PILHA);
        break;
    case 2:
        exibe(PILHA);
        break;
    case 3:
        empilhar(PILHA);
        break;
    case 4:
        temp = desempilhar(PILHA);
        if(temp != NULL)
            printf("\nRetirado da pilha o elemento: %d \n", temp->numero);
        //desempilhar(PILHA);
        break;
    default:
        printf("\nComando invalido. \n\n");
    }
}

// inicia a pilha e aponta o seu ponteiro para proximo
void inicia(no *PILHA){

    PILHA->atual = NULL;
    tam = 0;
}

//verifica se a nossa pilha esta vazia
int vazia(no *PILHA){

    if(PILHA->atual == NULL)
        return 1;
    else
        return 0;
}

// Alocar um espaço na memória

no *aloca(){
    no *novo = (no*) malloc(sizeof(no));

    if(!novo){
        printf("\nSem memoria disponível para alocar \n");
        exit(1);
    }else{
        printf("\nInforme um novo numero a ser empilhado \n");
        scanf("%d", &novo->numero);

        return novo;
    }
}

void libera(no *PILHA){

    if(!vazia(PILHA)){
        // dois ponteiros: 1 para saber o elemento
        no *proximoNo, *noAtual;
        noAtual = PILHA->atual;

        while(noAtual != NULL){
            proximoNo = noAtual->atual;
            free(noAtual);
            noAtual = proximoNo;
        }
    }
}

void exibe(no *PILHA){

    if(vazia(PILHA)){ //antes de exibir verifica se não ta vazia
        printf("\nPilha vazia! \n\n");
        return;
    }

    no *auxiliar;

    auxiliar = PILHA->atual;
    printf("\nA sua pilha tem os seguintes elementos: \n");

    while(auxiliar != NULL){
        printf("%5d", auxiliar->numero);
        auxiliar = auxiliar->atual;
    }
    printf("\n");
};

//push
void empilhar(no *PILHA){

    no *novo = aloca();

    novo->atual = NULL;

    if(vazia(PILHA))
        PILHA->atual = novo;
    else {
        no *auxiliar = PILHA->atual;
        //testar sem a seta
        while(auxiliar->atual != NULL){
            auxiliar = auxiliar->atual;
        }
        auxiliar->atual = novo;
    }
}

//pop
no *desempilhar(no *PILHA){

    if(PILHA->atual == NULL){
        printf("/nPilha esta vazia! \n");
        return NULL;
    } else{
        no *ultimo = PILHA->atual, *penultimo = PILHA;

        // vamos iterar até o *ponteiro apontar para NULL
        while(ultimo->atual != NULL){
            penultimo = ultimo;
            ultimo = ultimo->atual;
        }
        penultimo->atual == NULL;
        return ultimo;
    }
}

int main(void){

    no *PILHA = (no*) malloc(sizeof(no));
    if(!PILHA){
        printf("\nSem memória disponível. \n");
        exit(1);
    } else {
        inicia(PILHA);
        int aux;

        do{
            aux = menu();
            opcao(PILHA, aux);
        }while(aux);

        free(PILHA);
        return 0;

    }
}
