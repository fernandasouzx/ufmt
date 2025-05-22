#include "lista.h"

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

int insere_pos_lista(tipo_lista *lst, int valor, int pos) {
    int i;
    if (lst->contador < N) {
        i = lst->contador;
        while (i > pos) {
            lst->lista[i] = lst->lista[i-1];
            i--;
        }
        lst->lista[pos] = valor;
        lst->contador++;
        return 1;
    } else {
        return 0;
    }
}

int encontrapos(int vet[], int tam, int valor  ){
    int i = 0;
    while(i<tam){
        if(valor>vet[i]){
            i++;
        } else{
            return i;
        }
    }
}

int insere_fim_lista(tipo_lista *lst, int valor) {
    if (lst->contador < N) {
        lst->lista[lst->contador++] = valor;
        return 1;
    }
    return 0;
}
void imprime_lista(tipo_lista lst) {
    int i;
    printf("Quantidade de elementos da lista = %d\n", lst.contador);
    printf("Lista: [ ");
    for (i=0; i<lst.contador; i++)
        printf("%d ", lst.lista[i]);
    printf("]\n");
}

/*
int insere_pos_lista(tipo_lista*, int, int);
int remove_inicio_lista(tipo_lista*);
int remove_fim_lista(tipo_lista*);
int remove_pos_lista(tipo_lista*, int);
int remove_valor_lista(tipo_lista*, int);
int busca_pos_lista(tipo_lista, int);
int busca_valor_lista(tipo_lista, int);
int busca_maior_lista(tipo_lista);
int busca_menor_lista(tipo_lista);
*/
