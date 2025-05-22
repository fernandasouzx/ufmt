//bibliotecas
#include <stdio.h>
#include <stdlib.h> 

//struct de lista
struct tipo_lista {
    int *lista;
    int capacidade;
    int cont;
};
typedef struct tipo_lista Lista;

//struct do heap
struct tipo_heap {
    int *heap;
    int capacidade;
    int cont;
};
typedef struct tipo_heap Heap;

//prototipação de funções
void inicializaLista(Lista *lista1, int tamanho);
void insere_lista(Lista*, int valor);
void imprime(Lista);

void bubbleSort(Lista*);
void shellSort(Lista*);
void insertSort(Lista*);
void mergeSort(Lista*);
void mergeSortRecursivo(int*, int);
void quickSort(Lista*);
void quickSortRecursivo(int*, int , int);

void inicializaHeap(Heap*, int);
int pai(int);
int filhoEsq(int);
int filhoDir(int);
void insereHeap(Heap*, int);
int removeHeap(Heap*);
void sobeHeap(Heap*, int);
void desceHeap(Heap*, int);
void HeapSort(Lista*);

//DESENVOLVIMENTO DAS FUNÇÕES

//inicializa a Lista ------------------------------------------------------------------------------------
void inicializaLista(Lista *lista1, int tamanho){

    lista1->capacidade = tamanho;
    lista1->cont = 0;

    lista1->lista = (int*) malloc ( sizeof (int) * tamanho);

}

//insere Lista.....................................................................................
void insere_lista(Lista *lista1, int valor){
    if (lista1->cont < lista1->capacidade){
        lista1->lista[lista1->cont++] = valor;
    } else {
        printf("[ATENCAO] lista estah cheia. Nenhum valor serah inserido.\n");
    }
}

//imprime a lista ..........................................................................................
void imprime(Lista lista1){

    int i;

    for(i = 0; i<lista1.cont; i++){
        printf("[%d] ", lista1.lista[i]);
    }

    printf("\n\n");
}


//MÉTODOS DE ORDENAÇÃO--------------------------------------------------------------------------------------
//metodo bubble sort 
void bubbleSort(Lista *lista1){
    int troca, aux, i;

    do {
        troca = 0;

        for (i = 0; i < lista1->cont-1; i++){

            if (lista1->lista[i] > lista1->lista[i+1]){
                aux = lista1->lista[i];
                lista1->lista[i] = lista1->lista[i+1];
                lista1->lista[i+1] = aux;
                troca = 1;
            }
        }

    } while (troca);

}

//metodo shell sort 
void shellSort (Lista *lista1){

    int i, aux;
    int salto = (int)lista1->cont/2;

    while (salto > 1){

        for (i = 0; i+salto < lista1->cont; i++){

            if(lista1->lista[i] > lista1->lista[i+salto]){
                aux = lista1->lista[i];
                lista1->lista[i] = lista1->lista[i+salto];
                lista1->lista[i+salto] = aux;
            }
        }

        salto = (int) salto/2;
    }

    printf("parte 1: \n");
    imprime(*lista1);

    //parte 2
    bubbleSort(lista1); 
}

//metodo insert sort 
void insertSort (Lista *lista1){

    Lista listaOrdenada;
    inicializaLista (&listaOrdenada, lista1->capacidade); 
	
	int pos_lst, i;

   //Percorre cada valor da lista desordenada, inserindo na lista nova(ordenada)
    for(i=0; i<lista1->cont; i++){
        pos_lst = listaOrdenada.cont;
        while((pos_lst > 0) && (lista1->lista[i]<listaOrdenada.lista[pos_lst-1])){
            listaOrdenada.lista[pos_lst] = listaOrdenada.lista[pos_lst-1];
            pos_lst--;
        }
        listaOrdenada.lista[pos_lst] = lista1->lista[i];
        listaOrdenada.cont++;
    }

    for (i = 0; i != lista1->cont ; i++){
        lista1->lista[i] = listaOrdenada.lista[i];
    }
}

//metodo merge Sort (part1)
void mergeSort (Lista *lista1) {
    
    mergeSortRecursivo(lista1->lista, lista1->cont);

}

