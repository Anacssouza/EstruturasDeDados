#include<stdio.h>
#include<stdlib.h>

int main(){

    int *v;

    //v = malloc(10*sizeof(int)); // vai alocar 40 bytes
    v = (int *) malloc(10*sizeof(int));

    if(v){
        printf("Memoria alocada com sucesso! \n");
        printf("\n v: %d", *v);
        *v = 100;
        printf("\n v: %d", *v);
    } else{
        printf("\n Memoria insuficiente! \n");
    }

    free(v);
}
