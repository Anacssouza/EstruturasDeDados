/*
    - Fazer um programa que calcule a média e a variancia
    - Fazer com que o programa leia o numero de valores que serão fornecidos
    - Aloque um vetor dinamicamente
    - Leia os valores e realize os calculos
    - O calculo da média e da variancia deve ser feito em funções
*/

#include<stdio.h>
#include<stdlib.h>

float  cal_media(int quant, float *ptr){

    int i;
    float somar;

    for(i = 0; i < quant; i++){

        somar += ptr[i];

    }

    return somar/quant;

}

float  cal_variancia(int quant, float *ptr, float media){


    int i;
    float soma = 0.0;

    for(i = 0; i < quant; i++){

        soma += (ptr[i] - media) * (ptr[i] - media);

    }
    printf("%f", soma);

    return soma/quant;

}


int main(){

    float *ponteiro;
    float media, variancia;
    int quantidade, i;

    // leitura dos valores
    printf("Quantos notas voce ira apresentar: \n");
    scanf("%d", &quantidade);

    // alocacao dinamica de memoria
    ponteiro = (float*) malloc(quantidade*sizeof(float));

    if(ponteiro==NULL){
        printf("\n Memoria insuficiente \n");
    }

    // leitura dos valores

    for(i = 0; i < quantidade; i++){

        printf("\n Digite o %do numero: \n", i+1);
        scanf("%f", &ponteiro[i]);

    }

   /*

    for(i = 0; i < quantidade; i++){
    printf("%.2f", ponteiro[i]);

    }
    */

    media = cal_media(quantidade, ponteiro);
    variancia = cal_variancia(quantidade, ponteiro, media);
    printf("\n A media eh igual a: %.2f \n", media);
    printf("\n variancia eh igual a: %.2f \n", variancia);

    free(ponteiro);

}
