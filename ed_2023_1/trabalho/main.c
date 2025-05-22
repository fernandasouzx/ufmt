#include <stdio.h>
#include <stdlib.h>
//#include "arvMF.h"
#include "lista_dup.h"

//void carregarDados();

int main() {
    tipo_noh_dup *minha_lst_dup = NULL;
    FILE *fp = fopen("tcc_ceds_music.csv", "r");
    if (fp == NULL) {
        perror("[Erro] Não foi possível abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    char linha[6000];
    fgets(linha, sizeof(linha), fp); // Ignorar a primeira linha, que contém os cabeçalhos

    while (fgets(linha, sizeof(linha), fp)) {
        tipo_music_dataset music_data;
        sscanf(linha, "%d,%[^,],%[^,],%d,%[^,],%[^,],%d,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%[^,],%lf",
               &music_data.id, music_data.artist_name, music_data.track_name, &music_data.release_date, music_data.genre, music_data.lyrics,
               &music_data.len, &music_data.dating, &music_data.violence, &music_data.world_life, &music_data.night_time, &music_data.shake_the_audience,
               &music_data.family_gospel, &music_data.romantic, &music_data.communication, &music_data.obscene, &music_data.music,
               &music_data.movement_places, &music_data.light_visual_perceptions, &music_data.family_spiritual, &music_data.like_girls,
               &music_data.sadness, &music_data.feelings, &music_data.danceability, &music_data.loudness, &music_data.acousticness,
               &music_data.instrumentalness, &music_data.valence, &music_data.energy, music_data.topic, &music_data.age);
        insereLstDup(&minha_lst_dup, music_data);
    }

    fclose(fp);

    tipo_noh_dup *ptr = minha_lst_dup;
    if (ptr != NULL) {
        printf("ID: %d\n", ptr->data.id);
        printf("Artista: %s\n", ptr->data.artist_name);
        printf("Música: %s\n", ptr->data.track_name);
        printf("Gênero: %s\n", ptr->data.genre);
        printf("Ano de lançamento: %d\n", ptr->data.release_date);
        printf("Letra: %s\n", ptr->data.lyrics);
    }

    return EXIT_SUCCESS;
}
