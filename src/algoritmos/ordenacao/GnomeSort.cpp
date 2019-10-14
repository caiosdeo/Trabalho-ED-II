#include "GnomeSort.h"
#include "quickSortRecursivo.h"

void gnomeSort(unsigned *v, unsigned n, unsigned long long *numComparacoes, unsigned long long *numTrocas){ 

    unsigned id = 0; 
  
    // Para do laço - vetor inteiramente percorrido  
    while(id < n){ 

        if (id == 0) 
            id++; 

        (*numComparacoes)++;
        // Compara posição atual com anterior e incrementa em caso positivo
        if (v[id] >= v[id - 1]) 
            id++; 

        else{ 

            (*numTrocas)++;
            // Troca elementos da posição atual com a anterior
            swap(&v[id], &v[id - 1]); 
            id--;
             
        } 

    } 

} 