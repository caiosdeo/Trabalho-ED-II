#include <bits/stdc++.h> 
#include "pigeonholesort.h"
using namespace std; 
  
/* Sorts the array using pigeonhole algorithm */
void pigeonholeSort(int *a, int inicio, int fim) 
{ 
    // Find minimum and maximum values in a
    int min = a[0], max = a[0]; 
    for (int i = 1; i < (fim-inicio); i++) 
    { 
        if (a[i] < min) 
            min = a[i]; 
        if (a[i] > max) 
            max = a[i]; 
    } 
    int range = max - min + 1; // Find range 
  
    // Create an array of vectors
    vector<int> holes[range]; 
  
    // Traverse through input array and put every 
    // element in its respective hole 
    for (int i = 0; i < (fim-inicio); i++) 
        holes[a[i]-min].push_back(a[i]); 
  
    // Traverse through all holes one by one. For 
    // every hole, take its elements and put in 
    // array. 
    int index = 0;  // index in sorted array 
    for (int i = 0; i < range; i++) 
    { 
       vector<int>::iterator it; 
       for (it = holes[i].begin(); it != holes[i].end(); ++it) 
            a[index++]  = *it; 
    } 
} 


void pigeonholeSortReview(Review *r, int inicio, int fim) 
{ 
    // Find minimum and maximum values in a
    Review min = r[0], max = r[0]; 
    for (int i = 1; i < (fim-inicio); i++) 
    { 
        if (r[i].getId() < min.getId()) 
            min = r[i]; 
        if (r[i].getId() > max.getId()) 
            max = r[i]; 
    } 
    int range = max.getId() - min.getId() + 1; // Find range 
  
    // Create an array of vectors.
    vector<Review> holes[range]; 
  
    for (int i = 0; i < (fim-inicio); i++) 
        holes[r[i].getId()-min.getId()].push_back(r[i]); 
    int index = 0;  // index in sorted array 
    for (int i = 0; i < range; i++) 
    { 
       vector<Review>::iterator it; 
       for (it = holes[i].begin(); it != holes[i].end(); ++it) 
            r[index++]  = *it; 
    } 
} 
  
// Driver program to test the above function 
int main() 
{ 
    int arr[] = {8, 3, 2, 7, 4, 6, 8}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    pigeonholeSort(arr, 0, n); 
  
    printf("Sorted order is : "); 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
  
    return 0; 
} 