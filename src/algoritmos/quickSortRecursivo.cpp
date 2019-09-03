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

int partition(int *a, int start, int end, int *nComparisons, int *nSwaps){

    int pivot = a[end];
    int i = start - 1;

    for(int j = start; j < end; j++){

        (*nComparisons)++;
        if(a[j] <= pivot){

            i++;
            swap(a, i, j);
            (*nSwaps)++;

        }

    }

    swap(a, i+1, end);
    (*nSwaps)++;
    return i+1;

}

void quickSortRecursivo(int *a, int start, int end, int *nComparisons, int *nSwaps){

    if(start < end){

        int part = partition(a, start, end, nComparisons, nSwaps);
        quickSortRecursivo(a, start, part-1, nComparisons, nSwaps);
        quickSortRecursivo(a, part+1, end, nComparisons, nSwaps);

    }

}