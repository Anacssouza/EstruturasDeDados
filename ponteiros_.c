#include<stdio.h>

int main(){

    int *p;        //ponteiro para inteiro
    int a = 231;
    int b = 7680;

    printf(" \n &a vale: %x ", &a);
    printf(" \n &b vale: %x ", &b);
    printf(" \n &p vale: %x ", &p);

    printf("p vale: %p ", p);


    p = &a;   // atribui valor a p

    printf(" \n p vale: %x", p);
    printf(" \n *p vale: %d", *p);

    p = &b;   // atribui valor a p

    printf(" \n p vale: %x", p);
    printf(" \n *p vale: %d", *p);

    *p = 500;
    printf(" \n b vale: %d", b);

}
