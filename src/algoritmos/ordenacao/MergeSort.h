#ifndef MERGESORT_H
#define MERGESORT_H
#include <fstream>

void mergeSort(int *vet, int esq, int dir, unsigned long *numComp, unsigned long *numReg);

void merge(int *vet, int esq, int med, int dir, unsigned long *numComp, unsigned long *numReg);

#endif // MERGESORT_H
