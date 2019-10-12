#include "InsertionSort.h"
#include <fstream>

using namespace std;

/// Funcao Insertion Sort para vetor de unsigned de tamanho size
void insertionSort(unsigned *vet, unsigned size, unsigned long long *numComp, unsigned long long *numReg)
{
    int chave, j;
    for(unsigned i = 1; i < size; i++){

        chave = vet[i]; //copiando elemento i

        // copiando elementos de j para j+1
        for(j = i-1; j >= 0 && vet[j] > chave; j--){
            
            (*numReg)++;
            (*numComp)+=2;
            vet[j+1] = vet[j];

        }

        vet[j+1] = chave; // copia elemento i a j+1
        (*numReg)++;

    }

}
