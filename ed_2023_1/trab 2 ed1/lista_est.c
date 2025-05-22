#include "lista_est.h"

/**
 * @brief Funcao que insere no inicio da lista.
 * 
 * @param tipo_lista *lista - Estrutura da lista
 * @param int valor - valor a ser inserido na lista
 * 
 * @return int - verdadeiro se insercao com sucesso, falso caso contrário
 */
int insere_inicio_lista(tipo_lista *lst, int valor) {
    int pos;
    if (lst->contador < N) {
        pos = lst->contador;
        while (pos > 0) {
            lst->lista[pos] = lst->lista[pos-1];
            pos--;
        }
        lst->lista[0] = valor;
        lst->contador++;
        return lst->contador;
    } else {
        return 0;
    }
}

/**
 * @brief Funcao que insere o novo valor no fim da lista.
 * 
 * @param tipo_lista *lst - Estrutura da Lista 
 * @param int valor - Valor a ser inserido
 * @return int - verdadeiro se insercao com sucesso, falso caso contrario
 */
int insere_fim_lista(tipo_lista *lst, int valor) 
{
    if (lst->contador < N) {
        lst->lista[lst->contador++] = valor;
        return 1;

    }
    return 0;
}

/**
 * @brief Funcao que insere o novo valor em uma determinada posição na lista.
 * 
 * @param tipo_lista *lst - Estrutura da Lista 
 * @param int num - Valor a ser inserido
 * @param int pos - Posicao na lista
 * @return int - verdadeiro se insercao com sucesso, falso caso contrario
 */
int insere_pos_lista(tipo_lista* lst, int num, int pos)
{   
    if(pos < 0 || pos > lst->contador || lst->contador >= N)
        return 0;
    
    for(int i = lst->contador; i > pos; i--)
    {
        lst->lista[i] = lst->lista[i-1];
    }
    lst->lista[pos] = num;
    lst->contador++;
    return 1;
}

void salvarEstTxt(char *nomeArq, tipo_lista *lst)
{
    FILE *file = fopen(nomeArq, "w");
    if(file == NULL)
    {
        perror("[Erro] Falha ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < N; i++)
        fprintf(file, "%d\n", lst->lista[i]);
    fclose(file);
}