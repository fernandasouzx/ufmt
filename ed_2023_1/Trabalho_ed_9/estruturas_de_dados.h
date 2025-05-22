#ifndef __ESTRUTURA_DE_DADOS_H__
#define __ESTRUTURA_DE_DADOS_H__
#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP 28374

//Definição da estrutura do dataset
struct music_dataset
{
    int id;
    char artist_name[100];
    char track_name[100];
    int release_date;
    char genre[50];
    char lyrics[6000];
    int len;
    double dating;
    double violence;
    double world_life;
    double night_time;
    double shake_the_audience;
    double family_gospel;
    double romantic;
    double communication;
    double obscene;
    double music;
    double movement_places;
    double light_visual_perceptions;
    double family_spiritual;
    double like_girls;
    double sadness;
    double feelings;
    double danceability;
    double loudness;
    double acousticness;
    double instrumentalness;
    double valence;
    double energy;
    char topic[100];
    double age;
};
typedef struct music_dataset tipo_music_dataset;

//Definição da estrutura da lista duplamente encadeada
struct est_noh_dup
{
    tipo_music_dataset data;
    struct est_noh_dup *ant;
    struct est_noh_dup *prox;
}; typedef struct est_noh_dup tipo_noh_dup;

//Definição da estrutura de lista circular duplamente encadeada
struct est_noh_circ_dup
{
    tipo_music_dataset dataCirc;
    struct est_noh_circ_dup *ant;
    struct est_noh_circ_dup *prox;
};
typedef struct est_noh_circ_dup tipo_noh_circ_dup;


//Definição da estrutura da lista encadeada
struct est__noh_lst_enc{
    tipo_music_dataset dataListaEnc;
    struct  est__noh_lst_enc *prox;
}; typedef struct est__noh_lst_enc tipo_noh_lst_enc;

//Protótipo das funções

tipo_noh_circ_dup *alocaNohCircDup(tipo_music_dataset);
void insereCircDup(tipo_noh_circ_dup** , tipo_music_dataset);
tipo_noh_dup *aloca_noh(tipo_music_dataset);
void insereLstDup(tipo_noh_dup **, tipo_music_dataset);
tipo_noh_lst_enc *aloca_noLst(tipo_music_dataset);
void insereLstEnc(tipo_noh_lst_enc **, tipo_music_dataset);   

#endif //__ESTRUTURA_DE_DADOS_H__