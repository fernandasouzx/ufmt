/***
* Função Main
*/
#include<stdio.h>
#include<stdlib.h>

#include "fila_enc.h"


int main(int argc, char *argv[]){

    tipo_no *minha_fila;
    minha_fila = NULL;

    insereFilaEnc(&minha_fila, 7);
    insereFilaEnc(&minha_fila, 1);
    insereFilaEnc(&minha_fila, 20);
    insereFilaEnc(&minha_fila, 3);
    insereFilaEnc(&minha_fila, 9);
    insereFilaEnc(&minha_fila, 10);

    inprimeFilaEnc(minha_fila);
    printf("Valor removido = %d\n", removeFilaEnc(&minha_fila));
    qtdValores(&minha_fila);

    return EXIT_SUCCESS;
}