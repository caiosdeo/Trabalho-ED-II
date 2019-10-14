#ifndef MERGESORT_H
#define MERGESORT_H
#include <fstream>
/**
 * Função de ordenação merge sort
 * 
 * @author AndreCasarim
 * @param vet vetor de inteiros sem sinal
 * @param esq início da partição
 * @param dir fim da partição
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return void
 */
void mergeSort(unsigned *vet, unsigned esq, unsigned dir, unsigned long long *numComp, unsigned long long *numReg);

/**
 * Intercala dois vetores
 * 
 * @author AndreCasarim
 * @param vet vetor de inteiros sem sinal
 * @param esq início da partição
 * @param med meio da partição
 * @param dir fim da partição
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return void
 */
void merge(unsigned *vet, unsigned esq, unsigned med, unsigned dir, unsigned long long *numComp, unsigned long long *numReg);

#endif // MERGESORT_H
