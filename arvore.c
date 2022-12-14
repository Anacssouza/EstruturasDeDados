#include<stdio.h>
#include<stdlib.h>

typedef struct no{

    int valor;
    struct no *direita, *esquerda;

}NoArvore;

//compara com a raiz

NoArvore* inserir(NoArvore *raiz, int num){

    if(raiz == NULL){
        NoArvore *aux = malloc(sizeof(NoArvore));

        aux->valor = num; // seta o valor recebido
        aux->esquerda = NULL;
        aux->direita = NULL;

        return aux; // retorna o ponteiro para o nó criado(end. de memoria conteúdo de raiz)
    } else {
        if(num < raiz->valor) // caso sim, insere na esquerda
            raiz->esquerda = inserir(raiz->esquerda, num);
        else // caso não, insere na direita
            raiz->direita = inserir(raiz->direita, num);

        return raiz;
    }
}

void imprimir_1(NoArvore *raiz){         // raiz no começo da impressão
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_1(raiz->esquerda);
        imprimir_1(raiz->direita);
    }
}

void imprimir_2(NoArvore *raiz){        // raiz no meio da impressão
    if(raiz){
        imprimir_1(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_1(raiz->direita);
    }
}

int main(){
    NoArvore *raiz = NULL;
    int opcao, valor;

    do{
        printf("\n0 - Para sair; \n1 - Para inserir; \n2 - imprimir. \n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("\nDigite o valor a ser inserido\n");
            scanf("%d", &valor);

            raiz = inserir(raiz, valor);
            break;
        case 2:
            printf("\n\nAgora vem a impressao recursiva: \n");
            imprimir_1(raiz);
            printf("\n");
            printf("\n\nAgora vem a 2° impressão: \n");
            imprimir_2(raiz);
            printf("\n");
            break;
        default:
            printf("\nOpcao invalida");
        }
    }while(opcao != 0);

    return 0;
}
