#include <fstream>

/**
 * @author PaulaRRP
 * @param a vetor de inteiros sem sinal
 * @param inicio início da partição
 * @param fim fim da partição
 * @param m tamanho da partição para chamada do insertionSort
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return void
 */
void insertionQuickSort(unsigned *a, unsigned inicio, unsigned fim, unsigned m, unsigned long long *numComparacoes, unsigned long long *numTrocas);
