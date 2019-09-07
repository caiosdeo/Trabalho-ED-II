#include "MergeSort.h"
#include "review.h"
#include <fstream>

using namespace std;

/// implementacao do Merge Sort

/// merge para vetor de inteiros
void MergeSort::mergeV(int *vet, int esq, int med, int dir)
{
    int i, j, k;
    int tamE = med - esq +1, tamD = dir - med;
    int es[tamE], di[tamD];

    for(i = 0; i < tamE; i++) es[i] = vet[esq+i];
    for(j = 0; j < tamD; j++) di[j] = vet[med+1+j];

    for(i=0, j=0, k = esq; i < tamE && j < tamD; k++)
    {
        if(es[i] <= di[j]){vet[k] = es[i]; i++;}
        else {vet[k] = di[j]; j++;}
    }
}

/// Merge para vetor Review
void MergeSort::mergeR(Review *r, int esq, int med, int dir, int *numComp, int *numReg)
{
    int i,j,k = esq;
    int sizeE = med - esq +1, sizeD = dir - med;

    Review *es, *di;
    es = r->leituraDados(NULL, sizeE);
    di = r->leituraDados(NULL, sizeD);

    for(i = 0; i < sizeE; i++) {es[i].setNewInfo(r[esq+i].getUser(), r[esq+i].getRating(), r[esq+i].getId()); *numReg+=1;}
    for(i = 0; j < sizeD; i++) {di[j].setNewInfo(r[med+1+j].getUser(), r[med+1+j].getRating(), r[med+1+j].getId()); *numReg+=1;}

    for(i = 0, j = 0, k = esq; i < sizeE && j < sizeD; k++)
    {
        if(es[i].getId() <= di[j].getId()){r[k].setNewInfo(es[i].getUser(), es[i].getRating(), es[i].getId()); i++;}
        else {r[k].setNewInfo(di[j].getUser(), di[j].getRating(), di[j].getId()); j++;}
        *numComp+=1;
    }
}

void MergeSort::mergeSort(int *vet, Review *r, int esqV, int dirV, int esqR, int dirR, int *numComp, int *numReg)
{
    if(esqV >= 0 && dirV >= 0)
    {
        int medV = esqV + (dirV-esqV)/2;
        mergeSort(vet, r, esqV, medV, -1, -1, numComp, numReg);
        mergeSort(vet, r, medV+1, dirV, -1, -1, numComp, numReg);

        mergeV(vet, esqV, medV, dirV);
    }

    if(esqR >= 0 && dirR >= 0)
    {
        int medR = esqR + (dirR-esqR)/2;
        mergeSort(vet, r, -1, -1, esqR, medR, numComp, numReg);
        mergeSort(vet, r, -1, -1, medR+1, dirR, numComp, numReg);

        mergeR(r, esqR, medR, dirR, numComp, numReg);
    }
}
