#include "HeapSort.h"
#include "quickSortRecursivo.h"

void heapify(int *id, int tam, int indice, unsigned long *trocas, unsigned long *comparacoes) {
    
    int maior = indice;
    int esq = 2*indice + 1;
    int dir = 2*indice + 2;

    (*comparacoes)+=2;
    if (esq < tam && id[esq] > id[maior]) {
        maior = esq;
    }

    (*comparacoes)+=2;
    if (dir < tam && id[dir] > id[maior]) {
        maior = dir;
    }

    if (maior != indice) {

        swap(id, indice, maior);
        (*trocas)++;
        heapify(id, tam, maior, trocas, comparacoes);
    }

}

void heapSort(int *id, int tam, unsigned long *trocas, unsigned long *comparacoes) {
    // Build heap (rearrange array)
    for (int i = tam / 2; i >= 1; i--)
        heapify(id, tam, i, trocas, comparacoes);

    // One by one extract an element from heap
    for (int i = tam/2; i >= 2; i--){

        // Move current root to end
        swap(id, 1, i);
        (*trocas)++;

        // call max heapify on the reduced heap
        heapify(id, tam - 1, 1, trocas, comparacoes);
    }

}
