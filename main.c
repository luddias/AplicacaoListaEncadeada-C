// -----------------------------------------------------------------------
//  .* ESTRUTURA DE DADOS *.
//
//   main.c
//
//   Copyright 2022 Ludmila Dias
//
//  ----------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "tadLista.h"
#include <string.h>

// struct para armazenar
typedef struct
{
    char nome[200];
    float altura;
    char cpf[200];
    int idade;
} tpessoa;


// FUNÇÃO ARQUIVO DE SAIDA
void salvaLstPessoas(lista lst, char arquivo[])
{
    FILE *arq_saida = fopen(arquivo, "a");
    tpessoa *pnum;

    for (int pos = 0; pos < len_lista(lst); pos++)
    {
        pnum = (tpessoa *)dado_lista(lst, pos);
        fprintf(arq_saida, "%s, %s, %d, %.2f\n", pnum->nome, pnum->cpf, pnum->idade, pnum->altura);
    }

    fclose(arq_saida);
    return;
}

// FUNÇÃO CRIA LISTA DE STRUCTS
lista criaLstPessoas(lista lstnomes, lista lstcpfs, lista lstidades, lista lstalturas)
{
    lista lst = cria_lista();

    for (int i = 0; i < len_lista(lstnomes); i++)
    {

        tpessoa *pnum = (tpessoa *)malloc(sizeof(tpessoa));
        tpessoa dadosPessoa;

        strcpy(dadosPessoa.nome, dado_lista(lstnomes, i));
        strcpy(dadosPessoa.cpf, dado_lista(lstcpfs, i));

        dadosPessoa.idade = *(int *)dado_lista(lstidades, i);
        dadosPessoa.altura = *(float *)dado_lista(lstalturas, i);

        *pnum = dadosPessoa;
        append_lista(lst, pnum);
    }

    return lst;
}

// FUNÇÕES COLOCA DADOS DOS ARQUIVOS EM LISTAS
lista carregaNomes(char arquivo[])
{
    lista aux = cria_lista();
    FILE *arq;
    arq = fopen(arquivo, "r");
    while (!feof(arq))
    {
        char *pnum = (char *)malloc(200 * sizeof(char *));
        fgets(pnum, 200, arq);
        // REMOVE O \n DO FINAL DA STRING
        char *pos;
        if ((pos=strchr(pnum,'\n'))!=NULL){
            *pos = '\0';
        }
        append_lista(aux, pnum);
    }

    fclose(arq);
    return aux;
}

lista carregaCpfs(char arquivo[])
{
    lista aux = cria_lista();
    FILE *arq;
    arq = fopen(arquivo, "r");
    while (!feof(arq))
    {
        char *pnum = (char *)malloc(200 * sizeof(char *));
        fgets(pnum, 200, arq);
        // REMOVE O \n DO FINAL DA STRING
        char *pos;
        if ((pos=strchr(pnum,'\n'))!=NULL){
            *pos = '\0';
        }
        append_lista(aux, pnum);
    }

    fclose(arq);
    return aux;
}

lista carregaAlturas(char arquivo[])
{
    lista aux = cria_lista();
    FILE *arq = fopen(arquivo, "r");
    while (!feof(arq))
    {
        float *pnum = (float *)malloc(sizeof(float *));
        fscanf(arq, "%f", pnum);
        append_lista(aux, pnum);
    }

    fclose(arq);
    return aux;
}

lista carregaIdade(char arquivo[])
{
    lista aux = cria_lista();
    FILE *arq;
    arq = fopen(arquivo, "r");
    while (!feof(arq))
    {
        int *pnum = (int *)malloc(sizeof(int));
        fscanf(arq, "%d", pnum);
        append_lista(aux, pnum);
    }

    fclose(arq);
    return aux;
}

// FUNÇÃO PRINCIPAL
int main()
{
    lista lstnomes;
    lista lstcpfs;
    lista lstidades;
    lista lstalturas;
    lista lstPessoas;

    lstnomes = carregaNomes("bdnomes.txt");
    lstcpfs = carregaCpfs("bdcpfs.txt");
    lstidades = carregaIdade("bdidades.txt");
    lstalturas = carregaAlturas("bdalturas.txt");

    lstPessoas = criaLstPessoas(lstnomes, lstcpfs, lstidades, lstalturas);

    salvaLstPessoas(lstPessoas, "bdpessoas.txt");

    return 0;
}
