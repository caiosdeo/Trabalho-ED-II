#ifndef QUICKSORTMEDIANO_H
#define QUICKSORTMEDIANO_H
#include "../../classes/review.h"

int particaoId(int *vetor, int inicio, int fim, int *trocas, int *comparacoes);
void trocarId(int *vetor, int a, int b);
void quickSortMedianoId(int *vetor, int inicio, int fim, int *trocas, int *comparacoes);

int particaoReview(Review* r, int inicio, int fim, int *trocas, int *comparacoes);
void trocarReview(Review* r, int a, int b);
void quickSortMedianoReview(Review* r, int inicio, int fim, int *trocas, int *comparacoes);




#endif // QUICKSORTMEDIANO_H
