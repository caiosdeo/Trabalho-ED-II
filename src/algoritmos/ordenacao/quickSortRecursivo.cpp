#include "../../classes/review.h"
#include "quickSortRecursivo.h"
#include <iostream>

// Swap function
void swap(unsigned *i, unsigned *j){

    unsigned aux;

    aux = *i;
    *i = *j;
    *j = aux;

}

// Quick Sort

// Partição para ids
unsigned particaoIds(unsigned *a, unsigned inicio, unsigned fim, unsigned long long *numComparacoes, unsigned long long *numTrocas){

    // Pega um pivô aleatório
    srand(time(0));
    unsigned pivo = a[rand()%(fim - inicio) + inicio];
    // Coloca pivo no fim da partição
    swap(&a[pivo], &a[fim]);
    (*numTrocas)++; // Incrementa o número de trocas
    // i recebe decremento do início
    unsigned i = inicio - 1;

    // Loop de particionamento
    for(int j = inicio; j < fim; j++){

        // Troca a posição do elemento caso seja menor ou igual ao pivô
        (*numComparacoes)++;
        if(a[j] <= pivo){

            i++;
            swap(&a[i], &a[j]);
            (*numTrocas)++; // Incrementa o número de trocas

        }

    }

    swap(&a[i+1], &a[fim]); // Joga o novo pivô para o fim da partição
    (*numTrocas)++; // Incrementa o número de trocas
    return i+1; // Atualiza o pivô

}

// quickSortRecursivo para ids
void quickSortRecursivoIds(unsigned *a, unsigned inicio, unsigned fim, unsigned long long *numComparacoes, unsigned long long *numTrocas){

    // Parada da recursão
    if(inicio < fim){

        // Pivo da partição
        unsigned pivo = particaoIds(a, inicio, fim, numComparacoes, numTrocas);
        // Chama quickSort para valores menores que pivo
        quickSortRecursivoIds(a, inicio, pivo-1, numComparacoes, numTrocas);
        // Chama quickSort para valores maiores que pivo
        quickSortRecursivoIds(a, pivo+1, fim, numComparacoes, numTrocas);

    }

    return;

}

// Swap para estruturas
void swapEstruturas(Review* a, unsigned i, unsigned j){

    Review aux;

    aux = a[i];
    a[i] = a[j];
    a[j] = aux;

}

// particao para estruturas
unsigned particaoEstruturas(Review* a, unsigned inicio, unsigned fim, unsigned long long *numComparacoes, unsigned long long *numTrocas){

    // Pega um pivô aleatório
    srand(time(0));
    unsigned pivo = a[rand()%(fim - inicio) + inicio].getId();
    // Coloca pivo no fim da partição
    swapEstruturas(a, pivo, fim);
    (*numTrocas)++; // Incrementa o número de trocas
    // i recebe decremento do início
    unsigned i = inicio - 1; 

    // Loop de particionamento
    for(int j = inicio; j < fim; j++){

        // Troca a posição do elemento caso seja menor ou igual ao pivô
        (*numComparacoes)++;
        if(a[j].getId() <= pivo){

            i++;
            swapEstruturas(a, i, j);
            (*numTrocas)++; // Incrementa o número de trocas

        }

    }
    // Joga o novo pivô para o fim da partição
    swapEstruturas(a, i+1, fim);
    (*numTrocas)++; // Incrementa o número de trocas
    return i+1; // Atualiza o pivô

}

// quickSortRecursivo para estruturas
void quickSortRecursivoEstruturas(Review* a, unsigned inicio, unsigned fim, unsigned long long *numComparacoes, unsigned long long *numTrocas){

    // Parada da recursão
    if(inicio < fim){

        // Pivo da partição
        unsigned pivo = particaoEstruturas(a, inicio, fim, numComparacoes, numTrocas);
        // Chama quickSort para valores menores que pivo
        quickSortRecursivoEstruturas(a, inicio, pivo-1, numComparacoes, numTrocas);
        // Chama quickSort para valores maiores que pivo
        quickSortRecursivoEstruturas(a, pivo+1, fim, numComparacoes, numTrocas);

    }

    return;

}