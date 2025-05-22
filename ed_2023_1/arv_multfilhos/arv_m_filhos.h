

#ifndef __ARV_M_FILHOS_H__
#define __ARV_M_FILHOS_H__

#include<stdio.h>
#include<stdlib.h>

#define T 3 //Define capacidade do noh da arvore

//Definicao da estrutura
struct est_arv_m_f {
    int dados[T];
    struct est_arv_m_f *filhos[T+1];
    int cont;
};
typedef struct est_arv_m_f tipo_arv_m_f;

//Prototipo das funcoes
tipo_arv_m_f *alocaNoArvMF(int);
void insereArvMF(tipo_arv_m_f**, int);
int buscaArvMF(tipo_arv_m_f*, int);
void percursoPreOrdemArvMF(tipo_arv_m_f*);
void percursoPosOrdemArvMF(tipo_arv_m_f*);
void percursoOrdemArvMF(tipo_arv_m_f*);
int contabilizaValoresArvMF(tipo_arv_m_f*);
int contabilizaFolhasArvMF(tipo_arv_m_f*);
int contabilizaNosArvMF(tipo_arv_m_f*);
int alturaArvMF(tipo_arv_m_f*);
void imprimeNivelArvMF(tipo_arv_m_f*, int);
int maiorValorArvMF(tipo_arv_m_f*);
int menorValorArvMF(tipo_arv_m_f*);
int ehFolha(tipo_arv_m_f*);
int buscaFilhoProximo(tipo_arv_m_f*, int);
void removeArvMF(tipo_arv_m_f**, int);

#endif //ARV_M_FILHOS_H__
