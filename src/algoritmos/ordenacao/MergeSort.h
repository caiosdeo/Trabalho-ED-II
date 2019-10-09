#ifndef MERGESORT_H
#define MERGESORT_H
#include <fstream>

void mergeSort(unsigned *vet, unsigned esq, unsigned dir, unsigned *numComp, unsigned *numReg);

void merge(unsigned *vet, unsigned esq, unsigned med, unsigned dir, unsigned *numComp, unsigned *numReg);

#endif // MERGESORT_H
