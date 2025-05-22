/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton M. Santos
 * 
 * Alunos: Fernanda Lima de Souza
 *         Guilherme da Silva Ferraz
 * 
 * Implementacao da "biblioteca" utilizada no projeto
 * Arquivo de cabeçalho BIB.H
***/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef __BIB_H__
#define __BIB_H__


//Definicao do tipo da estrutura
struct est_lista {
    int capacidade;
    int *lista;
    int contador;
};
typedef struct est_lista tipo_lista;

//Definicao dos prototipos

void gera_arquivo(int n,int valor,char *texto);
void gerarDados(int numValues);
int contains(int *, int, int);
void insereLista(tipo_lista *, int valor);
void le_arquivo(const char *arq, tipo_lista *lst);
void inicializaLista( tipo_lista *lst, int capacidade);
void imprime(tipo_lista);
void ordenarEGravar(char *nomeArquivo, tipo_lista *lista, unsigned long int (*funcaoOrdenacao)(tipo_lista *));

//Métodos de ordenação
unsigned long int BubbleSort (tipo_lista *lst);
unsigned long int ShellSort(tipo_lista *);
unsigned long int InsertSort(tipo_lista *lst);
int insere_pos_lista(tipo_lista *lst, int valor, int pos);
unsigned long int MergeSort(tipo_lista *);
unsigned long int merge(int[], int);
long int QuickSort(tipo_lista *);
long int quick(int lst[], int inicio, int fim);

#endif //__BIB_H__