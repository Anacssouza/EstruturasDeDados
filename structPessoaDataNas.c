/*
    Desenvolver um programa que tenha uma estrutura pessoa que contenha nome, cpf, data de nascimento e endereço,
    sendo os dois ultimos outras duas esttuturas também.
    faça sub rotinas para cada processo.

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct nascimento{

    int dia, mes, ano;

} Nascimento;

typedef struct endereco{

    int cep;
    char bairro[50];
    char cidade [50];
    int num;

} Endereco;

typedef struct pessoa{

    Nascimento dataNas;
    Endereco endereco;
    char nome[50];
    int cpf;

}Pessoa;

Pessoa lerPessoa(){

    Pessoa p;

    printf("\nData de Nascimento (dd/mm/aaaa): ");
    scanf("%d%d%d", &p.dataNas.dia, &p.dataNas.mes, &p.dataNas.ano);

    printf("\nEndereco: (cep, bairro, cidade, numero) ");
    scanf("%d", &p.endereco.cep);

    fgets(p.endereco.bairro, 50, stdin);
    fgets(p.endereco.cidade, 50, stdin);
    scanf("%d", &p.endereco.num);

    printf("\nnome: ");
    fgets(p.nome, 50, stdin);
    printf("\ncpf: ");
    scanf("%d", &p.cpf);

    return p;

}

Pessoa imprimirPessoa(){

    Pessoa p;

    printf("\nNome - %s", p.nome);
    printf("\nCPF - %d", p.cpf);
    printf("\nData de Nascimento - %d/%d/%d", p.dataNas.dia, p.dataNas.mes, p.dataNas.ano);
    printf("\nEndereco - CEP: %d || Bairro: %s || Cidade: %s || Numero: %d", p.endereco.cep, p.endereco.bairro, p.endereco.cidade, p.endereco.num);

    return p;
}

void main(){

    Pessoa p;

    lerPessoa();
    imprimirPessoa();

}
