#include <iostream>
#include "quickSortInsertion.h"
#include "InsertionSort.h"
#include "quickSortRecursivo.h"
using namespace std;


void insertionQuickSort(int *a, int inicio, int fim, int *numComparacoes, int *numTrocas)
{

		if(fim - inicio < 10)
		{
			insertionSortInteiros(a, fim-inicio, numComparacoes, numTrocas);
		}
		else 
		{
			int pivo = particaoIds(a, inicio, fim, numComparacoes, numTrocas);
        	quickSortRecursivoIds(a, inicio, pivo-1, numComparacoes, numTrocas);
        	quickSortRecursivoIds(a, pivo+1, fim, numComparacoes, numTrocas);
		}	
}

void insertionQuickSortReview(Review *r, int inicio, int fim, int *numComparacoes, int *numTrocas){
	if(fim - inicio < 10)
	{
		insertionSortReviews(r, fim-inicio, numComparacoes, numTrocas);
	}
	else 
	{
		int pivo = particaoEstruturas(r, inicio, fim, numComparacoes, numTrocas);
        quickSortRecursivoEstruturas(r, inicio, pivo-1, numComparacoes, numTrocas);
        quickSortRecursivoEstruturas(r, pivo+1, fim, numComparacoes, numTrocas);
	}	
}