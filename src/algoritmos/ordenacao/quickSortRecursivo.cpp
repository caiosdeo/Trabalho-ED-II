#include "../../classes/review.h"
#include "quickSortRecursivo.h"
#include <iostream>

// Swap function
void swap(int *a, int i, int j){

    int aux;

    aux = a[i];
    a[i] = a[j];
    a[j] = aux;


}

// Quick Sort

// Partição para ids
int particaoIds(int *a, int inicio, int fim, unsigned long long int *numComparacoes, unsigned long long int *numTrocas){

    int pivo = a[fim];
    int i = inicio - 1;

    for(int j = inicio; j < fim; j++){

        (*numComparacoes)++;
        if(a[j] <= pivo){

            i++;
            swap(a, i, j);
            (*numTrocas)++;

        }

    }

    swap(a, i+1, fim);
    (*numTrocas)++;
    return i+1;

}

// quickSortRecursivo para ids
void quickSortRecursivoIds(int *a, int inicio, int fim, unsigned long long int *numComparacoes, unsigned long long int *numTrocas){

    if(inicio < fim){

        int pivo = particaoIds(a, inicio, fim, numComparacoes, numTrocas);
        quickSortRecursivoIds(a, inicio, pivo-1, numComparacoes, numTrocas);
        quickSortRecursivoIds(a, pivo+1, fim, numComparacoes, numTrocas);

    }

}

// Swap para estruturas
void swapEstruturas(Review* a, int i, int j){

    Review aux;

    aux = a[i];
    a[i] = a[j];
    a[j] = aux;

}

// particao para estruturas
int particaoEstruturas(Review* a, int inicio, int fim, unsigned long long int *numComparacoes, unsigned long long int *numTrocas){

    int pivo = a[fim].getId();
    int i = inicio - 1;

    for(int j = inicio; j < fim; j++){

        (*numComparacoes)++;
        if(a[j].getId() <= pivo){

            i++;
            swapEstruturas(a, i, j);
            (*numTrocas)++;

        }

    }

    swapEstruturas(a, i+1, fim);
    (*numTrocas)++;
    return i+1;

}

// quickSortRecursivo para estruturas
void quickSortRecursivoEstruturas(Review* a, int inicio, int fim, unsigned long long int *numComparacoes, unsigned long long int *numTrocas){

    if(inicio < fim){

        int pivo = particaoEstruturas(a, inicio, fim, numComparacoes, numTrocas);
        quickSortRecursivoEstruturas(a, inicio, pivo-1, numComparacoes, numTrocas);
        quickSortRecursivoEstruturas(a, pivo+1, fim, numComparacoes, numTrocas);

    }

}