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
    for (unsigned i = tam / 2; i >= 1; i--)
        heapify(id, tam, i, trocas, comparacoes);

    // One by one extract an element from heap
    for (unsigned i = tam/2; i >= 2; i--){

        // Move current root to end
        swap(&id[1], &id[i]);
        (*trocas)++;

        // call max heapify on the reduced heap
        heapify(id, tam - 1, 1, trocas, comparacoes);
    }

}
