#ifndef QUICKSORTMEDIANO_H
#define QUICKSORTMEDIANO_H
#include "../../classes/review.h"

unsigned* gerarVetor(unsigned* v, unsigned inicio, unsigned k);

unsigned medianadek(unsigned *vetor, unsigned k, unsigned long long *trocas, unsigned long long *comparacoes);

void quickSortMediano(unsigned *vetor, unsigned inicio, unsigned fim, unsigned k, unsigned long long *trocas, unsigned long long *comparacoes);

#endif // QUICKSORTMEDIANO_H
