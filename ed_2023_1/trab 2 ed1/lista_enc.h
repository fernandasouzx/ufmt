#ifndef __LISTA_ENC_H__
#define __LISTA_ENC_H__

struct est_noh
{
    int valor;
    struct est_noh *prox;
};
typedef struct est_noh tipo_noh;

tipo_noh *aloca_noh(int);
void insereInicioLstEnc(tipo_noh **, int);
void insereFimLstEnc(tipo_noh **, int);
void inserePosLstEnc(tipo_noh **, int, int);
void salvarEncTxt(char *, tipo_noh *);
int contaNosEnc(tipo_noh *);
#endif
