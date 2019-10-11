#ifndef MERGESORT_H
#define MERGESORT_H
#include <fstream>

void mergeSort(unsigned *vet, unsigned esq, unsigned dir, unsigned long long *numComp, unsigned long long *numReg);

void merge(unsigned *vet, unsigned esq, unsigned med, unsigned dir, unsigned long long *numComp, unsigned long long *numReg);

#endif // MERGESORT_H
