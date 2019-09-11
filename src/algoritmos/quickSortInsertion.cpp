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

/*
int main() 
{ 
    int arr[] = {8, 3, 2, 7, 4, 6, 8}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
	int numComparacoes = 0;
	int numTrocas = 0;
  
    insertionQuickSort(arr, 0, n, &numComparacoes, &numTrocas);
  
    printf("Sorted order is : "); 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
  
    return 0; 
}
*/