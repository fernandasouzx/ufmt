/*
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Aluna: Fernanda Lima de Souza
 * 
 * Implementação do cabeçalho MAIN.C
*/

#include <stdio.h>
#include <stdlib.h>
#include "arv_m_filhos.h"

int main(int argc, char *argv[]){
    tipo_arv_m_f *minha_arvore;
    (minha_arvore) = NULL;
    /*
    insereArvMF(&minha_arvore, 7);
    insereArvMF(&minha_arvore, 30);
    insereArvMF(&minha_arvore, 15);
    insereArvMF(&minha_arvore, 1);
    insereArvMF(&minha_arvore, 50);
    insereArvMF(&minha_arvore, 6);
    insereArvMF(&minha_arvore, 3);
    insereArvMF(&minha_arvore, 70);
    insereArvMF(&minha_arvore, 35);
    insereArvMF(&minha_arvore, 14);
    insereArvMF(&minha_arvore, 10);
    insereArvMF(&minha_arvore, 23);
    insereArvMF(&minha_arvore, 20);
    //insereArvMF(&minha_arvore, 12);
    insereArvMF(&minha_arvore, 25);
    insereArvMF(&minha_arvore, 60);
    */

    insereArvMF(&minha_arvore, 12);
    insereArvMF(&minha_arvore, 7);
    insereArvMF(&minha_arvore, 15);
    insereArvMF(&minha_arvore, 3);
    insereArvMF(&minha_arvore, 1);
    insereArvMF(&minha_arvore, 2);
    insereArvMF(&minha_arvore, 20);
    insereArvMF(&minha_arvore, 22);
    insereArvMF(&minha_arvore, 4);
    insereArvMF(&minha_arvore, 6);
    insereArvMF(&minha_arvore, 5);
    insereArvMF(&minha_arvore, 10);
    insereArvMF(&minha_arvore, 14);
    insereArvMF(&minha_arvore, 9);
    insereArvMF(&minha_arvore, 13);
    insereArvMF(&minha_arvore, 8);
    insereArvMF(&minha_arvore, 11);
    insereArvMF(&minha_arvore, 25);
    insereArvMF(&minha_arvore, 23);

    //int vl= 60;
    //if (buscaValorArvMF(minha_arvore, vl)){
      //  printf("Valor %d buscado e encontrado...\n",vl);
    
    //}else{
      //  printf("Valor %d buscado, mas nao encontrado\n",vl);
    //}
   
    printf("Imprime arvore PRE-ordem: \n");
    percursoPreOrdemArvMF(minha_arvore);
    printf("\n");

    printf("Imprime arvore POS-ordem: \n");
    percursoPosOrdemArvMF(minha_arvore);
    printf("\n");

    printf("Imprime arvore Ordem: \n");
    percursoOrdemArvMF(minha_arvore);
    printf("\n");

    printf("Total de valores presentes na arvores = %d\n", contabilizaValoresArvMF(minha_arvore));

    printf("Total de FOLHAS: %d\n", contabilizaFolhasArvMF(minha_arvore));

    printf("Total de nós da arvore = %d\n", contabilizaNosArvMF(minha_arvore));

    imprimeNivelArvMF(minha_arvore, 3);
    
    printf("A altura da arvore eh: %d \n", alturaArvMF(minha_arvore));

    printf("Maior valor registrado na arvore = %d \n", maiorValorArvMF(minha_arvore));

    printf("Menor valor registrado na arvore = %d\n", menorValorArvMF(minha_arvore));

    printf("Folha = %d\n", ehFolha(minha_arvore->filhos[3]->filhos[2]));

    printf("foi removido  %d");

    removeArvMF(minha_arvore, 60);

   

    return EXIT_SUCCESS;
}