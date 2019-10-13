#include "HeapSort.h"
#include "quickSortRecursivo.h"

void heapify(unsigned *id, unsigned tam, unsigned indice, unsigned long long *trocas, unsigned long long *comparacoes) {
    
    unsigned maior = indice;
    unsigned esq = 2*indice + 1;
    unsigned dir = 2*indice + 2;

    (*comparacoes)+=2;
    if (esq < tam && id[esq] > id[maior]) {
        maior = esq;
    }

    (*comparacoes)+=2;
    if (dir < tam && id[dir] > id[maior]) {
        maior = dir;
    }

    if (maior != indice) {

        swap(&id[indice], &id[maior]);
        (*trocas)++;
        heapify(id, tam, maior, trocas, comparacoes);
    }

}

void heapSort(unsigned *id, unsigned tam, unsigned long long *trocas, unsigned long long *comparacoes) {
    // Build heap (rearrange array)
    for (int i = tam / 2-1; i >= 0; i--)
        heapify(id, tam, i, trocas, comparacoes);

    // One by one extract an element from heap
    for (int i = tam-1; i >= 0; i--){

        // Move current root to end
        swap(&id[0], &id[i]);
        (*trocas)++;

        // call max heapify on the reduced heap
        heapify(id, i, 0, trocas, comparacoes);
    }

}
