#ifndef MERGESORT_H
#define MERGESORT_H
#include <fstream>

/**
 * @author AndreCasarim
 * @param a vetor de inteiros sem sinal
 * @param inicio início da partição
 * @param fim fim da partição
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return void
 */
void mergeSort(unsigned *vet, unsigned esq, unsigned dir, unsigned long long *numComp, unsigned long long *numReg);

void merge(unsigned *vet, unsigned esq, unsigned med, unsigned dir, unsigned long long *numComp, unsigned long long *numReg);

#endif // MERGESORT_H
