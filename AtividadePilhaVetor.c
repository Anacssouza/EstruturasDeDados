#define MAX 50
typedef struct pilha {
 int n;
 float vet[MAX];
}Pilha;

Pilha* cria (void)
{
 Pilha* p = (Pilha*) malloc(sizeof(Pilha));
 p->n = 0; /* inicializa com zero elementos */
 return p;
}

void push (Pilha* p, float v)
{
 if (p->n == MAX) { /* capacidade esgotada */
 printf("Capacidade da pilha estourou.\n");
 exit(1); /* aborta programa */
 }
 /* insere elemento na próxima posição livre */
 p->vet[p->n] = v;
 p->n++;
}

float pop (Pilha* p)
{
 float v;
 if (vazia(p)) {
 printf("Pilha vazia.\n");
 exit(1); /* aborta programa */
 }
 /* retira elemento do topo */
 v = p->vet[p->n-1];
 p->n--;
 return v;
}

int vazia (Pilha* p)
{
 return (p->n == 0);
}


int main(void){

    Pilha *PILHA = (Pilha*) malloc(sizeof(Pilha));
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

