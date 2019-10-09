#include <iostream>
#include "quickSortInsertion.h"
#include "InsertionSort.h"
#include "quickSortRecursivo.h"
using namespace std;


void insertionQuickSort(unsigned *a, unsigned inicio, unsigned fim, unsigned m, unsigned *numComparacoes, unsigned *numTrocas)
{

		if(fim - inicio < m)
		{
			insertionSort(a, fim-inicio, numComparacoes, numTrocas);
		}
		else
		{
			unsigned pivo = particaoIds(a, inicio, fim, numComparacoes, numTrocas);
        	quickSortRecursivoIds(a, inicio, pivo-1, numComparacoes, numTrocas);
        	quickSortRecursivoIds(a, pivo+1, fim, numComparacoes, numTrocas);
		}
}
