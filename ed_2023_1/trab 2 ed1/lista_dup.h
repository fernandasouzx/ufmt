 #ifndef __LISTA_DUP__
#define __LISTA_DUP__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct est_noh_dup
{
    int valor;
    struct est_noh_dup *ant;
    struct est_noh_dup *prox;
};
typedef struct est_noh_dup tipo_noh_dup;

tipo_noh_dup *aloca_noh_dup(int);
void insereInicioLstDup(tipo_noh_dup **, int);
void insereFimLstDup(tipo_noh_dup **, int);
void inserePosLstDup(tipo_noh_dup **, int, int);
void salvarDupEncTxt(char *, tipo_noh_dup *);
int contaNosDup(tipo_noh_dup *);
#endif