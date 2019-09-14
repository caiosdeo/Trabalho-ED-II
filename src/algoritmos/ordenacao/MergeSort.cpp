#include "MergeSort.h"
#include "../classes/review.h"
#include <fstream>

using namespace std;

void mergeInteiros(int *vet, int esq, int med, int dir, int *numComp, int *numReg){

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

void mergeReviews(Review *r, int esq, int med, int dir, int *numComp, int *numReg){

    int i, j, k = esq;
    int tamE = med - esq + 1;
    int tamD = dir - med;

    Review E[tamE], D[tamD];

    for(i = 0; i < tamE; i++){
        E[i] = r[esq + i];
        (*numReg)++;
    }
    for(j = 0; j < tamD; j++){
        D[j] = r[med + j + 1];
        (*numReg)++;
    }

    for(i = 0, j = 0, k = esq; i < tamE && j < tamD; k++){

        (*numComp)++;

        if(E[i].getId() <= D[j].getId()){
            r[k] = E[i];
            i++;

        }else{

            r[k] = D[j];
            j++;
        }

        (*numReg)++;
    }

    //Copiando os remanescentes de E
    while (i < tamE){
        r[k] = E[i];
        i++;
        k++;
        (*numReg)++;
    }

    //Copiando os remanescentes de D
    while (j < tamD){
        r[k] = D[j];
        j++;
        k++;
        (*numReg)++;
    }

}

void mergeSortInteiros(int *vet, int esq, int dir, int *numComp, int *numReg){

    if(esq < dir){

        int med = (esq + dir)/2;

        mergeSortInteiros(vet, esq, med, numComp, numReg);
        mergeSortInteiros(vet, med+1, dir, numComp, numReg);

        mergeInteiros(vet, esq, med, dir, numComp, numReg);
    }

}

void mergeSortReviews(Review *r, int esq, int dir, int *numComp, int *numReg){

    if(esq < dir){

        int med = (esq + dir)/2;

        mergeSortReviews(r, esq, med, numComp, numReg);
        mergeSortReviews(r, med+1, dir, numComp, numReg);

        mergeReviews(r, esq, med, dir, numComp, numReg);
    }
}
