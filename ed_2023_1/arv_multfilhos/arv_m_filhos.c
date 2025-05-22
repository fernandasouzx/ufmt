
//Implementacao de ARV_M_FILHOS.H
#include "arv_m_filhos.h"

/**
 * @brief Funcao que aloca um novo noh.
 * 
 * @param vl Primeiro valor a ser inserido no novo noh
 * @return tipo_arv_m_f* Retorna referencia para o novo noh criado 
 */
tipo_arv_m_f *alocaNoArvMF(int vl) {
    tipo_arv_m_f *novo_no;
    int i;
    novo_no = (tipo_arv_m_f*) malloc(sizeof(tipo_arv_m_f));
    //inicializa componentes do novo no
    novo_no->cont = 0;
    for (i=0; i<T+1; i++)
        novo_no->filhos[i] = NULL;
    //insere valor no novo noh    
    novo_no->dados[novo_no->cont++] = vl;

    return novo_no;
}

/**
 * @brief Funcao que insere um novo valor na arvore.
 * 
 * @param arv (tipo_arv_m_f**) Referencia para a estrutura.
 * @param vl Valor a ser inserido na arvore.
 */
void insereArvMF(tipo_arv_m_f **arv, int vl) {
    int i;

    //Verifica se arvore eh nula
    if ( (*arv) == NULL ) {
        (*arv) = alocaNoArvMF(vl);
    } else { //Caso o noh exista, verifica as situacoes:
        //Verifica se o noh tem espaco para insercao
        if ( (*arv)->cont < T) {
            //insere ordenado
            i = (*arv)->cont-1;
            while ( (i >= 0) && (vl < (*arv)->dados[i]) ) {
                (*arv)->dados[i+1] = (*arv)->dados[i];
                i--;
            }
            (*arv)->dados[i+1] = vl;
            (*arv)->cont++;
        } else { //Se nao tem espaco, busca pelo filho a descer
            //identifica filho e faz chamada recursiva
            i = 0;
            while ( (i < T) && (vl > (*arv)->dados[i]) )
                i++;
            insereArvMF(&(*arv)->filhos[i], vl);
        }
    }
}

/**
 * @brief Funcao que busca um valor na estrutura da arvore 
 *      com multiplos filhos.
 * 
 * @param arv Referencia para a arvore
 * @param vl Valor a ser buscado
 * @return int Verdadeiro/falso para o caso do valor ser encontrado/ou nao
 */
int buscaArvMF(tipo_arv_m_f *arv, int vl) {
    int i;
    if (arv != NULL) { //Verifica se noh nao eh vazio
        i = 0;
        while ( (arv->dados[i] < vl) && (i < T) )
            i++;
        if ( (i < T) && (arv->dados[i] == vl) )
            return 1; //Valor encontrado
        else //valor ainda nao encontrado, desce no filho correspondente
            return buscaArvMF(arv->filhos[i], vl);
    } else { //Caso noh seja vazio, valor nao foi encontrado
        return 0;
    }
}

/**
 * @brief Funcao que imprime a arvore por meio do percurso PRE ordem
 * 
 * @param arv Referencia para a arvore.
 */
void percursoPreOrdemArvMF(tipo_arv_m_f *arv) {
    int i;
    if (arv != NULL) {
        //Imprime valores
        for (i=0; i<arv->cont; i++)
            printf("%d ", arv->dados[i]);
        //Realiza chamada recursiva nos filhos
        for (i=0; i<=arv->cont; i++) //Pode usar T como criterio de parada
            percursoPreOrdemArvMF(arv->filhos[i]);
    }
}

/**
 * @brief Funcao que imprime a arvore por meio do percurso POS ordem
 * 
 * @param arv Referencia para a arvore.
 */
void percursoPosOrdemArvMF(tipo_arv_m_f *arv) {
    int i;
    if (arv != NULL) {
        //Realiza chamada recursiva nos filhos
        for (i=0; i<=arv->cont; i++) //Pode usar T como criterio de parada
            percursoPosOrdemArvMF(arv->filhos[i]);
        //Imprime valores
        for (i=0; i<arv->cont; i++)
            printf("%d ", arv->dados[i]);
    }
}

/**
 * @brief Funcao que imprime a arvore por meio do percurso ORDEM
 * 
 * @param arv Referencia para a arvore.
 */
void percursoOrdemArvMF(tipo_arv_m_f *arv) {
    int i;
    if (arv != NULL) {
        //Intercala chamada recursiva do filho aa esquerda e do valor.
        for (i=0; i<arv->cont; i++) {//Pode usar T como criterio de parada
            percursoOrdemArvMF(arv->filhos[i]);
            printf("%d ", arv->dados[i]);
        }
        //Faz a chamada para o ultimo filho (mais aa direita), que ficou faltando
        percursoOrdemArvMF(arv->filhos[i]);
    }
}

