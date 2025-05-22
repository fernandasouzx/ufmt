#include "lista_dup.h"

/***
 * @brief Funcao que aloca um novo noh na memória para uma lista duplamente encadeada.
 * 
 * @param vlr Valor a ser inserido.
 * @return tipo_noh_dup* Retorna o enderco do novo noh alocado.
*/
tipo_noh_dup *aloca_noh_dup(int vlr)
{
    tipo_noh_dup *novo_noh_dup;
    novo_noh_dup = (tipo_noh_dup *) malloc(sizeof(tipo_noh_dup));
    if(novo_noh_dup != NULL)
    {
        novo_noh_dup->prox = NULL;
        novo_noh_dup->ant = NULL;
        novo_noh_dup->valor = vlr;
        return novo_noh_dup;
    }
    else
        return NULL;
}

/***
 * @brief Funcao que insere um valor no inicio de uma lista duplamente encadeada
 * 
 * @param lst (tipo_noh_dup **) Ponteiro para a estrutura.
 * @param vlr Valor a ser inserido.
*/

void insereInicioLstDup(tipo_noh_dup **lst, int vlr)
{
    tipo_noh_dup *novo_noh_dup;
    novo_noh_dup = aloca_noh_dup(vlr);
    if(novo_noh_dup != NULL)
    {
        if((*lst) != NULL)
        {
            novo_noh_dup->prox = (*lst);
            (*lst)->ant = novo_noh_dup;
        }
        (*lst) = novo_noh_dup;
    }
    else
        printf("[ERRO] Falha na insercao de valor no inicio.\n");
}

/***
 * @brief Funcao que insere um valor no fim de uma lista duplamente encadeada
 * 
 * @param lst (tipo_noh_dup **) Ponteiro para a estrutura.
 * @param vlr Valor a ser inserido.
*/

void insereFimLstDup(tipo_noh_dup **lst, int vlr)
{
    tipo_noh_dup *novo_noh_dup, *aux;
    novo_noh_dup = aloca_noh_dup(vlr);
    if(novo_noh_dup != NULL)
    {
        aux = (*lst);
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }

        novo_noh_dup ->ant = aux;
        aux->prox = novo_noh_dup;
    }
}

/***
 * @brief Funcao que insere um novo valor em posicao.
 * 
 * @param lst (tipo_noh_dup **) Ponteiro para a estrutura.
 * @param vlr Valor a ser inserido.
 * @param pos Posicao a ser inserida.
*/

void inserePosLstDup(tipo_noh_dup **lst, int vlr, int pos) 
{
    tipo_noh_dup *novo = (tipo_noh_dup*) malloc(sizeof(tipo_noh_dup));
    novo->valor = vlr;
    novo->prox = NULL;
    novo->ant = NULL;

    if (*lst == NULL) {
        *lst = novo;
    } else {
        tipo_noh_dup *aux = *lst;
        int cont = 1;
        while (aux->prox != NULL && cont < pos) {
            aux = aux->prox;
            cont++;
        }
        if (cont == pos) {
            novo->prox = aux;
            novo->ant = aux->ant;
            if (aux->ant != NULL) {
                aux->ant->prox = novo;
            }
            aux->ant = novo;
            if (pos == 1) {
                *lst = novo;
            }
        } else {
            aux->prox = novo;
            novo->ant = aux;
        }
    }
}

void salvarDupEncTxt(char *nome_arq, tipo_noh_dup *lst)
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

// Função para contar o número de nós em uma lista duplamente encadeada
int contaNosDup(tipo_noh_dup *lst) 
{
    int count = 0;
    while (lst != NULL) {
        count++;
        lst = lst->prox;
    }
    return count;
}