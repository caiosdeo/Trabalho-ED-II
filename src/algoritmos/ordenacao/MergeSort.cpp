#include "MergeSort.h"
#include <fstream>

using namespace std;

/// Funcao auxiliar merge
void merge(int *vet, int esq, int med, int dir, int *numComp, int *numReg){

    int i, j, k;
    int tamE = med - esq + 1;
    int tamD = dir - med;

    //Vetores temporários
    int E[tamE], D[tamD];

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
    // Intercalando os vetores temporários
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


///Funcao merge sort para vetor de inteiros de tamanho esq a dir
void mergeSort(int *vet, int esq, int dir, int *numComp, int *numReg){

    if(esq < dir){

        // media entre esq e dir
        int med = (esq + dir)/2;

        mergeSort(vet, esq, med, numComp, numReg);
        mergeSort(vet, med+1, dir, numComp, numReg);

        merge(vet, esq, med, dir, numComp, numReg);
    }

}
