/***
* Implementação da Fila Encadeada
*/
#include <stdio.h> 
#include <stdlib.h>
#include "fila_enc.h"


tipo_no *aloca_novo_no(int vl){
    tipo_no *novo_no;
    novo_no = (tipo_no*) malloc(sizeof(tipo_no));
    if (novo_no != NULL) { //Se alocacao de memoria ocorreu normalmente
        novo_no->valor = vl;
        novo_no->prox = NULL;
    } else { //Caso tenha ocorrido falha na alocacao de memoria
        printf("[ERRO] Falha na alocacao de memoria para um novo noh\n");
    }
    return novo_no;
}
void insereFilaEnc(tipo_no **fila, int vl){
    tipo_no *novo_no, *aux;
    novo_no = aloca_novo_no(vl);
    if (novo_no != NULL) {
        if ( (*fila) == NULL ) { //Se fila estah vazia
            (*fila) = novo_no;
        } else { //Percorre estrutura buscando o ultimo elemento
            aux = (*fila);
            while (aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo_no;
        }
    }
}


int removeFilaEnc(tipo_no **fila){
    tipo_no *aux;
    int vl;

    if ((*fila) != NULL) { //Se fila tem valor, remove e retorna valor
        vl = (*fila)->valor;
        aux = (*fila);
        (*fila) = (*fila)->prox;
        free(aux);
        return vl;
    } else { //Se fila estah vazia
        return -1;
    }
}

void inprimeFilaEnc(tipo_no *fila){
 printf("Fila->");
    while (fila != NULL) {
        printf("[%d]->", fila->valor);
        fila = fila->prox;
    }
    printf("NULO\n");
}

int qtdValores(tipo_no *fila){
    int qtd;
    qtd = 0;
    printf("antes de entrar no while");
    while (fila == NULL){
        printf("entrou no while");
        
        fila = fila->prox; 
        qtd++;
    }
    
    return qtd;
    printf("saiu do laço");
}