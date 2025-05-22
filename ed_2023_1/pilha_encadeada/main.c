#include "pilhaenc.h"

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

    tipo_no *minha_pilha;
    minha_pilha = NULL;


    empilha(&minha_pilha, 1);
    empilha(&minha_pilha, 7);
    empilha(&minha_pilha, 3);
    empilha(&minha_pilha, 2);
    empilha(&minha_pilha, 5);
    empilha(&minha_pilha, 8);
    empilha(&minha_pilha, 4);
    empilha(&minha_pilha, 6);
    empilha(&minha_pilha, 9);
    empilha(&minha_pilha, 0);


    inprimePilhaEnc(minha_pilha);
    printf("\nValor Removido = %d\n\n", desempilha(&minha_pilha));
    inprimePilhaEnc(minha_pilha);
    return EXIT_SUCCESS;
}
