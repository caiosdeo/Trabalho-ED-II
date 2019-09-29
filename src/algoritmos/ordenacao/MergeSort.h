#ifndef MERGESORT_H
#define MERGESORT_H
#include <fstream>

void mergeSort(int *vet, int esq, int dir, unsigned long long int *numComp, unsigned long long int *numReg);

void merge(int *vet, int esq, int med, int dir, unsigned long long int *numComp, unsigned long long int *numReg);

#endif // MERGESORT_H
