/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Aluna: Fernanda Lima de Souza
 * Implementacao dos algorimtmos de ordenacao
 * Arquivo de cabeçalho ORDENACAO.H
 */

#ifndef __ORDENACAO_H__
#define __ORDENACAO_H__

#include<stdio.h>
#include<stdlib.h>

//Inclui bib que manipula lista com alocacao estatica
#include "lista.h"

//Prototipo dos metodos de ordenacao
void BubbleSort(tipo_lista *);
void ShellSort(tipo_lista *);
void InsertSort(tipo_lista *, int);
void MergeSort(tipo_lista *);
void merge(int*, int);
void QuickSort(tipo_lista *);
void quick(int*, int, int);



#endif //FIM __ORDENACAO_H__