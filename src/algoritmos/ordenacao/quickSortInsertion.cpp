#include <iostream>
#include "quickSortInsertion.h"
#include "InsertionSort.h"
#include "quickSortRecursivo.h"
using namespace std;

// QuickSort utilizando insertion sort para partições de tamanho <= m
void insertionQuickSort(unsigned *a, unsigned inicio, unsigned fim, unsigned m, unsigned long long *numComparacoes, unsigned long long *numTrocas)
{

		// Confere condição para chamada do insertion Sort
		if(fim - inicio < m)
			insertionSort(a, fim-inicio, numComparacoes, numTrocas); // Chama insertion sort

		else
			quickSortRecursivoIds(a, inicio, fim, numComparacoes, numTrocas); // Chama quickSort recursivo

}
