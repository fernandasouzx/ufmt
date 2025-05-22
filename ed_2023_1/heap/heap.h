#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP 20

// Define estrutura que armazena a prioridade e o valor/dado
struct est_dado_heap {
    int prioridade;
    char dado;
};

// Define estrutura que representa toda tabela Heap
struct est_heap {
    int qnt;
    struct est_dado_heap heap[MAX_HEAP];
};

// Define um alias para struct est_dado_heap
typedef struct est_dado_heap tipo_dado_heap;

// Define um alias para struct est_heap
typedef struct est_heap tipo_heap;

// Protótipos das funções
void inicializaHeap(tipo_heap *);
int filhoEsqHeap(int);
int filhoDirHeap(int);
int paiHeap(int);
void sobeHeap(tipo_heap *, int);
void desceHeap(tipo_heap *, int);
void insereHeap(tipo_heap *, int, char);
tipo_dado_heap removeHeap(tipo_heap *);
void imprimeHeap(tipo_heap *);

#endif // __HEAP_H__
