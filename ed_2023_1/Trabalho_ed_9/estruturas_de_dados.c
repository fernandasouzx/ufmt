#include "estruturas_de_dados.h" 

/**
 * @brief Funcao que aloca um novo noh na memória para uma lista duplamente encadeada.
 * 
 * @param dado Registro de dados do dataset a ser inserido na lista duplamente encadeada.
 * @return tipo_noh_dup* Retorna o enderco do novo noh alocado.
**/
tipo_noh_dup *aloca_noh(tipo_music_dataset dado)
{
    tipo_noh_dup *novo_noh;
    novo_noh = (tipo_noh_dup *) malloc(sizeof(tipo_noh_dup));
    if(novo_noh != NULL)
    {
        novo_noh->prox = NULL;
        novo_noh->ant = NULL;
        novo_noh->data = dado;
        return novo_noh;
    }
    else
        return NULL;
}

/**
 * @brief Funcao que insere um valor no inicio de uma lista duplamente encadeada
 * 
 * @param lst (tipo_noh_dup **) Ponteiro para a estrutura.
 * @param linha Linha de dados do dataset a ser inserido.
**/


tipo_noh_lst_enc *aloca_noLst (tipo_music_dataset dadoLst)
{
    tipo_noh_lst_enc *novo_noh;
    novo_noh = (tipo_noh_lst_enc *)malloc(sizeof(tipo_noh_lst_enc));
    if(novo_noh != NULL)
    {
        novo_noh->dataListaEnc = dadoLst;
        novo_noh->prox = NULL;
    }
    return novo_noh;
}

/**
 * @brief Funcao que aloca um novo noh na memória para uma lista encadeada.
 * 
 * @param dadoLst Registro de dados do dataset a ser inserido na lista encadeada.
 * @return tipo_noh_lst_enc* Retorna o endereco do novo noh alocado.
**/

void insereLstDup(tipo_noh_dup **lst, tipo_music_dataset linha)
{
    tipo_noh_dup *novo_noh;
    novo_noh = aloca_noh(linha);
    if(novo_noh != NULL)
    {
        if((*lst) != NULL)
        {
            novo_noh->prox = (*lst);
            (*lst)->ant = novo_noh;
        }
        (*lst) = novo_noh;
    }
    else
        printf("[ERRO] Falha na insercao.\n");
}


/**
 * @brief Funcao que aloca um novo noh na memória para uma lista  encadeada.

 * @param dado Registro de dados do dataset a ser inserido na lista encadeada.
 * @return tipo_noh_lst_enc* Retorna o enderco do novo noh alocado.
**/

void insereLstEnc(tipo_noh_lst_enc **lst, tipo_music_dataset dado)
{
    tipo_noh_lst_enc *novo_noh;
    novo_noh = aloca_noLst(dado);
    if(novo_noh != NULL)
    {
        novo_noh->prox = (*lst);
        (*lst) = novo_noh;
    }
    else
    {
        printf("[Error] Nao foi possivel inserir na lista encadeada.\n");
    }
}
/**
 * @brief Funcao que aloca um novo noh na memória para uma lista circular duplamente encadeada.
 * 
 * @param dadoCirc Registro de dados do dataset a ser inserido na lista circular duplamente encadeada.
 * @return tipo_noh_circ_dup* Retorna o endereco do novo noh alocado.
**/


tipo_noh_circ_dup *alocaNohCircDup(tipo_music_dataset dadoCirc)
{
    tipo_noh_circ_dup *novoNoh;
    novoNoh = (tipo_noh_circ_dup*) malloc(sizeof(tipo_noh_circ_dup));
    if(novoNoh != NULL)
    {
        novoNoh->dataCirc = dadoCirc;
        novoNoh->prox = NULL;
        novoNoh->ant = NULL;
        return novoNoh;
    }
    else
        return NULL;
}

/**
 * @brief Funcao que aloca um novo noh na memória para uma lista circular duplamente encadeada.
 * 
 * @param circ Ponteiro para o ponteiro do primeiro noh da lista circular duplamente encadeada.
 * @param dado Registro de dados do dataset a ser inserido na lista circular duplamente encadeada.
 * @return tipo_noh_circ_dup* Retorna o endereço do novo noh alocado.
**/


void insereCircDup(tipo_noh_circ_dup** circ, tipo_music_dataset dado)
{
    tipo_noh_circ_dup *novo_noh;
    novo_noh = alocaNohCircDup(dado);
    if(novo_noh != NULL)
    {
        if((*circ) == NULL)
        {
            novo_noh->prox = novo_noh;
            novo_noh->ant = novo_noh;
            (*circ) = novo_noh;
        }
        else
        {
            novo_noh->prox = (*circ)->prox;
            novo_noh->ant = (*circ);
            (*circ)->prox->ant = novo_noh;
            (*circ)->prox = novo_noh;
        }
    }
    else
        printf("[ERRO] Falha na insercao de valor no inicio.\n");
} 

