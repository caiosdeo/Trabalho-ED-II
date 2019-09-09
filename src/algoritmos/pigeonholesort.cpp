#include <bits/stdc++.h> 
#include "pigeonholesort.h"
using namespace std; 
  
/* Sorts the array using pigeonhole algorithm */
void pigeonholeSort(int arr[], int n) 
{ 
    // Find minimum and maximum values in arr[] 
    int min = arr[0], max = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        if (arr[i] < min) 
            min = arr[i]; 
        if (arr[i] > max) 
            max = arr[i]; 
    } 
    int range = max - min + 1; // Find range 
  
    // Create an array of vectors. Size of array 
    // range. Each vector represents a hole that 
    // is going to contain matching elements. 
    vector<int> holes[range]; 
  
    // Traverse through input array and put every 
    // element in its respective hole 
    for (int i = 0; i < n; i++) 
        holes[arr[i]-min].push_back(arr[i]); 
  
    // Traverse through all holes one by one. For 
    // every hole, take its elements and put in 
    // array. 
    int index = 0;  // index in sorted array 
    for (int i = 0; i < range; i++) 
    { 
       vector<int>::iterator it; 
       for (it = holes[i].begin(); it != holes[i].end(); ++it) 
            arr[index++]  = *it; 
    } 
} 


void pigeonholeSortReview(Review *r, int n) 
{ 
    // Find minimum and maximum values in arr[] 
    Review min = r[0], max = r[0]; 
    for (int i = 1; i < n; i++) 
    { 
        if (r[i].getId() < min.getId()) 
            min = r[i]; 
        if (r[i].getId() > max.getId()) 
            max = r[i]; 
    } 
    int range = max.getId() - min.getId() + 1; // Find range 
  
    // Create an array of vectors. Size of array 
    // range. Each vector represents a hole that 
    // is going to contain matching elements. 
    vector<Review> holes[range]; 
  
    // Traverse through input array and put every 
    // element in its respective hole 
    for (int i = 0; i < n; i++) 
        holes[r[i].getId()-min.getId()].push_back(r[i]); 
  
    // Traverse through all holes one by one. For 
    // every hole, take its elements and put in 
    // array. 
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
  
    pigeonholeSort(arr, n); 
  
    printf("Sorted order is : "); 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
  
    return 0; 
} 