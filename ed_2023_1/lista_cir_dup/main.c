#include <stdio.h>
#include <stdlib.h>

#include "lista_cir_dup.h"


int main(int argc, char *argv[]){

    tipo_no_dup *minha_lista_cir_dup;
    minha_lista_cir_dup = NULL;


    insereInicioLstCirDup(&minha_lista_cir_dup, 1);
    insereInicioLstCirDup(&minha_lista_cir_dup, 7);
    insereInicioLstCirDup(&minha_lista_cir_dup, 6);

    insereFimLstCirDup(&minha_lista_cir_dup, 40);
    insereFimLstCirDup(&minha_lista_cir_dup, 89);
    insereFimLstCirDup(&minha_lista_cir_dup, 3);

    imprimeLstCirDup(minha_lista_cir_dup); 

    printf("Valor removido no FINAL = %d\n", removeFimLstCirDup(&minha_lista_cir_dup));
    printf("Valor removido no FINAL = %d\n", removeFimLstCirDup(&minha_lista_cir_dup));
    printf("Valor removido  no INICIO = %d\n", removeInicioLstCirDup(&minha_lista_cir_dup));

    imprimeLstCirDup(minha_lista_cir_dup);

    
    return EXIT_SUCCESS;
}