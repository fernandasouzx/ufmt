#include <stdio.h>
#include <stdlib.h>

struct est_no{
    int valor;
    struct est_no *prox;

}; typedef struct est_no tipo_no;



tipo_no *aloca_no(int );
void insereInicio(tipo_no **, int);
void insereFim(tipo_no **, int);
void removeInicio(tipo_no **);
void removeFim(tipo_no **);