//metodo merge sort (part2)
void mergeSortRecursivo(int vetor[], int tamanho){

    //primeira parte do algoritimo consiste na quebra da lista em 2 partes, ate que nao seja mais possivel a quebra.
    int i, j, meio, *vet_aux, pos_aux;

    if(tamanho > 1){//Verifica se eh possivel dividir
        //processo de QUEBRA
        meio = (int) tamanho / 2;
        mergeSortRecursivo(&vetor[0], meio); //priemira metade
        mergeSortRecursivo(&vetor[meio], tamanho-meio); //segunda metade

        //Processo de MERGE
        //Aloca um vetor auxiliar para montar o vetor resultado do merge
        vet_aux = (int*) malloc(sizeof(int)*tamanho);
        i = 0;
        j = meio;
        pos_aux = 0;

        //Percorre cada metade do vetor, realizando o merge
        while ((i < meio) && (j < tamanho)){
            if(vetor[i] < vetor[j]){
                vet_aux[pos_aux++] = vetor[i++];
            } else {
                vet_aux[pos_aux++] = vetor[j++];
            }
        }

        //Verifica se uma das sub-listas foi finalizada e copia
        while ( i < meio){
            vet_aux[pos_aux++] = vetor[i++];
        }
        while ( j < tamanho){
            vet_aux[pos_aux++] = vetor[j++];
        }
        //Copia o vetor auxiliar para o vetor original
        for (i=0; i<tamanho; i++){
            vetor[i] = vet_aux[i];
        }
        free(vet_aux); //libera memoria do vetor auxiliar
    }

}

//metodo quick Sort (part1)
void quickSort(Lista *lista1){

    quickSortRecursivo(lista1->lista, 0, lista1->cont-1);

}

