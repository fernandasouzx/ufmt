/***
 * Universidade Federal de Mato Grosso - UFMT
 * Prof: Ivairton Monteiro Santos
 * Alunos: Fernanda Lima de Souza
 *         Guilherme da Silva Ferraz
 * 
 *  
***/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bib.h"

//implementação das funções

void gera_arquivo(int n, int valor, char *texto){
	int vet[valor];
	
	
	int i=0,j=0,numero=0,controle1=0,flag=0,b=0;
	srand(time(NULL));
    
	int k=0;
	

    
    for (k = 1; k < n; k++) {
    	char nomearq[1000];
        FILE *file;
        sprintf(nomearq, "%s-arq%d.txt",texto,k);//gera nomes em sequencia
        
        file = fopen(nomearq, "w");

        if(file == NULL){
		    printf("Erro na abertura do arquivo!\n");
		}

		for (i=0; i < valor; i++){
		    flag=0;

		    
		   controle1=(1+rand() %999999); //numeros de 1 ate 999999
		   //se o numero gerado for retirado da funcao que gera entao o tempo de geracao vai ser muito menor
		    do{
		        flag=1;
		        
		        for (j=0; j < i; j++){
		        	
		        	
					if (controle1==vet[j]){
		    			controle1=(1+rand() %99999);
		    			flag=0;
		    
					}   
		        } 
		        
		    } while (flag==0);
		    
		        
		    vet[i]=controle1;
		    
		}

		for (b=0; b < valor; b++){
		       
		    
		    fprintf(file, "%d\n",vet[b]);

		    
		}
		fclose(file);
		printf("Gerado %d de %d\n",k,valor );
	}
	printf("\n");
}

int contains(int *arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 1; // True, se número já existe no array
        }
    }
    return 0; // False, se número não existe no array
}

void le_arquivo(const char *arq,tipo_lista *lst){
    int num;
    int i = 0;
    FILE* file = fopen(arq, "r");
    if (file == NULL)
    {
        printf("[ERRO] não foi possivel abrir o arquivo!");
        return;
    }
    fscanf(file, "%d", &num);
    while(i != lst->capacidade){
        insereLista(lst, num);
        fscanf(file,"%d", &num);
        i++;
    }
    fclose(file);
}

int existeRepeticao(int *arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 1; // True, se número já existe no array
        }
    }
    return 0; // False, se número não existe no array
}

void inicializaLista( tipo_lista *lst, int capacidade){
    lst->capacidade = capacidade;
    lst->contador = 0;
    lst->lista = (int*)malloc(sizeof(int)*capacidade);
}

void insereLista(tipo_lista *lst, int valor) { 
    if (lst->contador < lst->capacidade) {
        lst->lista[lst->contador++] = valor;
    } else {
        printf("[ERRO] A lista esta cheia!\n");
        return;
    }
}

int insere_inicio_lista(tipo_lista *lst, int valor) {
    
    int pos, capacidade;
    if (lst->contador < capacidade) {
        pos = lst->contador;
        while (pos > 0) {
            lst->lista[pos] = lst->lista[pos-1];
            pos--;
        }
        lst->lista[0] = valor;
        lst->contador++;
        return lst->contador;
    } else {
        return 0;
    }
    
    return insere_pos_lista(lst, valor, 0);
}

int insere_pos_lista(tipo_lista *lst, int valor, int pos) {
    int i,capacidade;
    if (lst->contador < capacidade) {
        i = lst->contador;
        while (i > pos) {
            lst->lista[i] = lst->lista[i-1];
            i--;
        }
        lst->lista[pos] = valor;
        lst->contador++;
        return 1;
    } else {
        return 0;
    }
}

int encontrapos(int vet[], int tam, int valor){
    int i = 0;
    while(i<tam){
        if(valor>vet[i]){
            i++;
        } else{
            return i; //devolve a posicao
        }
    }
}

void ordenarEGravar(char *nomeArquivo, tipo_lista *lista, unsigned long int (*funcaoOrdenacao)(tipo_lista *)) {
    double tempo;
    unsigned long int trocas = 0;
    clock_t begin, end;

    // Leitura do arquivo
    // le_arquivo(nomeArquivo, lista);

    // Escolha do método de ordenação
    begin = clock();
    trocas += funcaoOrdenacao(lista);
    end = clock();
    tempo = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Durante a ordenacao houve %ld trocas\n", trocas);
    printf("A ordenacao durou %f segundos\n", tempo);

    // Escrita da lista ordenada de volta no arquivo
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < lista->contador; i++) {
        fprintf(arquivo, "%d\n", lista->lista[i]);
    }

    fclose(arquivo);
}


