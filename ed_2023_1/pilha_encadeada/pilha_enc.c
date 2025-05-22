#include "pilhaenc.h"

void empilha(tipo_no **pl, int valor){
    tipo_no *novo_no;
    novo_no = aloca_no(valor);

    if (novo_no!= NULL){
        novo_no->prox = (*pl);
        (*pl) = novo_no;
    }
}

tipo_no *aloca_no(int valor){
    tipo_no *novo_no;
    novo_no = (tipo_no*) malloc (sizeof(tipo_no));
    if (novo_no!= NULL)
    {
        novo_no -> valor = valor;
        novo_no -> prox = NULL;

    }
    return novo_no;
}


int desempilha(tipo_no **pl){
    
    int valor;
    tipo_no *aux;

    if((*pl) == NULL){
        printf("[ERRO] Pilha vazia.\n");
    }else{
        valor = (*pl)->valor;
        aux = (*pl);
        (*pl) = (*pl)->prox;
        free(aux);
        return valor;
    }
}

void inprimePilhaEnc(tipo_no *pl){

    printf("PILHA:\n\t->");
    while(pl!= NULL){
        printf("[%d]->", pl->valor);
        pl = pl->prox;
    }
    printf("[NULL]\n");
}
