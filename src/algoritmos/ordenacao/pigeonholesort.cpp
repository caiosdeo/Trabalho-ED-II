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
