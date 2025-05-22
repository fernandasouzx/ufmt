/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Aluna: Fernanda Lima de Souza
 * Implementacao dos algorimtmos de ordenacao
 * Arquivo de cabeçalho FILAENCADEADA.H
**/

#ifndef __FILA_ENC__
#define __FILA_ENC__

#include <stdio.h> 
#include <stdlib.h>

struct est_no{
    int valor;
    struct est_no *prox;
}; typedef struct est_no tipo_no;

tipo_no *aloca_novo_no(int);
void insereFilaEnc(tipo_no **, int);
int removeFilaEnc(tipo_no **);
void inprimeFilaEnc(tipo_no *);
int qtdValores(tipo_no *);

#endif //__FILA_ENC__