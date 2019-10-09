#include "InsertionSort.h"
#include <fstream>

using namespace std;

/// Funcao Insertion Sort para vetor de unsignedeiros de tamanho size
void insertionSort(unsigned *vet, unsigned size, unsigned *numComp, unsigned *numReg)
{
    unsigned i, chave, j;
    for(i = 1; i < size; i++){

        chave = vet[i]; //copiando elemento i
        j = i-1;

        (*numReg)++; //atualiza numero de copias de registro
        (*numComp)++; //atualiza numero de comparacoes

        // copiando elementos de j para j+1
        while(j >= 0 && vet[j] > chave){

            vet[j+1] = vet[j];
            j--;
            (*numComp)++;
            (*numReg)++;

        }

        vet[j+1] = chave; // copia elemento i a j+1
        (*numReg)++;
    }

}
