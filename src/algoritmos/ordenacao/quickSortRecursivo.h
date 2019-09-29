#include "../../classes/review.h"

// Monta o vetor de ids
/**
 * Atribuição de dados a cada conjunto, retornando-o em um vetor.
 *
 * @author eliascassis
 * @param review Vetor de reviews
 * @param n Tamanho do conjunto
 * @return vetorIds Vetor com os ids do jogo.
 */
int* fazerVetorIds(Review* review, int n);

// Swap function
/**
 * @author eliascassis
 * @param a Vetor de inteiros
 * @param i posição i
 * @param j posição j
 * @return void
 */
void swap(int *a, int i, int j);

// Quick Sort
// Partição para ids
/**
 * @author eliascassis
 * @param a Vetor de inteiros
 * @param inicio início da partição
 * @param fim fim da partição
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return i+1 id do novo pivô
 */
int particaoIds(int *a, int inicio, int fim, unsigned long long int *numComparacoes, unsigned long long int *numTrocas);

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
void quickSortRecursivoIds(int *a, int inicio, int fim, unsigned long long int *numComparacoes, unsigned long long int *numTrocas);

// Swap para estruturas
/**
 * @author eliascassis
 * @param a Vetor de reviews
 * @param i posição i
 * @param j posição j
 * @return void
 */
void swapEstruturas(Review* a, int i, int j);

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
int particaoEstruturas(Review* a, int inicio, int fim, unsigned long long int *numComparacoes, unsigned long long int *numTrocas);

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

void quickSortRecursivoEstruturas(Review* a, int inicio, int fim, unsigned long long int *numComparacoes, unsigned long long int *numTrocas);