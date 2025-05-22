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

#ifndef __LISTADUPLA_H__
#define __LISTADUPLA_H__

#include <stdio.h>
#include <stdlib.h>

struct est_no_dup{
    int valor;
    struct est_no_dup *prox;
    struct est_no_dup *ant;

}; typedef struct est_no_dup tipo_no_dup;



//Prótotipo das funcoes
tipo_no_dup *aloca_no(int);
void insereInicioLstDup(tipo_no_dup**, int);
void insereFimLstDup(tipo_no_dup**, int);
void inserePosLstDup(tipo_no_dup**, int, int);
int removeInicioLstDup(tipo_no_dup**);
int removeFimLstDup(tipo_no_dup**);
int removePosLstDup(tipo_no_dup**, int);
void imprimeLstDup(tipo_no_dup*);

#endif //__LISTADUPLA_H__