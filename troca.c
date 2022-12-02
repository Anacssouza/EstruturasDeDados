void troca(int *a, int *b){

    int aux;
    aux = *a;
    *a = *b;
    *b = aux;

}




int main(){

    int a = 2, b = 3;

    troca(&a, &b);

    printf("a = %d  || b = %d", a, b);

}