//-----METODOS DE ORDENAÇÃO-------------------------------------------------------------------------

unsigned long int BubbleSort (tipo_lista *lst){
    int flag_troca, i, aux;
    int trocas = 0;
    do {
        flag_troca = 0;
        for (i=0; i < lst->contador-1; i++){
            if (lst->lista[i] > lst->lista[i+1]){
                aux = lst->lista[i];
                lst->lista[i] = lst->lista[i+1];
                lst->lista[i+1] = aux;
                flag_troca++;
                trocas++;
            }
        }
    } while (flag_troca != 0);
    return trocas;
}
    
unsigned long int  ShellSort(tipo_lista *lst){
    int salto, i,flag_troca, aux, cont;

    salto = (int) lst->contador / 2;
    cont = 0;

    while(salto > 1){
        for (i=0; i+salto < lst->contador; i++){
            if (lst->lista[i] > lst->lista[i+salto]){
                aux = lst->lista[i];
                lst->lista[i] = lst->lista[i+salto];
                lst->lista[i+salto] = aux;
                cont++;

            }
        } salto = (int) salto / 2;
    } 

    //Etapa equivalente ao Bubble Sort (salto = 1)
    do { //realiza ao menos 1 passagem
        flag_troca = 0;
        for (i=0; i < lst->contador-1; i++){
            if (lst->lista[i] > lst->lista[i+salto]){
                aux = lst->lista[i+salto];
                lst->lista[i+salto] = lst->lista[i];
                lst->lista[i] = aux;
                flag_troca++; // modifica a flag troca
            }
        }
    } while (flag_troca != 0);

    
    return flag_troca+cont;
}

unsigned long int InsertSort(tipo_lista* lst){
    int aux, flag_troca;
    int trocas=0;
    do{
        flag_troca = 0;
        for(int i = 0; i < lst->contador; i++){
            for(int j = i+1; j > 0;j--)
            {
                if(lst->lista[j] < lst->lista[j-1])
                {
                    aux = lst->lista[j];
                    lst->lista[j] = lst->lista[j-1];
                    lst->lista[j-1] = aux;
                    flag_troca++;
                    trocas++;

                }
            }    
        }
    } while (flag_troca!= 0);
    return trocas;
}

unsigned long int MergeSort(tipo_lista *lst){
    return merge(lst->lista, lst->contador);
    //printf("%d -> %d -> %d \n", lst->lista[0], lst->lista[1], lst->lista[2]);
}

unsigned long int merge(int lst[], int tamanho){
    int meio, i, j, posAux, *lstAux;
    long int cont=0;

    if(tamanho>1){//Verifica se é possivel dividir
        //processo de QUEBRA
        meio = (int) tamanho/2;
        cont += merge(&(lst[0]), meio);
        cont += merge(&(lst[meio]), tamanho-meio);
    
    
        // Processo de Merge
        //aloca um vetor auxiliar vetAux de tamanho "tamanho"
        lstAux = (int*) malloc(sizeof(int)*tamanho);
        i = 0;    
        j = meio;
        posAux = 0;
        
        //Enquanto i e j não atingiram os seus respectivos 'fins'
        while((i<meio )&& (j<tamanho)){
            if(lst[i] < lst[j]){
                lstAux[posAux++] = lst[i++];
                cont++;
            }else{
                lstAux[posAux++] = lst[j++];
                cont++;
            }
        

        }
                        
        // se uma das listas foi finalizada, copia o restante
        while (i < meio){
            lstAux[posAux++] = lst[i++];
        }

        while(j < tamanho){
            lstAux[posAux++] = lst[j++];
        }

        //Copia o vetor auxiliar para o vetor original
        for(i=0; i<tamanho; i++){
            lst[i] = lstAux[i];
        }
        free(lstAux);//Desaloca da memória VetAux
    }
    return cont;
}

long int QuickSort(tipo_lista *lst){
    if (lst-> contador > 1){
        return quick(lst->lista, 0, lst->contador-1);
    }

    printf("\n");
    return 0;
}

long int quick(int lst[], int inicio, int fim){

    int meio, i, j, pivo, aux, cont;
    // escolha do pivo
    cont =0;
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
            cont++;
        }
    }

    //Verifica e faz a chamada recursiva
	if ((j >inicio) && (j-inicio)>1){
		cont+=quick(lst, inicio, j);
    }

    //chamada recursiva para a segunda parte (depois do pivo)
	if((i<fim) && ((fim-i)>1)) {
	   cont+=quick(lst, i, fim);
    }
    return cont;
}   

void imprime(tipo_lista lst)
{
    int i;
    for(i = 0; i <lst.contador; i++)
    {
        printf("%d ", lst.lista[i]);
    }
}