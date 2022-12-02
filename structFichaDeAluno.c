/*

 * Crie uma estrutura com nome ficha_de_aluno e acrescente os seguintes campos: nome, disciplina, nota_prova1, nota_prova2
 e nota_prova3
 * defina uma variável do novo tipo criado
 * faça a leitura de dados para cada uma das informações.
 * faça com que seja possível cadastrar 3 alunos.
 * crie sub-rotinas para cada funcionalidade do seu algoritmo;
 * crie uma sub-rotina para calcular a média do de cada aluno.

 */

#include<stdio.h>
#include<stdlib.h>

typedef struct ficha_de_aluno{

    char nome[50];
    char disciplina[50];
    float nota_prova1;
    float nota_prova2;
    float nota_prova3;

} Ficha_de_aluno;


Ficha_de_aluno lerFicha(){

    Ficha_de_aluno f;

    printf("Nome: ");
    fflush(stdin);
    fgets(f.nome,50, stdin);

    printf("Disciplina: ");
    fflush(stdin);
    fgets(f.disciplina, 50, stdin);

    printf("Nota 1: ");
    scanf("%f", &f.nota_prova1);

    printf("Nota 2: ");
    scanf("%f", &f.nota_prova2);

    printf("Nota 3: ");
    scanf("%f", &f.nota_prova3);

    return f;
}

Ficha_de_aluno imprimirFicha(){

    Ficha_de_aluno f;

    printf("\n ----- Alunos Cadastrados ----- \n");
    printf("\n Nome: %s", f.nome);
    printf("\n Disciplina: %s", f.disciplina);
    printf("\n Nota 1: %.2f", f.nota_prova1);
    printf("\n Nota 2: %.2f", f.nota_prova2);
    printf("\n Nota 3: %.2f \n", f.nota_prova3);
    printf(" ---------------------------------- ");

    return f;

}


void main(){

    Ficha_de_aluno f;

    lerFicha();

    imprimirFicha();

}
