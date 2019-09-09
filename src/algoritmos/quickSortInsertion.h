#include "../classes/review.h"
#include <fstream>


void insertionSort(int arr[], int low, int n);
void insertionSortReview(Review *r, int low, int n);
int partition(int a[], int low, int high);
int partitionReview(Review *r, int low, int high);
void insertionQuickSort(int a[], int low, int high);
void insertionQuickSortReview(Review *r, int low, int high);
