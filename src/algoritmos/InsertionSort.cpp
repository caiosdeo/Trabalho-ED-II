#include "InsertionSort.h"
#include "../classes/review.h"
#include <fstream>

using namespace std;

void insertionSort(int *vet, int size, int *numComp, int *numReg)
{
    int i, ch, j;
    for(i = 1; i < size; i++){

        ch = vet[i];
        j = i-1;
        
        (*numComp)++;

        while(j >= 0 && vet[j] > ch){

            vet[j+1] = vet[j];
            j--;
            (*numComp)++;
            (*numReg)++;

        }
        
        vet[j+1] = ch;
        (*numReg)++;
    
    }

}


void insertionSortReviews(Review *r, int size, int *numComp, int *numReg){

    for(int i = 1; i < size; i++){

        Review pivo = r[i];
        int j = i-1;

        (*numComp)++;

        while(j >= 0 && r[j].getId() > pivo.getId()){

            r[j+1] = r[j];
            j--;
            (*numComp)++;
            (*numReg)++;

        }

        r[j+1] = pivo;
        (*numReg)++;
    }

}
