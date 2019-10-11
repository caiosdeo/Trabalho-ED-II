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
unsigned* fazerVetorIds(Review* review, unsigned n);

// Swap function
/**
 * @author eliascassis
 * @param a Vetor de unsigned
 * @param i posição i
 * @param j posição j
 * @return void
 */
void swap(unsigned *i, unsigned *j);

// Quick Sort
// Partição para ids
/**
 * @author eliascassis
 * @param a Vetor unsigned
 * @param inicio início da partição
 * @param fim fim da partição
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return i+1 id do novo pivô
 */
unsigned particaoIds(unsigned *a, unsigned inicio, unsigned fim, unsigned long long *numComparacoes, unsigned long long *numTrocas);

// quickSortRecursivo para ids
/**
 * @author eliascassis
 * @param a Vetor unsigned
 * @param inicio início da partição
 * @param fim fim da partição
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return void
 */
void quickSortRecursivoIds(unsigned *a, unsigned inicio, unsigned fim, unsigned long long *numComparacoes, unsigned long long *numTrocas);

// Swap para estruturas
/**
 * @author eliascassis
 * @param a Vetor de reviews
 * @param i posição i
 * @param j posição j
 * @return void
 */
void swapEstruturas(Review* a, unsigned i, unsigned j);

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
unsigned particaoEstruturas(Review* a, unsigned inicio, unsigned fim, unsigned long long *numComparacoes, unsigned long long *numTrocas);

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

void quickSortRecursivoEstruturas(Review* a, unsigned inicio, unsigned fim, unsigned long long *numComparacoes, unsigned long long *numTrocas);