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
#include "arvore_bin.h"

int main(int argc, char *argv[]){
    tipo_no_arv *minha_arvore = NULL;

    // Inserindo nós com o caractere (letra) e a chave (valor)
    insere(&minha_arvore, 'A', 10);
    insere(&minha_arvore, 'B', 7);
    insere(&minha_arvore, 'C', 31);
    insere(&minha_arvore, 'D', 9);
    insere(&minha_arvore, 'E', 15);
    insere(&minha_arvore, 'F', 50);
    insere(&minha_arvore, 'G', 8);
    insere(&minha_arvore, 'H', 45);
    insere(&minha_arvore, 'I', 100);
    insere(&minha_arvore, 'J', 99);
    
    printf("\n ARVORE BINARIA\n");
    printf("____________________\n");

    printf("\nArvore PRE ORDEM:\n");
    percursoPreOrdem(minha_arvore);
    printf("\n");

    printf("\nArvore POS ORDEM:\n");
    percursoPosOrdem(minha_arvore);
    printf("\n");

    printf("\nArvore em ORDEM:\n");
    percursoOrdem(minha_arvore);
    printf("\n");
    
    int vl = 500;
    if(buscachave(minha_arvore, vl)){
        printf("\nValor %d ENCONTRADO!\n", vl);
    } else {
        printf("\nValor %d NAO ENCONTRADO!\n", vl);
    }
    
    // Calcula e imprime a altura da árvore
    printf("\nAltura da Arvore: %d\n", altura(minha_arvore));

    // Imprime os valores alocados em cada nível da árvore
    int nivel;
    for(nivel = 0; nivel <= altura(minha_arvore); nivel++){
        printf("\nValores alocados no nivel %d:\n", nivel);
        imprimeNivel(minha_arvore, nivel);
    }

    // Contabiliza os nós da árvore
    printf("\nA arvore possui o total de %d nos\n", contagem(minha_arvore));
    
    // Exibe o menor e o maior valor (chave) encontrados na árvore
    printf("\nO menor valor encontrado: %d\n", menorchaveArv(minha_arvore));
    printf("\nO maior valor encontrado: %d\n", maiorchaveArv(minha_arvore)); 
    
    // Remoção de nós: remove todos os nós, um a um, exibindo o percurso pré-ordem após cada remoção
   /* printf("\nREMOÇÃO\n");
    while(minha_arvore != NULL){
        printf("\nRemovendo %d...\n", minha_arvore->chave);
        removeArvBin(&minha_arvore, minha_arvore->chave);
        percursoPreOrdem(minha_arvore);
        printf("\n");
    } */

    return EXIT_SUCCESS;
}
