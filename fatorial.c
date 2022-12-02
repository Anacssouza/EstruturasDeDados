#include<stdio.h>

void main(){

    int i;
    int num;
    int fat = 1;

    printf("digite o número: ");
    scanf("%d", &num);

    for(i = 1; i <= num; i++){
        fat *= i;
    }

    printf("o fatorial de %d eh %d", num, fat);


}
