#include "heap.h"

void inicializaHeap(tipo_heap *hp)
{
    hp->qnt = 0;
}

int filhoEsqHeap(int i)
{
    return (2*i+1);
}

int filhoDirHeap(int i)
{
    return (2*i+2);
}

int paiHeap(int i)
{
    return (int) (i-1)/2;
}

void sobeHeap(tipo_heap *hp, int pos)
{
    tipo_dado_heap aux;
    if(pos > 0)
    {
        //Verifica se prioridade do pai eh menor
        if(hp->heap[pos].prioridade > hp->heap[(paiHeap(pos))].prioridade)
        {
            //Faz a troca
            aux =  (hp->heap[pos]);
            hp->heap[pos] = hp->heap[(paiHeap(pos))];
            hp->heap[paiHeap(pos)] = aux;
            sobeHeap(hp, paiHeap(pos));
        }
    }
}

void desceHeap(tipo_heap *hp, int pos)
{
    int pos_filho;
    tipo_dado_heap aux;
    if(filhoDirHeap(pos) < hp->qnt)
    {
        // Verifica se tem dois filhos
        if(filhoEsqHeap(pos) < hp->qnt)
        {
            if(hp->heap[filhoEsqHeap(pos)].prioridade < hp->heap[filhoDirHeap(pos)].prioridade)
            {
                pos_filho = filhoEsqHeap(pos);
            }
            else
                pos_filho = filhoDirHeap(pos);
        }
        else
            pos_filho = filhoEsqHeap(pos);
        
        if(hp->heap[pos].prioridade < hp->heap[pos_filho].prioridade)
        {
            aux = hp->heap[pos];
            hp->heap[pos] = hp->heap[pos_filho];
            hp->heap[pos_filho] = aux;
            desceHeap(hp, pos_filho);
        }
    }
}

void insereHeap(tipo_heap *hp, int prioridade, char dado)
{
    if(hp->qnt < MAX_HEAP)
    {
        hp->heap[hp->qnt].prioridade = prioridade;
        hp->heap[hp->qnt].dado = dado;
        hp->qnt++;
        sobeHeap(hp, hp->qnt-1);
    }
}

tipo_dado_heap removeHeap(tipo_heap *hp)
{
    tipo_dado_heap aux;
    if(hp->qnt > 0)
    {
        aux = hp->heap[0];
        hp->heap[0] = hp->heap[hp->qnt];
        desceHeap(hp, 0);
    }
    return aux;
}

void imprimeHeap(tipo_heap *hp)
{
    int i;
    printf("HEAP:\nQnt Dados = %d\nHEAP->[", hp->qnt);
    for(i = 0; i < MAX_HEAP; i++)
    {
        printf("(%d | %c)", hp->heap[i].prioridade, hp->heap[i].dado);
    }
    printf("]\n");
}