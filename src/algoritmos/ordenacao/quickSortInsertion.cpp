#include <iostream>
#include "quickSortInsertion.h"
#include "InsertionSort.h"
#include "quickSortRecursivo.h"
using namespace std;


void insertionQuickSort(int *a, int inicio, int fim, int m, unsigned long long int *numComparacoes, unsigned long long int *numTrocas)
{

		if(fim - inicio < m)
		{
			insertionSort(a, fim-inicio, numComparacoes, numTrocas);
		}
		else
		{
			int pivo = particaoIds(a, inicio, fim, numComparacoes, numTrocas);
        	quickSortRecursivoIds(a, inicio, pivo-1, numComparacoes, numTrocas);
        	quickSortRecursivoIds(a, pivo+1, fim, numComparacoes, numTrocas);
		}
}
