#include "HeapSort.h"

void trocarId (int a, int b) {
    int aux = a;
    a = b;
    b = aux;
}

void heapify(int *id, int tam, int indice, int *trocas, int *comparacoes) {
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
                trocarId (id[indice], id[maior]);
                (*trocas)++;
                heapify(id, tam, maior, trocas, comparacoes);
            }

        }
void heapSort(int *id, int tam, int *trocas, int *comparacoes) {
    // Build heap (rearrange array)
    for (int i = tam / 2 - 1; i >= 0; i--)
        heapify(id, tam, i, trocas, comparacoes);

    // One by one extract an element from heap
    for (int i=tam-1; i>=0; i--)
    {
        // Move current root to end
        trocarId(id[0], id[i]);

        // call max heapify on the reduced heap
        heapify(id, tam, i, trocas, comparacoes);
    }
}
