#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main() {
    tipo_heap meu_heap;
    insereHeap(&meu_heap, 20, 'G');
    insereHeap(&meu_heap, 13, 'C');
    insereHeap(&meu_heap, 3, 'D');
    insereHeap(&meu_heap, 43, 'E');
    insereHeap(&meu_heap, 23, 'F');
    insereHeap(&meu_heap, 14, 'A');
    
    imprimeHeap(&meu_heap);
    tipo_dado_heap dado;
    dado = removeHeap(&meu_heap);
    //printf("Valor removido: %d\n", dado);

    //imprimeHeap(&meu_heap);
    return 0;
}
