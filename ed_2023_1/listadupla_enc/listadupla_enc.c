/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 *
 * Disciplina de ED I
 * Prof. Ivairton
 * Discente: Fernanda Lima de Souza
 *
 * Implementacao da estrutura de LISTA DUPLAMENTE ENCADEADA
 * Arquivo de cabeçalho LISTA DUPLAMENTE ENCADEADA.H
 ***/


#include <stdio.h>
#include <stdlib.h>
#include "listadupla.h"


tipo_no_dup *aloca_no(int vl){

    tipo_no_dup *novo_no;
    novo_no=(tipo_no_dup*)malloc(sizeof(tipo_no_dup));
    if (novo_no != NULL){

        novo_no->prox=NULL;
        novo_no->ant=NULL;
        novo_no->valor = vl;
        return novo_no;

    }else{
        return NULL;
    }
}

void insereInicioLstDup(tipo_no_dup **lst, int vl){
    tipo_no_dup *novo_no;
    novo_no = aloca_no(vl);

    if (novo_no != NULL){
        if((*lst)!= NULL){
            novo_no->prox = (*lst);
            (*lst)->ant = novo_no;
        }
        (*lst) = novo_no;
    }else{
        printf("[ERRO] Falha a insercao de valor no inicio.\n");
    }
}

void insereFimLstDup(tipo_no_dup **lst, int vl){
    tipo_no_dup *novo_no, *aux;
    novo_no = aloca_no(vl);

    if (novo_no != NULL){
        aux = (*lst);
        while(aux->prox!=NULL){
            aux = aux->prox;
        }
        novo_no->ant = aux;
        aux->prox = novo_no;
    }
}

void inserePosLstDup(tipo_no_dup **lst, int vl, int pos){

    if(pos<0){
        printf("Posição Invalida!\n");
        return;
    }
    if(pos == 0){
        insereInicioLstDup(lst,vl);
        return;
    }
    tipo_no_dup *novo_no, *aux, *ant=NULL;
    tipo_no_dup *novo_no, *aux, *ant=NULL;
    tipo_no_dup *aux = *lst;
    int contador;
    novo_no= (tipo_no_dup*)malloc(sizeof(tipo_no_dup));

    while((aux!=NULL) && (contador<pos)){
        ant = aux;
        aux = aux->prox;
        contador++;
    }

    if(aux!=NULL) && (contador < pos){
            
    ant->prox = novo_no;
    novo_no->ant = ant;
    novo_no->ant = aux;

    if(aux != NULL){
        aux->ant = novo_no;
    }
}

int removeInicioLstDup(tipo_no_dup **lst){
    tipo_no_dup *aux;
    int valor;

    if ( (*lst) != NULL) { //Verifica se lista tem valor
        valor = (*lst)->valor;
        if ((*lst)->prox == NULL) {//Verifica se ha um unico valor
            free ((*lst));
            (*lst) = NULL;
        } else {
            aux = (*lst);
            (*lst) = (*lst)->prox;
            (*lst)->ant = NULL;
        }
        return valor;
    } else {
        return -1;
    }
}

int removeFimLstDup(tipo_no_dup **lst){
    tipo_no_dup *aux;
    int valor;

    if ( (*lst) != NULL) { //Verifica se lista tem valor
        valor = (*lst)->valor;
        if ((*lst)->prox == NULL) {//Verifica se ha um unico valor
            free ((*lst));
            (*lst) = NULL;
        } else {
            aux = (*lst);
            (*lst) = (*lst)->prox;
            (*lst)->ant = NULL;
        }
        return valor;
    } else {
        return -1;
    }
}

int removePosLstDup(tipo_no_dup**lst, int pos){
    if(*lst == NULL){
        printf("Lista Vazia!\n");
        return -1;
    }
    if(pos < 0){
        printf("Posição Invalida!\n");
        return -1;
    }
    if(pos == 0){
        return removeInicioLstDup(lst);
    }


    tipo_no_dup *anterior =NULL;
    tipo_no_dup *aux = *lst;
    int contador = 0;


    while(contador < pos && aux->prox != NULL) {
        anterior = aux;
        aux = aux->prox;
        contador++;
    }
    if(aux==NULL){
        printf("Posição Invalida!\n");
        return -1;
    }
    anterior->prox = aux->prox;

    if(aux->prox != NULL){
       aux->prox->ant = anterior;

    int valor = aux->valor;
    free(aux);
    return valor;
}

void imprimeLstDup(tipo_no_dup *lst){
    if(lst != NULL){
        printf("[NULL]");
        while(lst!=NULL){
            printf("->[%d]<-", lst->valor);
            lst=lst->prox;
        }
        printf("[NULL]\n");
    }
}
