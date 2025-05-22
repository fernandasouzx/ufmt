#include "lista_dup.h" 
/***
 * @brief Funcao que aloca um novo noh na memória para uma lista duplamente encadeada.
 * 
 * @param dado Linha de dados do dataset a ser inserido.
 * @return tipo_noh_dup* Retorna o enderco do novo noh alocado.
*/
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

/***
 * @brief Funcao que insere um valor no inicio de uma lista duplamente encadeada
 * 
 * @param lst (tipo_noh_dup **) Ponteiro para a estrutura.
 * @param linha Linha de dados do dataset a ser inserido.
*/

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

/***
 * @brief Funcao que remove um valor no inicio da lista.
 * 
 * @param lst (tipo_noh_dup **) Ponteiro para a estrutura.
*/
/*tipo_music_dataset removeInicioLstDup(tipo_noh_dup **lst)
{
    tipo_noh_dup *aux;
    tipo_music_dataset dados;
    if((*lst) != NULL)
    {
        dados = (*lst)->data;
        if((*lst)->prox == NULL)
        {    
            free(*lst);
            (*lst) = NULL;
        }
        else
        {
            aux = (*lst);
            (*lst) = (*lst)->prox;
            (*lst)->ant = NULL;
        }
        return dados;
    }
    else
    {
        return EXIT_FAILURE;
    }
}

void imprimeLstDup(tipo_noh_dup *lst)
{
    printf("Lista duplamente encadeada: \n\t->");
    tipo_noh_dup *aux = (lst);

    if(lst == NULL)
        printf("[Nulo]\n");
    else
    {
        printf("[%d]", lst->valor);
        lst = lst->prox;
    }
    //Imprime os demais
    while(lst != NULL) 
    {
        printf("[%d]", lst->valor);
        lst = lst->prox;
    }
    printf("\n");
}
*/