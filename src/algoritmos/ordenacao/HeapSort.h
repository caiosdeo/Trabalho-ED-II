#ifndef HEAPSORT_H
#define HEAPSORT_H

/**
 * Constrói uma heap de máximo
 * 
 * @author Developer-Hannya
 * @param id vetor de inteiros sem sinal
 * @param tam tamanho do vetor
 * @param indice indice para construção da heap
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return void
 */
void heapify(unsigned *id, unsigned tam, unsigned indice, unsigned long long *trocas, unsigned long long *comparacoes);

/**
 * Ordenação heap sort
 * 
 * @author Developer-Hannya
 * @param id vetor de inteiros sem sinal
 * @param tam tamanho do vetor
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return void
 */
void heapSort(unsigned *id, unsigned tam, unsigned long long *trocas, unsigned long long *comparacoes);

#endif // HEAPSORT_H
