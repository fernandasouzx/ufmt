/***
 * UFMT -Ciencia da Computacao
 * Estrutura de Dados
 * Prof Ivairton M. Santos
 * Alunos: Fernanda Lima de Souza
 *         Guilherme da Silva Ferraz 
 * 
 * Arquivo da função MAIN.C 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_est.h"
#include "lista_enc.h"
#include "lista_dup.h"

#define tam 10000

int main()
{
    srand(time(NULL));
    //Nome dos arquivo .txt;
    char texto_1[] = "lista_est.txt";
    char texto_2[] = "lista_enc.txt";
    char texto_3[] = "lista_dup.txt";

    //Cria listas estáticas, encadeadas e duplamente encadeadas;
    tipo_lista minha_lista_est;
    tipo_noh *minha_lista_enc = NULL;
    tipo_noh_dup *minha_lista_dup = NULL;

    minha_lista_est.contador = 0;
    
    int escolha,ins_inicio, ins_fim, ins_pos;
    double tempo;

    printf("Escolha o método de inserção pela qual deseja inserir:\n\n");
    printf("1 - LISTA ESTÁTICA\n");
    printf("2 - LISTA ENCADEADA\n");
    printf("3 - LISTA EDUPLAMENTE NCADEADA\n");

    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:
        printf("Inserção em LISTA ESTÁTICA....\n");

        ins_inicio = 0;
        ins_fim = 0;
        ins_pos = 0;
        tempo = 0.0;
        clock_t inicio, fim;
        inicio = clock();

        for (int i = 0; i < tam; i++)
        {
            if (i < (int)(tam / 3))
            {
                insere_inicio_lista(&minha_lista_est, (1 + rand() % 999999));
                ins_inicio++;
            }
            else if (i > 2 * ((int)(tam / 3)))
            {
                insere_fim_lista(&minha_lista_est, (1 + rand() % 999999));
                ins_fim++;
            }
            else
            {
                insere_pos_lista(&minha_lista_est, (1 + rand() % 999999), (rand() % (minha_lista_est.contador + 1)));
                ins_pos++;
            }
        }

        fim = clock();

        tempo += (double)(fim - inicio) / CLOCKS_PER_SEC;
        
        printf("Quantidade de dados inseridos no inicio: %d\n", ins_inicio);
        printf("Quantidade de dados inseridos no fim: %d\n", ins_fim);
        printf("Quantidade de dados inseridos por posição: %d\n", ins_pos);
        printf("Tempo de execução: %lf\n", tempo);
        salvarEstTxt(texto_1, &minha_lista_est);

        break;
    case 2:
        printf("Inserção em LISTA ENCADEADA...\n");
        
        ins_inicio = 0;
        ins_fim = 0;
        ins_pos = 0;
        tempo = 0.0;
        inicio = clock();

        for (int i = 0; i < tam; i++)
        {
            if (i < (int)(tam / 3))
            {
                insereInicioLstEnc(&minha_lista_enc, (1 + rand() % 999999));
                ins_inicio++;
            }
            else if (i > 2 * ((int)(tam / 3)))
            {
                insereFimLstEnc(&minha_lista_enc, (1 + rand() % 999999));
                ins_fim++;
            }
            else
            {
                int pos = rand() % (contaNosEnc(minha_lista_enc) + 1);
                inserePosLstEnc(&minha_lista_enc, (1 + rand() % 999999), pos);
                ins_pos++;
            }
        }

        fim = clock();

        tempo += (double)(fim - inicio) / CLOCKS_PER_SEC;
        
        printf("Quantidade de dados inseridos no inicio: %d\n", ins_inicio);
        printf("Quantidade de dados inseridos no fim: %d\n", ins_fim);
        printf("Quantidade de dados inseridos por posição: %d\n", ins_pos);
        printf("Tempo de execução: %lf.\n", tempo);
        salvarEncTxt(texto_2, minha_lista_enc);
        break;

    case 3:
        printf("Inserção em LISTA DUPLAMENTE ENCADEADA...\n");
        
        ins_inicio = 0;
        ins_fim = 0;
        ins_pos = 0;
        tempo = 0.0;
        inicio = clock();

        for (int i = 0; i < tam; i++)
        {
            if (i < (int)(tam / 3))
            {
                insereInicioLstDup(&minha_lista_dup, (1 + rand() % 999999));
                ins_inicio++;
            }
            else if (i > 2 * ((int)(tam / 3)))
            {
                insereFimLstDup(&minha_lista_dup, (1 + rand() % 999999));
                ins_fim++;
            }
            else
            {
                int pos = rand() % (contaNosDup(minha_lista_dup) + 1);
                inserePosLstDup(&minha_lista_dup, (1 + rand() % 999999), pos);
                ins_pos++;
            }
        }

        fim = clock();

        tempo += (double)(fim - inicio) / CLOCKS_PER_SEC;
        
        printf("Quantidade de dados inseridos no inicio: %d\n", ins_inicio);
        printf("Quantidade de dados inseridos no fim: %d\n", ins_fim);
        printf("Quantidade de dados inseridos por posição: %d\n", ins_pos);
        printf("Tempo de execução: %lf.\n", tempo);

        salvarDupEncTxt(texto_3, minha_lista_dup);
        break;
    default:
        printf("Opção inválida.\n"); // Adição: Mensagem de erro para opção inválida
        break;
    }
    free(minha_lista_enc);
    free(minha_lista_dup);
    return EXIT_SUCCESS;
}