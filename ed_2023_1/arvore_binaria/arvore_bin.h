#ifndef ARVORE_BIN_H
#define ARVORE_BIN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct est_no_ar {
    char letra;
    int chave;
    struct est_no_ar *esq;
    struct est_no_ar *dir;
} tipo_no_arv;

// Prototipos das funções
tipo_no_arv *alocaNo(char letra, int chave);
void insere(tipo_no_arv **no, char letra, int chave);
void percursoPreOrdem(tipo_no_arv *no);
void percursoPosOrdem(tipo_no_arv *no);
void percursoOrdem(tipo_no_arv *no);
int buscachave(tipo_no_arv *no, int chave);
int altura(tipo_no_arv *no);
void imprimeNivel(tipo_no_arv *arv, int nivel);
int contagem(tipo_no_arv *arv);
int maiorchaveArv(tipo_no_arv *no);
int menorchaveArv(tipo_no_arv *no);
//void removeArvBin(tipo_no_arv **no, int chave);

#endif // ARVORE_BIN_H
