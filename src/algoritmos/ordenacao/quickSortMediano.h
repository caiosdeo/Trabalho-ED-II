#ifndef QUICKSORTMEDIANO_H
#define QUICKSORTMEDIANO_H
#include "../../classes/review.h"

int particao(int *vetor, int inicio, int fim, int *trocas, int *comparacoes);
void trocarId(int *vetor, int a, int b);
void quickSortMediano(int *vetor, int inicio, int fim, int *trocas, int *comparacoes);

#endif // QUICKSORTMEDIANO_H
