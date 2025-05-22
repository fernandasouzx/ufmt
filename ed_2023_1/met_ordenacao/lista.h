/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discente: Fernanda Lima de Souza
 * 
 * Implementacao da estrutura de LISTA 
 * Arquivo de cabeçalho LISTA.H
***/

#ifndef __LISTA_H__
#define __LISTA_H__

#include<stdio.h>
#include<stdlib.h>

//Constante para definicao da capacidade da lista
#define N 10

//Definicao do tipo da estrutura
struct est_lista {
    int lista[N];
    int contador;
};typedef struct est_lista tipo_lista;

//Definicao dos prototipos
int insere_inicio_lista(tipo_lista*, int);
int insere_fim_lista(tipo_lista*, int);
int insere_pos_lista(tipo_lista*, int, int);
int remove_inicio_lista(tipo_lista*);
int remove_fim_lista(tipo_lista*);
int remove_pos_lista(tipo_lista*, int);
int remove_valor_lista(tipo_lista*, int);
int busca_pos_lista(tipo_lista, int);
int busca_valor_lista(tipo_lista, int);
int busca_maior_lista(tipo_lista);
int busca_menor_lista(tipo_lista);
void imprime_lista(tipo_lista);
int encontrapos(int*, int , int);

#endif //Fim __LISTA_H__