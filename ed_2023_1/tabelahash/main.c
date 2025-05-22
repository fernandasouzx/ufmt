#include <stdio.h>
#include <stdlib.h>

#include "tab_hash.h"


int main(int argc, char *argv[]){

    tipo_tab_hash minha_tab_hash;
    inicializaTabHash(&minha_tab_hash);
    tipo_no_hash *aux;

    //insereTabHash(&minha_tab_hash, 77, "a");
    //insereTabHash(&minha_tab_hash, 111, "b");
    //insereTabHash(&minha_tab_hash, 9999, "c");
    //insereTabHash(&minha_tab_hash, 22, "d");
    //insereTabHash(&minha_tab_hash, 9, "e");
    insereTabHash(&minha_tab_hash, 1007, "f");

    imprimeTabHash(&minha_tab_hash);
   

    funcaoHash(&minha_tab_hash);
    int ch;
    ch = 7000;
    aux = buscaTabHash(&minha_tab_hash, ch);
    if(aux != NULL){
        printf("Chave %d encontrada: dado = %c\n", ch, aux->valor);
    }else{
        printf("Chave NAO encontrada\n");
    }
    printf("Removido: %c\n", removeTabHash(&minha_tab_hash, 77));

    imprimeTabHash(&minha_tab_hash);

    return EXIT_SUCCESS;
}