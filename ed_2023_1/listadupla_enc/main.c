#include <stdio.h>
#include <stdlib.h>
#include "listadupla.h"
#include "listadupla_enc.c"

int main(int argc, char *argv[])
{

    tipo_no_dup *minha_lista_dup;
    minha_lista_dup = NULL;

    insereInicioLstDup(&minha_lista_dup, 1);
    insereInicioLstDup(&minha_lista_dup, 2);
    insereInicioLstDup(&minha_lista_dup, 3);

    insereFimLstDup(&minha_lista_dup, 40);
    insereFimLstDup(&minha_lista_dup, 27);
    insereFimLstDup(&minha_lista_dup, 3);

    //inserePosLstDup(&minha_lista_dup, -5, 2);
    //inserePosLstDup(&minha_lista_dup, , -1);
    inserePosLstDup(&minha_lista_dup, -3, 2);
    inserePosLstDup(&minha_lista_dup, 88, -3);

    imprimeLstDup(minha_lista_dup);

    return EXIT_SUCCESS;
}