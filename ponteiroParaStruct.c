#include<stdio.h>

typedef struct data{

    int dia, mes, ano;

}Data;


void lerData(Data *nomeQualquer){

    printf("\n Dia: \n");
    scanf("%d", &nomeQualquer->dia);
    printf("\n Mes: \n");
    scanf("%d", &nomeQualquer->mes);
    printf("\n Ano: \n");
    scanf("%d", &nomeQualquer->ano);

}

void imprimirData(Data *nomeQualquer){

    printf("\n Imprimir Data: %d/%d/%d \n", nomeQualquer->dia, nomeQualquer->mes, nomeQualquer->ano);

}

/*

    o ponto vai ser usado como acesso a estrutura, já a -> vai ser utilizado no acesso de ponteiros.

*/


int main(){

    Data *p;
    Data meuAniversario;

    p = &meuAniversario;

   // meuAniversario.dia = 10;
    //meuAniversario.mes = 9;
   // meuAniversario.ano = 2001;

    lerData(p);

    imprimirData(p);

    printf("\n Printf do Main %d/%d/%d \n", meuAniversario.dia, meuAniversario.mes, meuAniversario.ano);
    printf("\n Endereco de data: %x || Endereco de p: %x \n", &meuAniversario, p);

}
