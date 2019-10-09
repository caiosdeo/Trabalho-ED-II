#include "../../classes/review.h"
#include "quickSortRecursivo.h"
#include <iostream>

// Swap function
void swap(unsigned *a, unsigned i, unsigned j){

    unsigned aux;

    aux = a[i];
    a[i] = a[j];
    a[j] = aux;


}

// Quick Sort

// Partição para ids
unsigned particaoIds(unsigned *a, unsigned inicio, unsigned fim, unsigned *numComparacoes, unsigned *numTrocas){

    unsigned pivo = a[fim];
    unsigned i = inicio - 1;

    for(unsigned j = inicio; j < fim; j++){

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
void quickSortRecursivoIds(unsigned *a, unsigned inicio, unsigned fim, unsigned *numComparacoes, unsigned *numTrocas){

    if(inicio < fim){

        unsigned pivo = particaoIds(a, inicio, fim, numComparacoes, numTrocas);
        if(pivo != 0)
            quickSortRecursivoIds(a, inicio, pivo-1, numComparacoes, numTrocas);
        if(pivo != fim)
            quickSortRecursivoIds(a, pivo+1, fim, numComparacoes, numTrocas);

    }

}

// Swap para estruturas
void swapEstruturas(Review* a, unsigned i, unsigned j){

    Review aux;

    aux = a[i];
    a[i] = a[j];
    a[j] = aux;

}

// particao para estruturas
unsigned particaoEstruturas(Review* a, unsigned inicio, unsigned fim, unsigned *numComparacoes, unsigned *numTrocas){

    unsigned pivo = a[fim].getId();
    unsigned i = inicio - 1;

    for(unsigned j = inicio; j < fim; j++){

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
void quickSortRecursivoEstruturas(Review* a, unsigned inicio, unsigned fim, unsigned *numComparacoes, unsigned *numTrocas){

    if(inicio < fim){

        unsigned pivo = particaoEstruturas(a, inicio, fim, numComparacoes, numTrocas);
        if(pivo != 0)
            quickSortRecursivoEstruturas(a, inicio, pivo-1, numComparacoes, numTrocas);
        if(pivo != fim)
            quickSortRecursivoEstruturas(a, pivo+1, fim, numComparacoes, numTrocas);

    }

}