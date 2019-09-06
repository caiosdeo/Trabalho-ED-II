#include <iostream>
using namespace std;

// Number of elements to be sorted
#define N 1000000

// Number of sorting runs
#define NUM 10


// print the array
void printArray(int a[], int tam) 
{ 
    for (int i=0; i<tam; ++i) 
        printf("%i  ", a[i]);
    printf("\n");
} 

// perform insertion sort on arr[]
void insertionSort(int arr[], int low, int n)
{
	// Start from second element (element at index 0 
	// is already sorted)
	for (int i = low + 1; i <= n; i++) 
	{
		int value = arr[i];
		int j = i;
		
		// Find the index j within the sorted subset arr[0..i-1]
		// where element arr[i] belongs
		while (j > low && arr[j - 1] > value) 
		{
			arr[j] = arr[j - 1];
			j--;
		}
		// Note that subarray arr[j..i-1] is shifted to
		// the right by one position i.e. arr[j+1..i]
		
		arr[j] = value;
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

void insertionQuickSort(int A[], int low, int high)
{
	while (low < high) 
	{
		// do insertion sort if 10 or smaller
		if(high - low < 10)
		{
			insertionSort(A, low, high);
			break;
		}
		else 
		{
			int pivot = partition(A, low, high);
			
			// tail call optimizations - recur on smaller sub-array
			if (pivot - low < high - pivot) {
				insertionQuickSort(A, low, pivot - 1);
				low = pivot + 1;
			} else {
				insertionQuickSort(A, pivot + 1, high);
				high = pivot - 1;
			}
		}
	}	
}

int main()
{
	int arr[N];
	
	// perform Quicksort NUM times and take average
	for(int i = 0; i < NUM; i++)
	{
		// generate random input
		for (int i = 0; i < N; i++)
		    arr[i] = rand() % 100000;

		
		// Perform Optimized Quicksort on arr[]
		insertionQuickSort(arr, 0, N-1);
	}
    printArray(arr, N);

	return 0;
}