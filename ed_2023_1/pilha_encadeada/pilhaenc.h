#ifndef __PILHA_ENC_H__
#define __PILHA_ENC_H__

#include <stdio.h>
#include <stdlib.h>

struct est_no{
    int valor;
    struct est_no *prox;
}; typedef struct est_no tipo_no;

//Prototipos

tipo_no *aloca_no (int);
void empilha(tipo_no **, int);
int desempilha(tipo_no **);
void inprimePilhaEnc(tipo_no *);

#endif //__PILHA_ENC_H__