#include "quickSortMediano.h"
#include "quickSortRecursivo.h"
#include <iostream>

using namespace std;

int* gerarVetor(int* v, int k){

    int aux[k];
    
    for(int i = 0; i < k; i++ )
        aux[i] = v[i];

    return aux;

}

int medianadek(int* vetor, int k, int* trocas, int *comparacoes){

    quickSortRecursivoIds(vetor, 0, k-1, comparacoes, trocas);

    int mediana = k/2;

    return mediana;

}

void quickSortMediano(int *vetor, int inicio, int fim, int k, int *trocas, int *comparacoes) {

    if (fim - inicio < k) {
        
        int pivo = particaoIds(vetor, inicio, fim, comparacoes, trocas);
        
        quickSortMediano(vetor, inicio, pivo - 1, k, trocas, comparacoes);
        quickSortMediano(vetor, pivo + 1, fim, k, trocas, comparacoes);

    }else {

        int* aux = gerarVetor(vetor, k);
        int mediana = medianadek(aux, k, trocas, comparacoes);

        (*trocas)++;
        swap(vetor, mediana, fim);

        int pivo = particaoIds(vetor, inicio, fim, comparacoes, trocas);
        
        quickSortMediano(vetor, inicio, pivo - 1, k, trocas, comparacoes);
        quickSortMediano(vetor, pivo + 1, fim, k, trocas, comparacoes);
    
    }

}