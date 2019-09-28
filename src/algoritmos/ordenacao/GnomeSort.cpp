#include "GnomeSort.h"

void swap(int* v, int a, int b){

    int aux = v[a];
    v[a] = v[b];
    v[b] = v[aux];

}

void gnomeSort(int *v, int n){ 

    int id = 0; 
  
    while(id < n){ 
        if (id == 0) 
            id++; 
        if (v[id] >= v[id - 1]) 
            id++; 
        else { 
            swap(v, id, id - 1); 
            id--; 
        } 
    } 

} 