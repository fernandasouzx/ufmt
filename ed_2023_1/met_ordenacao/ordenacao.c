/***
*Aluna: Fernanda Lima de Souza
***/

#include "ordenacao.h"
#include "lista.h"


/**
 * @brief Método de ordenação BUBBLE SORT (complexidade 0(n^2))
 * @param lst - ponteiro para estrutura para o tipo Lista (tipo_lista)
 */
void BubbleSort (tipo_lista *lst){
    int troca, i, aux;
    do {
        troca = 0;
        for (i=0; i < lst->contador-1; i++){
            if (lst->lista[i] > lst->lista[i+1]){
                aux = lst->lista[i];
                lst->lista[i] = lst->lista[i+1];
                lst->lista[i+1] = aux;
                troca++;
            }
        }
    } while (troca != 0);
    
} 

/**
* @brief Função que ordena a lista pelo método SHELL SORT(complexidade o(n^2)).
* 
* @param lst - ponteiro para estrutura para o tipo Lista (tipo_lista)
*/
    
void ShellSort(tipo_lista *lst){
    int salto, i,troca, aux ;

    salto = (int) lst->contador / 2;

    while(salto > 1){
        for (i=0; i+salto < lst->contador; i++){
            
            if (lst->lista[i] > lst->lista[i+salto]){
                aux = lst->lista[i];
                lst->lista[i] = lst->lista[i+salto];
                lst->lista[i+salto] = aux;
            }
        } salto = (int) salto / 2;
    } 

    printf("A lista meio ordenada:\n");
    imprime_lista(*lst);
    printf("imprimi\n\n");


    //Etapa equivalente ao Bubble Sort (salto = 1)
    do { //realiza ao menos 1 passagem
        troca = 0;
        for (i=0; i < lst->contador-1; i++){
            if (lst->lista[i] > lst->lista[i+salto]){
                aux = lst->lista[i+salto];
                lst->lista[i+salto] = lst->lista[i];
                lst->lista[i] = aux;
                troca++; // modifica a flag troca
            }
        }
    } while (troca != 0);
}

/**
 * @brief - Funçao que ordena lista pelo método INSERT SORT.
 * 
 * @param lst - ponteiro para estrutura para o tipo Lista (tipo_lista)
*/
    
void InsertSort(tipo_lista *lst, int tam){

    tipo_lista ordenado;
    ordenado.contador = 0;

    int i;

    for(i=0; i <tam; i++){
        if(ordenado.contador == 0){
            insere_inicio_lista(&ordenado, lst->lista[i]);
        } else {
            insere_pos_lista(&ordenado, lst->lista[i], encontrapos(&ordenado, ordenado.contador, lst->lista[i] ));
        }
    }

    for (i = 0; i != lst->contador ; i++){
        lst->lista[i] = ordenado.lista[i];
    }
}

/**
 * @brief - Funçao que ordena lista pelo método MERGE SORT.
 * 
 * @param lst - ponteiro para estrutura para o tipo Lista (tipo_lista)
**/
    
void MergeSort(tipo_lista *lst){
    merge(lst -> lista, lst ->contador);
    
}     

void merge(int lst[], int tamanho){
    int meio, i, j, posAux, *lstAux;

    if(tamanho>1){//Verifica se é possivel dividir
        //processo de QUEBRA
        meio = (int) tamanho/2;
        merge(&(lst[0]), meio);
        merge(&(lst[meio]), tamanho - meio);
    
    
        // Processo de Merge
        //aloca um vetor auxiliar vetAux de tamanho "tamanho"
        lstAux = (int*) malloc(sizeof(int)*tamanho);
        i = 0;    
        j = meio;
        posAux = 0;
        
        //Enquanto i e j não atingiram os seus respectivos 'fins'
        while(i<meio && j<tamanho){
            if(lst[i] < lst[j]){
                lstAux[posAux++] = lst[i++];
            }else{
                lstAux[posAux++] = lst[j++];
            }
        }
                        
        // se uma das listas foi finalizada, copia o restante
        while (i < meio){
            lstAux[posAux++] = lst[i++];
            //posAux = posAux + 1;
            //i = i + 1;
        }

        while(j < tamanho){
            lstAux[posAux++] = lst[j++];
            //posAux = posAux + 1;
            //j = j + 1; 
        }

        //Copia o vetor auxiliar para o vetor original
        for(i=0; i<tamanho; i++){
            lst[i] = lstAux[i];
        }
        free(lstAux);//Desaloca da memória VetAux
    }
}

/**
 * @brief - Funçao que ordena lista pelo método QUICK SORT.
 * 
 * @param lst - ponteiro para estrutura para o tipo Lista (tipo_lista)
**/

void QuickSort(tipo_lista *lst){
    if (lst-> contador > 1){
        quick(lst->lista, 0, lst->contador-1);
    }
}


/**
 * @brief - Funçao interna ao Quick Sort, que implementa o algoritmo.
 * 
 * @param lst - Vetor de inteiros
 * @param inicio - Indice do inicio a ser considerado do vetor (sub-lista)
 * @param fim - Indice de fim a ser considerado do vetor (sub-lista)
 **/

void quick(int lst[], int inicio, int fim){

    int meio, i, j, pivo, aux;

    // escolha do pivo
    meio = (int) ((fim - inicio) / 2) + inicio;
    pivo = lst[meio];

    // Mas a estratégia de definição do pivo, adotada acima, vai impactar no procedimento de troca
    i = inicio;
    j = fim;
    //Faz as trocas entre os valores menores e maiores posicionados em lados errados (em relação ao pivo)!
    while(i<j){

        while(lst[i] < pivo)
            i++;

        while(lst[j] > pivo)
            j--;
        
        //Verifica se os dois não se encontraram para fazer troca
        if(i < j){
            aux = lst[i];
            lst[i] = lst[j];
            lst[j] = aux;
        }
    }

    //Verifica e faz a chamada recursiva
	if ( j-1 >= inicio){
		quick(lst, inicio, j-1);
    }

    //chamada recursiva para a segunda parte (depois do pivo)
	if( i+1 <= fim ) {
		quick(lst, i+1, fim);
    }
}    