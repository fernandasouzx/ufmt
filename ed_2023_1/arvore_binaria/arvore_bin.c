/*
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 *
 * Disciplina de ED I
 * Prof. Ivairton
 * Aluna: Fernanda Lima de Souza
 *
 * Implementação do cabeçalho ARVORE.C
 */

#include "arvore_bin.h"

tipo_no_arv *alocaNo(char letra, int chave){
    tipo_no_arv *no = (tipo_no_arv *)malloc(sizeof(tipo_no_arv));
    no->letra = letra;
    no->chave = chave;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

void insere(tipo_no_arv **no, char letra, int chave){
    if ((*no) == NULL){
        (*no) = alocaNo(letra, chave);
    }
    else{
        if (chave < (*no)->chave){
            insere(&(*no)->esq, letra, chave);
        }
        else{
            insere(&(*no)->dir, letra, chave);
        }
    }
}

void percursoPreOrdem(tipo_no_arv *no){
    if (no != NULL){
        printf("[%d] [%c] ", no->chave, no->letra);
        percursoPreOrdem(no->esq);
        percursoPreOrdem(no->dir);
    }
}

void percursoPosOrdem(tipo_no_arv *no){
    if (no != NULL){
        percursoPosOrdem(no->esq);
        percursoPosOrdem(no->dir);
        printf("[%d] [%c] ", no->chave, no->letra);
    }
}

void percursoOrdem(tipo_no_arv *no){
    if (no != NULL){
        percursoOrdem(no->esq);
        printf("[%d] [%c] ", no->chave, no->letra);
        percursoOrdem(no->dir);
    }
}

int buscachave(tipo_no_arv *no, int chave){
    if (no != NULL){
        if (chave == no->chave){
            return 1;
        }

        if (chave <  no->chave){

            return buscachave(no->esq, chave);
        }
        else{
            return buscachave(no->dir, chave);
        }

        printf("chave %d encontrado na noore.\n", chave);
    }
    return 0;
}

// Calcula a altura da árvore binária
int altura(tipo_no_arv *no){
  
    int alt_esq, alt_dir;

    // Verifica se o nó é NULL (caso base da recursão)
    if (no == NULL) {
        return -1; // Retorna -1 para indicar que a altura de um nó NULL é -1
    }

    // Verifica a altura do ramo esquerdo
    if (no->esq == NULL) {
        alt_esq = 0; // Não há filho à esquerda
    } else {
        alt_esq = altura(no->esq); // Recursivamente calcula a altura do filho esquerdo
    }

    // Verifica a altura do ramo direito
    if (no->dir == NULL) {
        alt_dir = 0; // Não há filho à direita
    } else {
        alt_dir = altura(no->dir); // Recursivamente calcula a altura do filho direito
    }

    // Retorna a altura máxima entre os ramos esquerdo e direito, mais 1 para incluir o próprio nó
    return (alt_esq > alt_dir) ? alt_esq + 1 : alt_dir + 1;
}

// Imprime os chavees alocados em cada nível da árvore

void imprimeNivel(tipo_no_arv *arv, int nivel){
    if (arv != NULL)
    {
        if (nivel == 0){
            printf("\tNO: %d\n", arv->chave);
        }
        else{
            imprimeNivel(arv->esq, nivel - 1);
            imprimeNivel(arv->dir, nivel - 1);
        }
    }
}


int contagem(tipo_no_arv *arv){
    // criterio de parada, nó nulo
    if (arv == NULL){
        return 0;
    }
    else{
        return contagem(arv->esq) +
               contagem(arv->dir) +
               1;
    }
} 

int maiorchaveArv(tipo_no_arv *no){
    if (no != NULL){
        if (no->dir == NULL){
            return no->chave;
        }
        else{
            return maiorchaveArv(no->dir);
        }
    }
}

int menorchaveArv(tipo_no_arv *no)
{
    if (no != NULL)
    {
        if (no->esq == NULL)
        {
            return no->chave;
        }
        else
        {
            return menorchaveArv(no->esq);
        }
    }
    return -1;
} 


/*void removeArvBin(tipo_no_arv **no, int chave){
    tipo_no_arv *aux;

    // encontra o no a ser removido
    if ((*no) != NULL){

        if ( (*no)->chave != chave){ // se diferentes:

            if (chave < (*no)->chave){ //se chave maior, desce pela esq
                removeArvBin( &(*no)->esq, chave);
            }
            else{ // se chave maior, desce pela dir
                removeArvBin(& (*no)->dir, chave);
            }

        } else{ //chave é igual, foi encontrado
            
            //verifica caso 1: no é folha
            if ( ((*no)->esq == NULL) && ((*no)->dir == NULL)){
                //desaloca 
                free(*no);
                (*no) = NULL;

            }   
          
            else if(
                ( (*no)->esq == NULL && (*no)->dir != NULL) ||
                ( (*no)->esq != NULL && (*no)->dir == NULL)
                ) {

            //verifica qual filho existente
            aux = (*no);
        
            if ((*no)->esq != NULL)
                (*no) = aux->esq;
            
            else if ((*no)->dir != NULL)
                (*no) = aux->dir;
            
            free(aux);
        

        }   else if ( ((*no)->esq != NULL) && ( (*no)->dir != NULL) ) {
                int novo_chave;

                novo_chave = maiorchaveArv( (*no)->esq);
                (*no)->chave = novo_chave;
                removeArvBin(& (*no)->esq, novo_chave);
            }
            
    
        }
    }
}

*/