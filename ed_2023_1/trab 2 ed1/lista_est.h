#ifndef __LISTA_EST_H__
#define __LISTA_EST_H__
#include<stdio.h>
#include<stdlib.h>

//Constante para definicao da capacidade da lista
#define N 10000

//Definicao do tipo da estrutura
struct est_lista {
    int lista[N];
    int contador;
};
typedef struct est_lista tipo_lista;

//Definicao dos prototipos
int insere_inicio_lista(tipo_lista*, int);
int insere_fim_lista(tipo_lista*, int);
int insere_pos_lista(tipo_lista*, int, int);
void salvarEstTxt(char *, tipo_lista *);
#endif