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
int particaoIds(int *a, int inicio, int fim, int *numComparacoes, int *numTrocas){

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
// quickSortRecursivo para ids
/**
 * @author eliascassis
 * @param a Vetor de inteiros
 * @param inicio início da partição
 * @param fim fim da partição
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return void
 */
void quickSortRecursivoIds(int *a, int inicio, int fim, int *numComparacoes, int *numTrocas){

    if(inicio < fim){

        int pivo = particaoIds(a, inicio, fim, numComparacoes, numTrocas);
        quickSortRecursivoIds(a, inicio, pivo-1, numComparacoes, numTrocas);
        quickSortRecursivoIds(a, pivo+1, fim, numComparacoes, numTrocas);

    }

}

// Swap para estruturas
/**
 * @author eliascassis
 * @param a Vetor de reviews
 * @param i posição i
 * @param j posição j
 * @return void
 */
void swapEstruturas(Review** a, int i, int j){

    Review* aux;

    aux = a[i];
    a[i] = a[j];
    a[j] = aux;

}

// particao para estruturas
/**
 * @author eliascassis
 * @param a Vetor de reviews
 * @param inicio início da partição
 * @param fim fim da partição
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return i+1 id do novo pivô
 */
int particaoEstruturas(Review** a, int inicio, int fim, int *numComparacoes, int *numTrocas){

    int pivo = a[fim]->getId();
    int i = inicio - 1;

    for(int j = inicio; j < fim; j++){

        (*numComparacoes)++;
        if(a[j]->getId() <= pivo){

            i++;
            swapEstruturas(a, i, j);
            (*numTrocas)++;

        }

    }

    swapEstruturas(a, i+1, fim);
    (*numTrocas)++;
    return i+1;

}

// quickSortRecursivo para estruturas
/**
 * @author eliascassis
 * @param a Vetor de reviews
 * @param inicio início da partição
 * @param fim fim da partição
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return void
 */
void quickSortRecursivoEstruturas(Review** a, int inicio, int fim, int *numComparacoes, int *numTrocas){

    if(inicio < fim){

        int pivo = particaoEstruturas(a, inicio, fim, numComparacoes, numTrocas);
        quickSortRecursivoEstruturas(a, inicio, pivo-1, numComparacoes, numTrocas);
        quickSortRecursivoEstruturas(a, pivo+1, fim, numComparacoes, numTrocas);

    }

}