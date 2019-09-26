#ifndef MERGESORT_H
#define MERGESORT_H
#include <fstream>

void mergeSort(int *vet, int esq, int dir, int *numComp, int *numReg);

void merge(int *vet, int esq, int med, int dir, int *numComp, int *numReg);

#endif // MERGESORT_H
