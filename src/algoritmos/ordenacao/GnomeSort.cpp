#include "GnomeSort.h"
#include "quickSortRecursivo.h"

void gnomeSort(int *v, int n, unsigned long *numComparacoes, unsigned long *numTrocas){ 

    int id = 0; 
  
    while(id < n){ 

        if (id == 0) 
            id++; 

        (*numComparacoes)++;
        if (v[id] >= v[id - 1]) 
            id++; 

        else{ 

            (*numTrocas)++;
            swap(v, id, id - 1); 
            id--;
             
        } 

    } 

} 