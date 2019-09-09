#include <iostream>
#include "quickSortInsertion.h"
#include "InsertionSort.h"
#include "quickSortRecursivo.h"
using namespace std;

// Number of elements to be sorted
#define N 1000000

// Number of sorting runs
#define NUM 10



void swapReview(Review* a, int i, int j){

    Review aux;

    aux = a[i];
    a[i] = a[j];
    a[j] = aux;

}

void insertionSortReview(Review *r, int low, int n)
{
	// Start from second element (element at index 0 
	// is already sorted)
	for (int i = low + 1; i <= n; i++) 
	{
		Review value = r[i];
		int j = i;
		
		// Find the index j within the sorted subset arr[0..i-1]
		// where element arr[i] belongs
		while (j > low && r[j - 1].getId() > value.getId()) 
		{
			r[j] = r[j - 1];
			j--;
		}
		// Note that subarray arr[j..i-1] is shifted to
		// the right by one position i.e. arr[j+1..i]
		
		r[j] = value;
	}
}
 
int partition(int a[], int low, int high)
{
	// Pick rightmost element as pivot from the array
	int pivot = a[high];

	// elements less than pivot will be pushed to the left of pIndex
	// elements more than pivot will be pushed to the right of pIndex
	// equal elements can go either way
	int pIndex = low;	
	
	// each time we finds an element less than or equal to pivot, pIndex
	// is incremented and that element would be placed before the pivot. 
	for (int i = low; i < high; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}
	// swap pIndex with Pivot
	swap (a[pIndex], a[high]);
	
	// return pIndex (index of pivot element)
	return pIndex;
}
int partitionReview(Review *r, int low, int high)
{
	// Pick rightmost element as pivot from the array
	Review pivot = r[high];

	// elements less than pivot will be pushed to the left of pIndex
	// elements more than pivot will be pushed to the right of pIndex
	// equal elements can go either way
	int pIndex = low;	
	
	// each time we finds an element less than or equal to pivot, pIndex
	// is incremented and that element would be placed before the pivot. 
	for (int i = low; i < high; i++)
	{
		if (r[i].getId() <= pivot.getId())
		{
			swapReview(r, i, pIndex);
			pIndex++;
		}
	}
	// swap pIndex with Pivot
	swapReview(r, pIndex, high);
	
	// return pIndex (index of pivot element)
	return pIndex;
}

void insertionQuickSort(int a[], int low, int high)
{
	while (low < high) 
	{
		// do insertion sort if 10 or smaller
		if(high - low < 10)
		{
			insertionSort(a, low, high);
			break;
		}
		else 
		{
			int pivot = partition(a, low, high);
			
			// tail call optimizations - recur on smaller sub-array
			if (pivot - low < high - pivot) {
				insertionQuickSort(a, low, pivot - 1);
				low = pivot + 1;
			} else {
				insertionQuickSort(a, pivot + 1, high);
				high = pivot - 1;
			}
		}
	}	
}

void insertionQuickSortReview(Review *r, int low, int high)
{
	while (low < high) 
	{
		// do insertion sort if 10 or smaller
		if(high - low < 10)
		{
			insertionSortReview(r, low, high);
			break;
		}
		else 
		{
			int pivot = partitionReview(r, low, high);
			
			// tail call optimizations - recur on smaller sub-array
			if (pivot - low < high - pivot) {
				insertionQuickSortReview(r, low, pivot - 1);
				low = pivot + 1;
			} else {
				insertionQuickSortReview(r, pivot + 1, high);
				high = pivot - 1;
			}
		}
	}	
}