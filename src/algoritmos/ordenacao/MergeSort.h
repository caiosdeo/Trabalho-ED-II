#ifndef MERGESORT_H
#define MERGESORT_H
#include "../../classes/review.h"
#include <fstream>

/**
 * mergeSort para vetor de inteiros
 * @author caiosdeo
 * @param vet Vetor de inteiros
 * @param esq Começo do vetor
 * @param dir Fim do vetor
 * @param numComp número de comparações
 * @param numReg número de registros
 * @return void
 */
void mergeSortInteiros(int *vet, int esq, int dir, int *numComp, int *numReg);

/**
 * mergeSort para vetor de reviews
 * @author caiosdeo
 * @param vet Vetor de reviews
 * @param esq Começo do vetor
 * @param dir Fim do vetor
 * @param numComp número de comparações
 * @param numReg número de registros
 * @return void
 */
void mergeSortReviews(Review *r, int esq, int dir, int *numComp, int *numReg);

/**
 * @author caiosdeo
 * @param vet Vetor de inteiros
 * @param esq início da vetor
 * @param med meio do vetor
 * @param dir fim da vetor
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return void
 */
void mergeInteiros(int *vet, int esq, int med, int dir, int *numComp, int *numReg);

/**
 * @author caiosdeo
 * @param vet Vetor de reviews
 * @param esq início da vetor
 * @param med meio do vetor
 * @param dir fim da vetor
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return void
 */
void mergeReviews(Review *r, int esq, int med, int dir, int *numComp, int *numReg);

#endif // MERGESORT_H
