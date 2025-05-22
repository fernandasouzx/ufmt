#include "lista_enc.h"
#include <stdio.h>
#include <stdlib.h>


tipo_no *aloca_no(vl){
    tipo_no *novo_no;
    novo_no = (tipo_no*) malloc(sizeof(tipo_no));
    novo_no->valor= vl;
    novo_no->prox = NULL;
    return novo_no;
}

void insereInicio(tipo_no **lst, int vl){
    tipo_no *novo_no;
    novo_no = aloca_no(vl);
    novo_no->prox=(*lst);
    (*lst)= novo_no;
}

void insereFim(tipo_no **lst, int vl){

    tipo_no *novo_no;
    novo_no = aloca_no(vl);
    if ((*lst) == NULL){
        (*lst) = novo_no;
    }else{
        tipo_no *aux;
        aux = (*lst);
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo_no;
    }
}

void removeInicio(tipo_no **lst){
    tipo_no *aux;
    int vl;

    if((*lst)!= NULL){
        aux= (*lst);
        vl = (*lst)->valor;
        (*lst) = (*lst)->prox;
        free(aux);
        return vl;
    }else{
        return -1;
    }
}


void removePosicao(tipo_no **lst){

}

void imprimeLista();

//funcao principal

int main(){
    tipo_no *minha_lista;
}