/**
 * @brief Funcao que contabiliza o total de valores na arvore
 * 
 * @param arv Referencia para a arvore
 * @return int Total de valores (contabilizado)
 */
int contabilizaValoresArvMF(tipo_arv_m_f *arv) {
    int total, i;
    total = 0;
    if (arv != NULL) {
        for (i=0; i <= arv->cont; i++)
            total += contabilizaValoresArvMF(arv->filhos[i]);
        total += arv->cont;
    }
    return total;
}

/**
 * @brief FUncao que contabiliza o tatal de nohs que sao folhas
 * 
 * @param arv Referencia para a arvore
 * @return int Total de nohs folha (contabilizado)
 */
int contabilizaFolhasArvMF(tipo_arv_m_f *arv) {
    int i, flag;
    if (arv != NULL) {
        flag = 0;
        for (i=0; i <= arv->cont; i++)
            flag += contabilizaFolhasArvMF(arv->filhos[i]);

        if (flag == 0)
            return 1;
        else
            return flag;
    }
    return 0;
}

/**
 * @brief Funcao que calcula a quantidade noh na arvore
 * 
 * @param arv Referencia para a arvore
 * @return int Quantidade de nohs da arvore
 */
int contabilizaNosArvMF(tipo_arv_m_f *arv) {
    int i, contador;
    if (arv == NULL)
        return 0;
    else 
        contador = 0;
        for (i=0; i <= arv->cont; i++)
            contador += contabilizaNosArvMF(arv->filhos[i]);
        return contador + 1;
}

/**
 * @brief Funcao que calcula a altura da arvore
 * 
 * @param arv Referencia para a arvore
 * @return int valor da altura
 */
int alturaArvMF(tipo_arv_m_f *arv) {
    int i, maior, h_atual;
    
    if (arv == NULL)
        return -1;
    else {
        maior = alturaArvMF(arv->filhos[0]); //Pega a altura do filho 0
        for (i=1; i<=arv->cont; i++) {
            h_atual = alturaArvMF(arv->filhos[i]);
            if (h_atual > maior)
                maior = h_atual;
        }
        return maior + 1;
    }
}

/**
 * @brief Funcao que impri
 * 
 * @param arv Referencia para a arvore
 * @param nvl Valor do nivel a ser impresso 
 */
void imprimeNivelArvMF(tipo_arv_m_f *arv, int nvl) {
    int i;
    if (arv != NULL) {
        if (nvl == 0) {
            printf("[");
            for (i=0; i<arv->cont; i++)
                printf("%d ",arv->dados[i]);
            printf("]");
        } else {
            for (i=0; i<=arv->cont; i++)
                imprimeNivelArvMF(arv->filhos[i], nvl-1);
        }
    }
}

/**
 * @brief Funcao que identifica o maior valor da arvore
 * 
 * @param arv Referencia para a arvore
 * @return int Valor correspondente ao maior valor registrado.
 */
int maiorValorArvMF(tipo_arv_m_f *arv) {
    if (arv->filhos[arv->cont] == NULL) //verifica se o maior valor tem filho direito
        return arv->dados[arv->cont-1];
    else
        return maiorValorArvMF(arv->filhos[arv->cont]);
}

/**
 * @brief Funcao que identifica o menor valor da arvore
 * 
 * @param arv Referencia para a arvore
 * @return int Valor correspondente ao menor valor registrado.
 */
int menorValorArvMF(tipo_arv_m_f *arv) {
    if (arv != NULL) {
        if (arv->filhos[0] == NULL)
            return arv->dados[0];
        else {
            return menorValorArvMF(arv->filhos[0]);
        }
    }
    return 0;
}

/**
 * @brief Funcao que verifica se um noh eh folha.
 * 
 * @param arv Referencia para a estrutura
 * @return int Retorna verdadeiro/falso caso seja folha/ou nao.
 */
int ehFolha(tipo_arv_m_f *arv) {
    int i, flag;
    flag = 1; //Parte do principio que o noh eh folha
    i = 0;
    do {
        if (arv->filhos[i] != NULL) //se tem filho, nao eh folha
            flag = 0;
        i++;
    } while (i <= arv->cont);
    return flag;
}

/**
 * @brief Funcao que remove um valor da arvore com multiplos filhos
 *          A funcao trata as seguintes situacoes:
 *             - Eh folha:
 *                  - tem mais de um valor, remove e mantem ordenacao
 *                  - ultimo valor, desaloca memoria e atualiza ponteiro do pai
 *              - Nao eh folha:
 *                  - valor tem um dos filhos, encontra valor adequado e substitui
 *                  - nao tem filhos, identifica lado com filho mais proximo, reposiciona valores e encontra valor para substiuir
 * 
 * @param arv Referencia para estrutura
 * @param vl Valor a ser removido
 */
