#include <iostream>
#include "review.h"
#include <fstream>

using namespace std;

void mergeV(int *vet, int esq, int med, int dir)
{
    int i, j, k;
    int tamE = med - esq +1, tamD = dir - med;
    int es[tamE], di[tamD];

    for(i = 0; i < tamE; i++) es[i] = vet[esq+i];
    for(j = 0; j < tamD; j++) di[j] = vet[med+1+j];

    i=0; j=0;
    for(i=0, j=0, k = esq; i < tamE && j < tamD; k++)
    {
        if(es[i] <= di[j]){vet[k] = es[i]; i++;}
        else {vet[k] = di[j]; j++;}
    }
}

void mergeR(Review *r, int esq, int med, int dir, int *numComp, int *numReg)
{

}

void mergeSort(int *vet, Review *r, int esqV, int dirV, int esqR, int dirR, int *numComp, int *numReg)
{
    if(esqV >= 0 && dirV >= 0)
    {
        int medV = esqV + (dirV-esqV)/2;
        mergeSort(vet, r, esqV, medV, -1, -1, numComp, numReg);
        mergeSort(vet, r, medV+1, dirV, -1, -1, numComp, numReg);

        mergeV(vet, esqV, medV, dirV);
    }
    int medR = esqR + (dirR-esqR)/2;
    mergeSort(vet, r, -1, -1, esqR, medR, numComp, numReg);
    mergeSort(vet, r, -1, -1, medR+1, dirR, numComp, numReg);

    mergeR(r, esqR, medR, dirR, numComp, numReg);
}

