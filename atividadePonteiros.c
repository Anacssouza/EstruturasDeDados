#include<stdio.h>

void main(){

    int var = 1, *ponteiro1, *ponteiro2, *ponteiro3;

    ponteiro1 = &var;
    ponteiro2 = ponteiro1 + 7;
    ponteiro3 = ponteiro2 - 7;

    printf("\n O endereco original eh = %x \n", &var);
    printf("\n Ponteiro1 + 7 = %x \n", ponteiro2);
    printf("\n Ponteiro3 - 7 = %x \n", ponteiro3);

}
