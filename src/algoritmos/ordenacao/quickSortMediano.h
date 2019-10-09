#ifndef QUICKSORTMEDIANO_H
#define QUICKSORTMEDIANO_H
#include "../../classes/review.h"

void gerarVetor(unsigned* v, unsigned inicio, unsigned k, unsigned* aux);

unsigned medianadek(unsigned *vetor, unsigned k, unsigned *trocas, unsigned *comparacoes);

void quickSortMediano(unsigned *vetor, unsigned inicio, unsigned fim, unsigned k, unsigned *trocas, unsigned *comparacoes);

#endif // QUICKSORTMEDIANO_H
