// Implementação de LISTA_CIR_H
#include "lista_cir.h"

tipo_no *aloca_no(int vl)
{
    tipo_no *novo_no;
    novo_no = (tipo_no *)malloc(sizeof(tipo_no));

    if (novo_no != NULL)
    {
        novo_no->valor = vl;
        novo_no->prox = NULL;
        return novo_no;
    }
    return NULL;
}

void insereFimLstCir(tipo_no **lst, int vl)
{
    if ((*lst) == NULL)
    {
        (*lst) = aloca_no(vl);
        (*lst)->prox = (*lst);
    }
    else
    {
        tipo_no *novo_no, *aux;
        novo_no = aloca_no(vl);
        aux = (*lst);

        while (aux->prox != (*lst))
        {
            aux = aux->prox;
        }
        aux->prox = novo_no;
        novo_no->prox = (*lst);
    }
}

void insereInicioLstCir(tipo_no **lst, int vl)
{
    tipo_no *novo_no, *aux;

    novo_no = aloca_no(vl);
    novo_no->prox = (*lst);

    aux = (*lst);
    while ((aux->prox) != (*lst))
    {
        aux = aux->prox;
    }
    aux->prox = novo_no;
    (*lst) = novo_no;
}

int removeFimLstCir(tipo_no **lst){
    int valor;
    tipo_no *aux, *aux_ant;

    if((*lst) != NULL){ //verifica se a lista tem valor
        if ((*lst) ->prox == (*lst)){ //verifica se a lista tem apenas um nó
            valor = (*lst)-> valor;
            free(*lst);
            return valor;
        }else{ //caso tenha mais de um valor
            aux=(*lst);
            while(aux->prox != (*lst)){
                aux_ant = aux;
                aux = aux->prox;
        
            }
            valor = aux->valor;
            aux_ant->prox = aux->prox;
            free(aux);
            return valor;
        } 
    }
    return -1;
}



int removeInicioLstCir(tipo_no **lst){
    int valor;
    tipo_no *aux;

    if((*lst)!=NULL){ //verifica se a lista tem valor
         if((*lst)->prox == (*lst)){
            valor = (*lst)->valor;
            free (*lst);
            (*lst) = NULL;
            return valor;

         }else{ //caso tenha mais que um valor
            valor = (*lst)->valor;
            // atualiza ponteiro prox do ultimo no
            aux = (*lst);
            while(aux->prox != (*lst)){
                aux = aux->prox;
            }  
            aux->prox = (*lst)->prox;
            //aponta para o no a ser desalocado e atualiza a lista
            aux = (*lst);
            (*lst) = (*lst)->prox;
            free(aux);
            return valor;
        }
    }
    return -1;
}



void imprimeLstCir(tipo_no *lst)
{
    tipo_no *aux;

    printf("Lista Circular:\n\t->");
    // Imprime o primeiro no
    if (lst == NULL)
        printf("[NULL]");

    else
    {
        printf("[%d]", lst->valor);
        aux = lst->prox;
    }
    while (aux != lst)
    {
        printf("->[%d]->", aux->valor);
        aux = aux->prox;
    }
}
