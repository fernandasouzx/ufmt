#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/times.h> //Funcao Times
#include <sys/types.h> //Bib que define o registro TMS
#include <unistd.h> //Biblioteca necessaria para descobrir os ciclos de clock

#include "estruturas_de_dados.h"

int main() { 

    printf("\t\n");
    printf("\t***********************\n");
    printf("\t*                     *\n");
    printf("\t* Seja bem-vindo ao   *\n");
    printf("\t*    Trabalho de      *\n");
    printf("\t*   Estruturas de     *\n");
    printf("\t*     Dados 9 !       *\n");
    printf("\t*                     *\n");
    printf("\t*    (^.^)   (^_^)    *\n");
    printf("\t*    <(^.^)> <(^_^)>  *\n");
    printf("\t*     /_|_\\ /_|_\\     *\n");
    printf("\t*                     *\n");
    printf("\t***********************\n");
    printf("\n");



    //PARTE 1-------------------------------------------------------------------------------------------------------------------
    
    //Declaração de variáveis para contagem de tempo e armazenamento de dados. 
    int  genreLst, genreCirc, danceAbility;
    struct tms tempo;
    int tics_por_segundo,tics_por_segundo2 ;
    tipo_noh_dup *minha_lst_dup = NULL;

    // Pergunta ao SO sobre os ciclos de clock
    tics_por_segundo = sysconf(_SC_CLK_TCK);

    // Abre o arquivo para leitura
    FILE *fp = fopen("tcc_ceds_music.csv", "r");
    if (fp == NULL) {
        perror("[Erro] Não foi possível abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    // Ignorar a primeira linha, que contém os cabeçalhos
    char linha[6000];
    fgets(linha, 6000, fp); 

    // Lê os registros do arquivo e os armazena na lista duplamente encadeada
    while (fgets(linha, 6000, fp)) {
        struct music_dataset music_data;
        sscanf(linha, "%d,%[^,],%[^,],%d,%[^,],%[^,],%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%[^,],%lf",
         
            &music_data.id, music_data.artist_name, music_data.track_name, &music_data.release_date, music_data.genre, music_data.lyrics,
            &music_data.len, &music_data.dating, &music_data.violence, &music_data.world_life, &music_data.night_time, &music_data.shake_the_audience,
            &music_data.family_gospel, &music_data.romantic, &music_data.communication, &music_data.obscene, &music_data.music,
            &music_data.movement_places, &music_data.light_visual_perceptions, &music_data.family_spiritual, &music_data.like_girls,
            &music_data.sadness, &music_data.feelings, &music_data.danceability, &music_data.loudness, &music_data.acousticness,
            &music_data.instrumentalness, &music_data.valence, &music_data.energy, &music_data.topic, &music_data.age);
        insereLstDup(&minha_lst_dup, music_data);
    }

    fclose(fp); //fecha o arquivo
    
    
    // Executa a função times para registro dos dados na estrutura time (estrutura tms)
    times(&tempo);

    printf("\nTempo de uso do processador pelo processo PARTE 1: %f segundos\n", ((double)tempo.tms_utime) / tics_por_segundo);

    
    //PARTE 2 -----------------------------------------------------------------------------------------------------------------------
    
    //Pergunta ao SO sobre os ciclos de clock
    tics_por_segundo2 = sysconf(_SC_CLK_TCK);

    // Inicialização de variáveis e estruturas para contagem de registros e armazenamento de dados    
    tipo_noh_dup *ptr = minha_lst_dup;
    tipo_noh_circ_dup *circ = NULL;
    tipo_noh_lst_enc *lst = NULL;
    
    danceAbility = 0;

    // Conta os registros com 'danceability' >= 0.5 e insere na lista encadeada
    while(ptr != NULL)
    {
        if(ptr->data.danceability >= 0.5)
        {
            danceAbility++;
            insereCircDup(&circ, ptr->data);
            //insereLstEnc(&lst, ptr->data);
            ptr = ptr->prox;
            
        }
        else
            ptr = ptr->prox;
    }
    
    printf("\nTotal de registros com 'danceability' >= 0.5: %d\n", danceAbility);

    // Conta o número de registros com gênero 'pop' na lista encadeada
    genreLst = 0;
    while(lst != NULL)
    {   
        //verifica se o genero da musica armazenada é "pop"
        if(strcmp(lst->dataListaEnc.genre, "pop") == 0)
        {
            genreLst++;
        }
        lst = lst->prox;
       
    }
    printf("\nNumero de registros com gênero 'pop' na LISTA ENCADEADA: %d\n", genreLst);
 
    // Conta o número de registros com gênero 'pop' na lista circular duplamente encadeada
    genreCirc = 0;
    tipo_noh_circ_dup *ptrCirc = circ; 

    // Verifica se a lista circular não está vazia
    if (circ != NULL) {
        // Percorre a lista circular até retornar ao início
        do {
            // Verifica o gênero da música atual
            if (strcmp(ptrCirc->dataCirc.genre, "pop") == 0) {
                genreCirc++; // Incrementa o contador se o gênero for "pop"
            }
            ptrCirc = ptrCirc->prox; // Avança para o próximo nó da lista
        } while (ptrCirc != circ); // Condição de parada: quando voltar ao início
    } 
    times(&tempo);
    printf("\nNumero de registros com  gênero 'pop' na LISTA CIRCULAR DUPLAMENTE ENCADEADA: %d\n", genreCirc);

    
    printf("\nTempo de uso do processador pelo processo PARTE 2: %f segundos\n", ((double)tempo.tms_utime) / tics_por_segundo2);
    
    return EXIT_SUCCESS;
}