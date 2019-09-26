#ifndef QUICKSORTMEDIANO_H
#define QUICKSORTMEDIANO_H
#include "../../classes/review.h"

int* gerarVetor(int* v, int k);

int medianadek(int *vetor, int k, int *trocas, int *comparacoes);

void quickSortMediano(int *vetor, int inicio, int fim, int k, int *trocas, int *comparacoes);

#endif // QUICKSORTMEDIANO_H
