#include "MergeSort.h"
#include <fstream>

using namespace std;

/// Funcao auxiliar merge
void merge(unsigned *vet, unsigned esq, unsigned med, unsigned dir, unsigned long long *numComp, unsigned long long *numReg){

    unsigned i, j, k;
    unsigned tamE = med - esq + 1;
    unsigned tamD = dir - med;

    //Vetores temporários
    unsigned E[tamE], D[tamD];

    //Copiando dados para os vetores temporários
    for(i = 0; i < tamE; i++)
    {
        E[i] = vet[esq+i];
        (*numReg)++;
    }
    for(j = 0; j < tamD; j++)
    {
        D[j] = vet[med+1+j];
        (*numReg)++;
    }
    // intercalando os vetores temporários
    for(i = 0, j = 0, k = esq; i < tamE && j < tamD; k++){

        (*numComp)++;
        if(E[i] <= D[j]){

            vet[k] = E[i];
            i++;

        }
        else{

            vet[k] = D[j];
            j++;

        }
        (*numReg)++;
    }

    //Copiando os remanescentes de E
    while (i < tamE){
        vet[k] = E[i];
        i++;
        k++;
        (*numReg)++;
    }

    //Copiando os remanescentes de D
    while (j < tamD){
        vet[k] = D[j];
        j++;
        k++;
        (*numReg)++;
    }

}


///Funcao merge sort para vetor de unsigned de tamanho esq a dir
void mergeSort(unsigned *vet, unsigned esq, unsigned dir, unsigned long long *numComp, unsigned long long *numReg){

    if(esq < dir){

        // media entre esq e dir
        unsigned med = (esq + dir)/2;

        mergeSort(vet, esq, med, numComp, numReg);
        mergeSort(vet, med+1, dir, numComp, numReg);

        merge(vet, esq, med, dir, numComp, numReg);
    }

}
