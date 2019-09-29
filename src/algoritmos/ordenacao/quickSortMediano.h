#ifndef QUICKSORTMEDIANO_H
#define QUICKSORTMEDIANO_H
#include "../../classes/review.h"

void gerarVetor(int* v, int k, int* aux);

int medianadek(int *vetor, int k, unsigned long long int *trocas, unsigned long long int *comparacoes);

void quickSortMediano(int *vetor, int inicio, int fim, int k, unsigned long long int *trocas, unsigned long long int *comparacoes);

#endif // QUICKSORTMEDIANO_H
