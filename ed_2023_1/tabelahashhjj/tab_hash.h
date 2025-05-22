#include <stdio.h>
#include <stdlib.h>

#ifndef __TAB_HASH_H__
#define __TAB_HASH_H__

#define TAM_HASH 10 //define a capacidade de tab hash


//definicao da estrutura do no
struct est_no_hash{
    int chave; //chave que identifica o conjunto de dados
    char valor;
    struct est_no_hash *prox;
};
typedef struct est_no_hash tipo_no_hash;

struct est_tab_hash{
    tipo_no_hash *tabela_hash[TAM_HASH];

};
typedef struct est_tab_hash tipo_tab_hash;


// Prototipo das funcoes

void inicializaTabHash(tipo_tab_hash*);
tipo_no_hash *alocaNoHash(int, char);
int funcaoHash(int);
void insereTabHash(tipo_tab_hash*, int, char);
char removeTabHash(tipo_tab_hash*, int);
tipo_no_hash *buscaTabHash(tipo_tab_hash*, int);
void imprimeTabHash(tipo_tab_hash*);


#endif 