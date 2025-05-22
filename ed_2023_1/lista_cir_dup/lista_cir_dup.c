#include "lista_cir_dup.h"

tipo_no_dup *aloca_no(int valor){
    tipo_no_dup *novo_no;
    novo_no = (tipo_no_dup*)malloc(sizeof(tipo_no_dup));
    if(novo_no== NULL){
        return NULL;
    }
    novo_no->valor = valor;
    novo_no->prox = NULL;
    novo_no->ant = NULL;
    return novo_no;

}

void insereInicioLstCirDup(tipo_no_dup **lst, int valor){
    tipo_no_dup *novo_no;
    novo_no = aloca_no(valor);

    if(novo_no != NULL){ //verifica se alocacao ocorreu corretamente
        if((*lst) == NULL){
            novo_no->prox = novo_no;
            novo_no->ant = novo_no;
            (*lst) = novo_no;

        } else{
            novo_no->prox = (*lst);
            novo_no->ant = (*lst)->ant;
            (*lst)->ant->prox = novo_no;
            (*lst)->ant = novo_no;
            (*lst) = novo_no;
        }
    }
    //insereFimLstCirDup(lst,valor);
    //(*lst) = (*lst)->ant;
   
}

void insereFimLstCirDup(tipo_no_dup**lst, int valor){
    tipo_no_dup *novo_no;
    novo_no = aloca_no(valor);
    if(novo_no != NULL){
        if((*lst) == NULL){
            novo_no->prox = novo_no;
            novo_no->ant = novo_no;
            (*lst) = novo_no;
        } else{
            novo_no->prox = (*lst);
            novo_no->ant = (*lst)->ant;
            (*lst)->ant->prox = novo_no;
            (*lst)->ant = novo_no;     
        }
    }
}

int removeInicioLstCirDup(tipo_no_dup**lst){
    tipo_no_dup *aux;
    int valor;

    if((*lst) != NULL){
        if((*lst)->prox == (*lst) && (*lst)->ant == (*lst)){
            valor = (*lst)->valor;
            free ((*lst));
            (*lst) = NULL;
            return valor;
        } else{
            aux = (*lst);
            valor = aux->valor;
            (*lst) = (*lst)->prox;
            (*lst)->ant = aux->ant;
            aux->ant->prox = (*lst);
            free(aux);
            return valor;
        }
    }
    return -1;
}

int removeFimLstCirDup(tipo_no_dup**lst){
    tipo_no_dup *aux;
    int valor;

    if((*lst) != NULL){
        if((*lst)->prox == (*lst)){
            valor = (*lst)->valor;
            free ((*lst));
            (*lst) = NULL;
            return valor;
        } else{
            aux = (*lst)->ant;
            valor = aux->valor;
            aux->ant->prox = (*lst);
            (*lst)->ant = aux->ant;
            free(aux);
            return valor;
        }
    }
    return -1;
} 

void imprimeLstCirDup(tipo_no_dup *lst){
    tipo_no_dup *aux;
    printf("Lista CIRCULAR DUPLAMENTE ENCADEADA:\nLIsta-->");
    aux = lst;
    //if(lst != NULL){
        if(aux->prox == aux){
            printf("Lista)<-[%d]->(lista)\n", aux->valor);
        }else{
            printf("<-[%d]->", aux->valor);
            aux = aux->prox;
            while(aux != lst){
                printf("<-[%d]->", aux->valor);
                aux = aux->prox;
            }
            printf("\n");
        }
    //}    
}

/*
void GiraRoleta(tipo_no_dup **lst){
    int direcao, contador;
    if((*lst) != NULL){
        srand(1); //semente fixa
        //srand(time(NULL); //semente base no clock

        //sorteia a dirtecao do giro:1 para direita;0 para a esquerda
        direcao = rand () %2;

        //sorteia a quantidade de passos/deslocamentos
        contador = rand() %100;
        if(direcao == 0){
            printf("Giro para ESQUERDA...");
            printf("\t%d passos...", contador);
            while(contador >0){
                (*lst) = (*lst)->ant;
                contador --;
            }
        }else{//executa o giro para direita
            printf("Giro para DIREITA...");
            printf("\t%d passos...\n", contador);
            while(contador>0){
                (*lst) = (*lst)->prox;
                contador --;
            }
        }
    }
}
*/