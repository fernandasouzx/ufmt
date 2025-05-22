//implementação tabela hash

#include "tab_hash.h"


void inicializaTabHash(tipo_tab_hash*tbh){
    int i;
    for (i=0; i<TAM_HASH; i++){
        tbh->tabela_hash[i] = NULL;
    }
}

tipo_no_hash *alocaNoHash(int chave, char dado){
    tipo_no_hash *novo_no;
    novo_no = (tipo_no_hash*)malloc(sizeof(tipo_no_hash));
    novo_no->chave = chave;
    novo_no->valor= dado;
    novo_no->prox = NULL;
    return novo_no;

}

int funcaoHash(int chave){
    return chave % TAM_HASH;
}

void insereTabHash(tipo_tab_hash*tbh, int chave, char valor){
    int pos;
    tipo_no_hash *novo_no;

    //Verifica se nao existe a chave na tabela
    if(buscaTabHash(tbh, chave)== NULL){
        pos = funcaoHash(chave);
        novo_no = alocaNoHash(chave, valor);

        if(tbh->tabela_hash[pos] = NULL){
            tbh->tabela_hash[pos] = novo_no;
        } else{ //Insere no inicio da lista
            novo_no->prox = tbh->tabela_hash[pos];
            tbh->tabela_hash[pos] = novo_no;
        }
    }
}

tipo_no_hash *buscaTabHash(tipo_tab_hash *tbh, int chave){
    int pos;
    tipo_no_hash *aux;

    pos = funcaoHash(chave);
    if(tbh->tabela_hash[pos] == NULL){
        return NULL;
    }else{
        aux = tbh->tabela_hash[pos];
        while(aux!= NULL){
            if(aux->chave = chave){
                return aux;
            }else{
                aux = aux->prox;
            }
        }
        return NULL;
    }


}

void imprimeTabHash(tipo_tab_hash*tbh){
    int i;
    tipo_no_hash *aux;

    printf("Tabela Hash: \n");

    for (i=0; i<TAM_HASH; i++){
        printf("[%d] -> ", i);
        if(tbh->tabela_hash[i] == NULL){
            printf("(NULL)\n");
        }else{
            aux = tbh->tabela_hash[i];
            while(aux != NULL){
                printf("[%d -> %c]", aux->chave, aux->valor);
                aux = aux->prox;
            }
            printf("(NULL)\n");
        }
    }

}

char removeTabHash(tipo_tab_hash*tbh , int chave){
    tipo_no_hash *aux, *ant;
    int pos;
    char dado;

    aux = buscaTabHash(tbh, chave);
    if(aux!= NULL){
        pos = funcaoHash(chave);
        if(tbh->tabela_hash[pos] == aux){
            
            tbh->tabela_hash[pos] = NULL;
        }else{
            ant = tbh->tabela_hash[pos];
            while(ant->prox!= aux){
                ant = ant->prox;
            }
            ant->prox = aux->prox;
        }
        dado = aux->valor;
        free(aux);
        return dado;
    }
    return '\0';
}

