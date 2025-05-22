#include <stdio.h>
#include <stdlib.h>

#include "lista_cir.h"


int main(int argc, char *argv[]){

    tipo_no *minha_lista_cir;
    minha_lista_cir = NULL;

    
    insereFimLstCir(&minha_lista_cir, 40);
    insereFimLstCir(&minha_lista_cir, 27);
    insereFimLstCir(&minha_lista_cir, 3);

    insereInicioLstCir(&minha_lista_cir, 1);
    insereInicioLstCir(&minha_lista_cir, 7);
    insereInicioLstCir(&minha_lista_cir, 6);


    imprimeLstCir(minha_lista_cir);
    printf("Valor removido no FINAL = %d\n", removeFimLstCir(&minha_lista_cir));
    printf("Valor removido  no INICIO = %d\n", removeInicioLstCir(&minha_lista_cir));
    imprimeLstCir(minha_lista_cir);

    return EXIT_SUCCESS;
}