/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitário do Araguaia
 * Bacharelado em Ciência da Computação
 * 
 * Disciplina de ESTRUTURA DE DADOS 1
 * Prof. Ivairton M. Santos
 * Discente: Fernanda Lima de Souza
 * Data: 15 fev 2024
 * 
 * Implementacao da estrutura de LISTA CIRCULAR DUPLAMENTE ENCADEADA
 * Arquivo de cabeçalho LISTA CIRCULAR DUPLAMENTE ENCADEADA.H
***/

#ifndef __LISTA_CIR_DUP_H
#define __LISTA_CIR_DUP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct est_no_dup{
    int valor;
    struct est_no_dup *prox;
    struct est_no_dup *ant;

};typedef struct est_no_dup tipo_no_dup;

//Prótotipo das funcoes
tipo_no_dup *aloca_no(int);
void insereInicioLstCirDup(tipo_no_dup**, int);
void insereFimLstCirDup(tipo_no_dup**, int);

int removeInicioLstCirDup(tipo_no_dup**);
int removeFimLstCirDup(tipo_no_dup**);
//void GiraRoleta(tipo_no_dup **);
void imprimeLstCirDup(tipo_no_dup*);


#endif //__LISTA_CIR_DUP_H