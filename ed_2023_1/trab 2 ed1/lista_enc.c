#include "lista_enc.h"
#include <stdio.h>
#include <stdlib.h>


tipo_noh *aloca_noh(int vlr) {
    tipo_noh *novo_noh = (tipo_noh *)malloc(sizeof(tipo_noh));
    if (novo_noh != NULL) {
        novo_noh->prox = NULL;
        novo_noh->valor = vlr;
        return novo_noh;
    } else {
        printf("[Erro] Falha na alocacao de memoria.\n");
        return NULL;
    }
}

void insereInicioLstEnc(tipo_noh **lst, int valor) {
    tipo_noh *novo_noh = aloca_noh(valor);
    if (novo_noh != NULL) {
        novo_noh->prox = (*lst);
        (*lst) = novo_noh;
    } else {
        printf("[Erro] Falha na alocacao de memoria.\n");
    }
}

void insereFimLstEnc(tipo_noh **lst, int valor) {
    tipo_noh *novo_noh = aloca_noh(valor);
    if (novo_noh != NULL) {
        novo_noh->prox = NULL;
        if ((*lst) == NULL) {
            (*lst) = novo_noh;
        } else {
            tipo_noh *aux = (*lst);
            while (aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo_noh;
        }
    } else {
        printf("[Erro] Falha na alocacao de memoria.\n");
    }
}

void inserePosLstEnc(tipo_noh **lst, int vlr, int pos) {
    tipo_noh *novo_noh = aloca_noh(vlr);
    if (novo_noh != NULL) {
        int cont = 0;
        tipo_noh *aux = (*lst), *aux_ant = NULL;
        while (cont < pos && aux != NULL) {
            aux_ant = aux;
            aux = aux->prox;
            cont++;
        }
        if (cont == pos) {
            novo_noh->prox = aux;
            if (aux_ant != NULL)
                aux_ant->prox = novo_noh;
            else
                (*lst) = novo_noh;
        } else {
            free(novo_noh);
            //printf("Posicao invalida.\n");
        }
    } else {
        printf("[Erro] Falha na alocacao de memoria.\n");
    }
}

void salvarEncTxt(char *nome_arq, tipo_noh *lst)
{
    FILE *arq = fopen(nome_arq, "w");
    if (arq == NULL)
    {
        perror("[Erro] Falha ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    while (lst != NULL)
    {
        fprintf(arq, "%d\n", lst->valor);
        lst = lst->prox; // Avança para o próximo nó
    }
    fclose(arq);
}

// Função para contar o número de nós em uma lista encadeada
int contaNosEnc(tipo_noh *lst) 
{
    int count = 0;
    while (lst != NULL) {
        count++;
        lst = lst->prox;
    }
    return count;
}