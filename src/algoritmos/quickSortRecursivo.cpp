#include "../classes/review.h"

// Monta o vetor de ids
/**
 * Atribuição de dados a cada conjunto, retornando-o em um vetor.
 *
 * @author eliascassis
 * @param review Vetor de reviews
 * @param n Tamanho do conjunto
 * @return vetorIds Vetor com os ids do jogo.
 */
int* fazerVetorIds(Review* review, int n){

    int* vetorIds = new int(n);

    for(int i = 0; i < n; i++)
        vetorIds[i] = review[i].getId();

}

// Swap function
/**
 * @author eliascassis
 * @param a Vetor de inteiros
 * @param i posição i
 * @param j posição j
 * @return void
 */
void swap(int *a, int i, int j){

    int aux;

    aux = a[i];
    a[i] = a[j];
    a[j] = aux;

}

// Quick Sort
/**
 * @author eliascassis
 * @param a Vetor de inteiros
 * @param inicio início da partição
 * @param fim fim da partição
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return i+1 id do novo pivô
 */
int particao(int *a, int inicio, int fim, int *numComparacoes, int *numTrocas){

    int pivo = a[fim];
    int i = inicio - 1;

    for(int j = inicio; j < fim; j++){

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
// quickSortRecursivo
/**
 * @author eliascassis
 * @param a Vetor de inteiros
 * @param inicio início da partição
 * @param fim fim da partição
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return void
 */
void quickSortRecursivo(int *a, int inicio, int fim, int *numComparacoes, int *numTrocas){

    if(inicio < fim){

        int pivo = particao(a, inicio, fim, numComparacoes, numTrocas);
        quickSortRecursivo(a, inicio, pivo-1, numComparacoes, numTrocas);
        quickSortRecursivo(a, pivo+1, fim, numComparacoes, numTrocas);

    }

}