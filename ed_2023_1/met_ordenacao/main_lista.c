/**
 * Universidade Federal de Mato Grosso
 * Bacharelado em Ciencia da Computacao
 * @file main.c
 * @author Fernanda Lima de Souza
 * @brief Arquivo para testes.
 * @version 0.4
 * @date 2024-01-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<stdio.h>
#include<stdlib.h>

#include "lista.h"
#include "ordenacao.h"


int main(int argc, char *argv[]){

    tipo_lista minha_lista;
    minha_lista.contador = 0;


    insere_fim_lista(&minha_lista, 80);
    insere_fim_lista(&minha_lista, 20);
    insere_fim_lista(&minha_lista, 60);
    insere_fim_lista(&minha_lista, 30);
    insere_fim_lista(&minha_lista, 10);
    insere_fim_lista(&minha_lista, 40);
    insere_fim_lista(&minha_lista, 50);
    insere_fim_lista(&minha_lista, 90);
    insere_fim_lista(&minha_lista, 70);
    insere_fim_lista(&minha_lista, 100);
    


    
    printf("-> Lista Desordenada <-\n");
    imprime_lista(minha_lista);
    printf("\n");

    //BubbleSort(&minha_lista);
    //printf("Lista Ordenada!");
    //imprime_lista(minha_lista);

    //ShellSort(&minha_lista);
    //printf("--> Lista ordenada por Shell Sort:\n");
    //imprime_lista(minha_lista);
        
    //InsertSort(&minha_lista, minha_lista.contador);
    //printf("--> Lista ordenada por Insert Sort <--\n");
    //(minha_lista);

    //MergeSort(&minha_lista);
    //printf("--> Lista ordenada por Merge Sort:\n");
    //imprime_lista(minha_lista);

    QuickSort(&minha_lista);
    printf("--> Lista ordenada por Quick Sort <--\n");
    printf("\n");
    imprime_lista(minha_lista);

    return EXIT_SUCCESS;
} 