//metodo quick Sort (part2)
void quickSortRecursivo(int *vetor, int inicio, int fim){

    int i, j, meio, pivo, aux;

    //escolhe como pivo o elemento do meio
    meio = (int) (fim- inicio)/2 + inicio;
    pivo = vetor[meio];

    i = inicio;
    j = fim;

    //verifica se os elementos da esquerda sao menores e os da sdieta sao maiores, trocando quendo necessario ateh que i e j se encontrem
    while (i<j){
        
        while (vetor[i] < pivo){
            i++;
        }

        while (vetor[j] > pivo){
            j--;
        }

        if (i < j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }

    //realiza a chamada recursiva para cada parte
    if (j-1 > inicio) {
        quickSortRecursivo(vetor, inicio, j-1);
    }

    //chamada recursiva para a segunda parte (depois do pivo)
    if (i+1 < fim) {
        quickSortRecursivo(vetor, i+1, fim);
    }

}

//HEAP.................................................................
//inicializa o Heap 
void inicializaHeap(Heap *heap1, int tamanho){

    heap1->capacidade = tamanho;
    heap1->cont = 0;

    heap1->heap = (int*) malloc ( sizeof (int) * tamanho);

}

//calcula a posição do pai
int pai(int indice){

    int pai = (indice-1)/2;
    return pai;
}

//calcula a posição do filho esquerdo
int filhoEsq(int indice){

    int filho = (2*indice)+1;
    return filho;

}

//calcula a posição do filho direito
int filhoDir(int indice){

    int filho = (2*indice)+2;
    return filho;

}

//insere Heap Max
void insereHeap(Heap *heap1, int valor){

    if (heap1->cont < heap1->capacidade){
        
        heap1->heap[heap1->cont++] = valor;
        sobeHeap(heap1,heap1->cont-1);

    }
}

//remove Heap Max
int removeHeap(Heap *heap1){

    if (heap1->cont > 0){

        int removido;
        removido = heap1->heap[0];
        heap1->heap[0] = heap1->heap[--heap1->cont];
        desceHeap(heap1,0);

        return removido;

    } else {

        return -1;
    }
}

//pega o novo valor inserido e compara se é maior que seu pai e vai trocando até o lugar correto
void sobeHeap(Heap *heap1, int i){
    int aux;
    while((i>0) && (heap1->heap[pai(i)] < heap1->heap[i])){

        aux = heap1->heap[pai(i)];
        heap1->heap[pai(i)] = heap1->heap[i];
        heap1->heap[i] = aux;

        sobeHeap(heap1, pai(i));
    }
}

//Pega o novo valor inserido e compara se é menor que seu pai e vai trocando até o lugar correto
void desceHeap(Heap *heap1, int i){
    
    int aux, idx_maior;

    //Verifica se tem os 2 filhos
    if (filhoDir(i) < heap1->cont) {

        //Identifica o filho maior
        if ( heap1->heap[filhoEsq(i)] > heap1->heap[filhoDir(i)] ){
            idx_maior = filhoEsq(i);

        } else {
            idx_maior = filhoDir(i);
        }

        //verifica se o valor precisa descer
        if (heap1->heap[idx_maior] > heap1->heap[i]) {
            aux = heap1->heap[idx_maior];
            heap1->heap[idx_maior] = heap1->heap[i];
            heap1->heap[i] = aux;
            desceHeap(heap1, idx_maior);
        }

    } else if (filhoEsq(i) < heap1->cont) {

        idx_maior = filhoEsq(i);

        //verifica se o valor precisa descer
        if (heap1->heap[idx_maior] > heap1->heap[i]) {
            aux = heap1->heap[idx_maior];
            heap1->heap[idx_maior] = heap1->heap[i];
            heap1->heap[i] = aux;
            desceHeap(heap1, idx_maior);
        }
    }
}

void HeapSort(Lista *lista1){

    int i;

    //cria heap auxiliar
    Heap heapAux;
    inicializaHeap(&heapAux, lista1->cont);

    //percorre o heap desordenado colocando os valores ordenados no heap aux
    for (i = 0; i < lista1->cont; i++){
        insereHeap(&heapAux, lista1->lista[i]);
    }
   
    //sobrescreve a lista desordenada com elementos removidos do heap, realizando a ordenação
    for (i = lista1->cont-1; i>=0; i --) {
        lista1->lista[i] = removeHeap(&heapAux);
    }
}    

//MAIN------------------------------------------------------------------------------------------------------
int main(){

    int i;
    int valor;
    Lista MinhaLista;
    inicializaLista(&MinhaLista, 10);
    srand(1);


    //INTRODUÇÃO
    printf("\n\n");
    printf("          P  /_\\  P                                   \n");
    printf("         /_\\_|_|_/_\\                                 \n");
    printf("     n_n | ||. .|| | n_n           Bem vindo ao        \n");
    printf("     |_|_|nnnn nnnn|_|_|     meu código sobre metodos  \n");
    printf("    |" "  |  |_|  |"  " |                de ordenacao!       \n");
    printf("    |_____| ' _ ' |_____|                              \n");
    printf("          \\__|_|__/                                   \n");
    printf("\n\n");


    //INSERIR NO INICIO----------------------------------------------------------------------------------------
    printf("Inserindo valores no inicio da lista...\n\n");
    //laço para inserir no começo
    for (i = 1; i <= 10; i ++){ 
        valor = rand()% 100;
        insere_lista(&MinhaLista, valor); 
    } 

    printf("A lista nao ordenada eh: ");
    imprime(MinhaLista);

    int escolha;

    //MENU PARA ESCOLHER O MÉTODO DE ORDENAÇÃO
    printf("Escolha por qual método deseja ordenar a lista: \n\n");

    printf("1. Bubble Sort\n");
    printf("2. Shell Sort\n");
    printf("3. Insert Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Heap Sort\n\n");

    scanf("%d", &escolha);

    switch (escolha) {

        case 1:
            printf("\nOrdenando a lista por bubble sort...\n");
            bubbleSort (&MinhaLista);
            break;

        case 2:
            printf("\nOrdenando a lista por shell sort...\n");
            shellSort (&MinhaLista);
            break;

        case 3:
            printf("\nOrdenando a lista por insert sort...\n");
            insertSort (&MinhaLista);
            break;

        case 4:
            printf("\nOrdenando a lista por merge sort...\n");
            mergeSort (&MinhaLista);
            break;

        case 5:
            printf("\nOrdenando a lista por quick sort...\n");
            quickSort (&MinhaLista);
            break;

        case 6:
            printf("\nOrdenando a lista por heap sort...\n\n");
            HeapSort(&MinhaLista);
            break;        
    }
    
    printf("A lista ordenada eh: \n");
    imprime(MinhaLista);

}