#ifndef QUICKSORTMEDIANO_H
#define QUICKSORTMEDIANO_H
#include "../../classes/review.h"

void gerarVetor(int* v, int inicio, int k, int* aux);

int medianadek(int *vetor, int k, unsigned long *trocas, unsigned long *comparacoes);

void quickSortMediano(int *vetor, int inicio, int fim, int k, unsigned long *trocas, unsigned long *comparacoes);

#endif // QUICKSORTMEDIANO_H
