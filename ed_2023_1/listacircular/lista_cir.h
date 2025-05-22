/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discente: Fernanda Lima de Souza
 * 
 * Implementacao da estrutura de LISTA CIRCULAR ENCADEADA
 * Arquivo de cabeçalho LISTA CIRCULAR ENCADEADA.H
***/

#ifndef __LISTA_CIR_H__
#define ___LISTA_CIR_H__

#include <stdio.h>
#include <stdlib.h>

struct est_no{
    int valor;
    struct est_no *prox;

}; typedef struct est_no tipo_no;


//Prótotipo das funcoes
tipo_no *aloca_no(int);

void insereFimLstCir(tipo_no**, int);
void insereInicioLstCir(tipo_no**, int);

int removeInicioLstCir(tipo_no**);
int removeFimLstCir(tipo_no**);

void imprimeLstCir(tipo_no*);

#endif //__LISTA_CIR_H__