#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include "../classes/review.h"

/**
 * insertionSort para vetor de inteiros
 * @author caiosdeo
 * @param vet Vetor de inteiros
 * @param size Tamanho do vetor
 * @param numComparacoes número de comparações
 * @param numReg número de registros
 * @return void
 */
void insertionSortInteiros(int *vet, int size, int *numComp, int *numReg);

/**
 * insertionSort para vetor de reviews
 * @author caiosdeo
 * @param vet Vetor de reviews
 * @param size Tamanho do vetor
 * @param numComparacoes número de comparações
 * @param numReg número de registros
 * @return void
 */
void insertionSortReviews(Review *r, int size, int *numComp, int *numReg);



#endif // INSERTIONSORT_H
