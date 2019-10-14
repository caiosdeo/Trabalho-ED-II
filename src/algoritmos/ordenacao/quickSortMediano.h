#ifndef QUICKSORTMEDIANO_H
#define QUICKSORTMEDIANO_H
#include "../../classes/review.h"

/**
 * Retorna um vetor de k elementos
 *
 * @author caiosdeo
 * @param v Vetor com quantidade de elementos >= k
 * @param inicio Tamanho do conjunto
 * @param k quantidade de elementos
 * @return aux Vetor com k elementos
 */
unsigned* gerarVetor(unsigned* v, unsigned inicio, unsigned k);

/**
 * Calcula a mediana de k elementos
 *
 * @author caiosdeo
 * @param vetor vetor de inteiros sem sinal
 * @param k Tamanho do conjunto
 * @param trocas ponteiro para número de trocas
 * @param comparacoes ponteiro para número de comparações
 * @return mediana 
 */
unsigned medianadek(unsigned *vetor, unsigned k, unsigned long long *trocas, unsigned long long *comparacoes);

/**
 * quickSort com mediana de k elementos
 *
 * @author caiosdeo
 * @param vetor Vetor unsigned
 * @param inicio início da partição
 * @param fim fim da partição
 * @param k quantidade de elementos para cálculo da mediana
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return void
 */
void quickSortMediano(unsigned *vetor, unsigned inicio, unsigned fim, unsigned k, unsigned long long *trocas, unsigned long long *comparacoes);

#endif // QUICKSORTMEDIANO_H
