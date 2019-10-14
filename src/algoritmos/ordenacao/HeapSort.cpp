#include "HeapSort.h"
#include "quickSortRecursivo.h"

// Constrói uma max Heap
void heapify(unsigned *id, unsigned tam, unsigned indice, unsigned long long *trocas, unsigned long long *comparacoes) {
    
    unsigned maior = indice; // Pai
    unsigned esq = 2*indice + 1; // Filho da esquerda
    unsigned dir = 2*indice + 2; // FIlho da direita

    (*comparacoes)+=2;
    // Atualiza maior valor se necessário
    if (esq < tam && id[esq] > id[maior]) {
        maior = esq;
    }

    (*comparacoes)+=2;
    // Atualiza maior valor se necessário
    if (dir < tam && id[dir] > id[maior]) {
        maior = dir;
    }

    // Confere se o maior não é o pai
    if (maior != indice) {

        swap(&id[indice], &id[maior]); // Troca pai com o maior filho
        (*trocas)++;
        heapify(id, tam, maior, trocas, comparacoes); // Chama heapfy
    }

}

void heapSort(unsigned *id, unsigned tam, unsigned long long *trocas, unsigned long long *comparacoes) {
    // Constrói max Heap
    for (int i = tam / 2-1; i >= 0; i--)
        heapify(id, tam, i, trocas, comparacoes);

    // Extrai, um por um, os elementos da heap
    for (int i = tam-1; i >= 0; i--){

        // Move o atual para o fim
        swap(&id[0], &id[i]);
        (*trocas)++;

        // Chama o max Heapfy para a heap reduzida
        heapify(id, i, 0, trocas, comparacoes);
    }

}
