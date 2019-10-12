#include <iostream>
#include "quickSortInsertion.h"
#include "InsertionSort.h"
#include "quickSortRecursivo.h"
using namespace std;


void insertionQuickSort(unsigned *a, unsigned inicio, unsigned fim, unsigned m, unsigned long long *numComparacoes, unsigned long long *numTrocas)
{

		if(fim - inicio < m)
			insertionSort(a, fim-inicio, numComparacoes, numTrocas);

		else
			quickSortRecursivoIds(a, inicio, fim, numComparacoes, numTrocas);

}
