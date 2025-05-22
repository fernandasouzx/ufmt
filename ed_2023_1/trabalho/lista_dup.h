#ifndef __LISTA_DUP__H_
#define __LISTA_DUP__
#include <stdio.h>
#include <stdlib.h>


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

struct est_noh_dup
{
    tipo_music_dataset data;
    struct est_noh_dup *ant;
    struct est_noh_dup *prox;
}; typedef struct est_noh_dup tipo_noh_dup;

tipo_noh_dup *aloca_noh(tipo_music_dataset);
void insereLstDup(tipo_noh_dup **, tipo_music_dataset);
tipo_music_dataset removeInicioLstDup(tipo_noh_dup**);
void imprimeLstDup(tipo_noh_dup*);

#endif