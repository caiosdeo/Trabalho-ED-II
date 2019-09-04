#include "../classes/review.h"

// Monta o vetor de ids
int* fazerVetorIds(Review* review, int n){

    int* vetorIds = new int(n);

    for(int i = 0; i < n; i++)
        vetorIds[i] = review[i].getId();

}

// Swap function
void swap(int *a, int i, int j){

    int aux;

    aux = a[i];
    a[i] = a[j];
    a[j] = aux;

}

// Quick Sort

int particao(int *a, int inicio, int fim, int *numComparacoes, int *nTrocas){

    int pivo = a[fim];
    int i = inicio - 1;

    for(int j = inicio; j < fim; j++){

        (*numComparacoes)++;
        if(a[j] <= pivo){

            i++;
            swap(a, i, j);
            (*nTrocas)++;

        }

    }

    swap(a, i+1, fim);
    (*nTrocas)++;
    return i+1;

}

void quickSortRecursivo(int *a, int inicio, int fim, int *numComparacoes, int *nTrocas){

    if(inicio < fim){

        int pivo = particao(a, inicio, fim, numComparacoes, nTrocas);
        quickSortRecursivo(a, inicio, pivo-1, numComparacoes, nTrocas);
        quickSortRecursivo(a, pivo+1, fim, numComparacoes, nTrocas);

    }

}