void removeArvMF(tipo_arv_m_f **arv, int vl) {
    int i, novo_vl, idx_filho;
    if ((*arv) != NULL) {
        i = 0;
        //Busca pelo valor
        while ( (i < (*arv)->cont) && ((*arv)->dados[i] < vl) ) {
            i++;
        }
        //Se valor encontrado
        if ( (i < (*arv)->cont) && ((*arv)->dados[i] == vl) ) {
            //Verifica se noh eh folha
            if ( ehFolha((*arv)) ) {
                //Verifica se tem mais de um valor
                if ( (*arv)->cont > 1 ) {
                    //Reposiciona valores, removendo o valor da posicao i
                    for ( ; i < (*arv)->cont-1; i++ )
                        (*arv)->dados[i] = (*arv)->dados[i+1];
                    (*arv)->cont--; //decrementa contador
                } else {
                    free( (*arv) ); //Libera noh da memoria
                    (*arv) = NULL; //Atualiza ponteiro do pai
                }
            } else { // Caso NAO seja folha, seja um noh intermediario
                //Verifica se o valor tem filho esquerdo
                if ( (*arv)->filhos[i] != NULL ) {
                    novo_vl = maiorValorArvMF((*arv)->filhos[i]);
                    (*arv)->dados[i] = novo_vl;
                    removeArvMF(&(*arv)->filhos[i], novo_vl);
                } else //Verifica se o valor tem filho direito
                  if ( (*arv)->filhos[i+1] != NULL ) {
                     novo_vl = menorValorArvMF((*arv)->filhos[i+1]);
                     (*arv)->dados[i] = novo_vl;
                     removeArvMF(&(*arv)->filhos[i+1], novo_vl);  
                } else { //Entao o valor nao tem filho
                    idx_filho = buscaFilhoProximo((*arv), i); //encontra posicao do filho
                    //Verifica se filho estah aa esquerda
                    if (idx_filho < i) {
                        while (i > idx_filho) { //Reposiciona valores
                            (*arv)->dados[i] = (*arv)->dados[i-1];
                            i--;
                        }
                        //Encontra maior valor no idx do filho (esquerdo)
                        novo_vl = maiorValorArvMF((*arv)->filhos[idx_filho]);
                        (*arv)->dados[i] = novo_vl; //Atualiza valor
                        removeArvMF(&(*arv)->filhos[idx_filho], novo_vl); //Chamada recursiva
                    } else { //senao, filho estah aa direita
                        while (i < idx_filho-1) { //Reposiciona valores
                            (*arv)->dados[i] = (*arv)->dados[i+1];
                            i++;
                        }
                        //Encontra menor valor no idx do filho
                        novo_vl = menorValorArvMF( (*arv)->filhos[idx_filho] );
                        (*arv)->dados[i] = novo_vl; //atualiza valor
                        removeArvMF(&(*arv)->filhos[idx_filho], novo_vl); //Chamada recursiva
                    }
                }
            }
        } else { // Se valor não encontrado na busca, faz chamada recursiva
            removeArvMF(&(*arv)->filhos[i], vl);
        }
    }
}

/**
 * @brief Funcao que busca pela posicao do filho mais proximo
 *          do indice informado no parametro.
 * 
 * @param arv Referencia para a estrutura
 * @param idx Indice do valor usado como posicao de referencia
 * @return int Retorna o indice da posicao do filho mais proximo
 */
int buscaFilhoProximo(tipo_arv_m_f *arv, int idx) {
    int i, cont_esq, cont_dir;
    //Verifica filho mais proximo aa esquerda
    cont_esq = 0;
    for (i=idx; ( (i > 0) && (arv->filhos[i] == NULL) ); i--)
        cont_esq++;
    //Confere se de fato tem o filho
    if( arv->filhos[i] == NULL )
        cont_esq = T*T; //Define uma penalidade para garantir a nao escolha deste lado
    
    //Verifica filho mais proximo aa direitra
    cont_dir = 0;
    for (i=idx; ( (i < T) && (arv->filhos[i] == NULL) ); i++)
        cont_dir++;
    //Confere se de fato tem o filho
    if ( arv->filhos[i] == NULL)
        cont_dir = T * T; //Definie penalidade

    //Verifica qual lado tem o filho mais proximo
    if (cont_esq < cont_dir)
        return idx-cont_esq;
    else
        return idx+cont_dir;
}
