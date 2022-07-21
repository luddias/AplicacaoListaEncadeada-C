// -----------------------------------------------------------------------
//  .* ESTRUTURA DE DADOS *.
//
//   tad_lista.c
//
//   Copyright 2022 Ludmila Dias
//
//  ----------------------------------------------------------------------


#include "tadLista.h"
#include <stdlib.h>
#include <stdio.h>

// IMPLEMENTAÇÃO DO TAD LISTA

lista cria_lista(){

    lista lst = (lista)malloc(sizeof(tcabec));
    lst->tamanho = 0;
    lst->primeiro = NULL;
    lst->ultimo = NULL;

    return lst;
}

int len_lista(lista lst){
    return lst->tamanho;
}

tdado prim_lista(lista lst){
    return lst->primeiro->dado;
}

tdado ult_lista(lista lst){
    return lst->ultimo->dado;
}

lista append_lista(lista lst, tdado dado){

    if(lst == NULL) return NULL;

    pnoh novo_no = (pnoh)malloc(sizeof(tnode));
    novo_no->proximo = NULL;
    novo_no->dado = dado;

    if(len_lista(lst)==0){
        lst->primeiro = novo_no; 
        lst->ultimo = novo_no;
    } else{
        lst->ultimo->proximo = novo_no;
        lst->ultimo = novo_no;
    }
    
    lst->tamanho++;
 }

tdado dado_lista(lista lst, int pos){
    int cont_pulos;
    pnoh no_corrente;

    if((lst == NULL) || (pos < 0) || (pos >= lst->tamanho)){
        return NULL;
    }

    cont_pulos = 0;
    no_corrente = lst->primeiro;

    while(cont_pulos != pos){
        cont_pulos++;
        no_corrente = no_corrente->proximo;
    }

    return no_corrente->dado;

}

/*
int index_lista(lista lst, tdado dado){

}
lista insert_lista(lista lst, int index, tdado dado){

}
lista remove_lista(lista lst, int index){
}
*/
