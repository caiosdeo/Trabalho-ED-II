#include "quickSortMediano.h"
#include "quickSortRecursivo.h"
#include <iostream>

using namespace std;

// Gera um vetor com k elementos da partição
unsigned* gerarVetor(unsigned* v, unsigned inicio, unsigned k){
    
    unsigned *aux = (unsigned*)malloc(k*sizeof(unsigned)); // aloca vetor de tamanho k

    // Insere k elementos no vetor alocado
    for(unsigned i = 0; i < k; i++, inicio++ )
        aux[i] = v[inicio];

    return aux; // Retorna vetor com k elementos

}

// Retorna a mediana de k elementos
unsigned medianadek(unsigned* vetor, unsigned k, unsigned long long* trocas, unsigned long long *comparacoes){

    quickSortRecursivoIds(vetor, 0, k-1, comparacoes, trocas); // ordena os k elementos

    unsigned mediana = vetor[k/2]; // Pega a mediana

    return mediana; // Retorna a mediana

}

// quickSort que utiliza como pivo a mediana de k elementos da partição
void quickSortMediano(unsigned *vetor, unsigned inicio, unsigned fim, unsigned k, unsigned long long *trocas, unsigned long long *comparacoes) {


    // Parada da recursão
    if(inicio < fim){

        // Conferindo condição de k para cálculo da mediana
        if (fim - inicio < k) {

            // Chama quickSort recursivo
            quickSortRecursivoIds(vetor, inicio, fim, comparacoes, trocas); 

        }else {

            unsigned *aux = gerarVetor(vetor, inicio, k); // Gera vetor com k elementos

            unsigned mediana = medianadek(aux, k, trocas, comparacoes); // Calcula a mediana de k elementos

            unsigned copiaInicio = inicio;
            // Loop para encontrar id da mediana
            while(aux[mediana] != vetor[copiaInicio])
                copiaInicio++;

            delete[] aux; // Desaloca vetor auxiliar

            mediana = copiaInicio;

            (*trocas)++; // Incrementa o número de trocas
            swap(&vetor[mediana], &vetor[fim]); // Troca a media para a posição final do vetor

            // Chamadas recursivas do quickSortMediano
            unsigned pivo = particaoIds(vetor, inicio, fim, comparacoes, trocas);
            quickSortMediano(vetor, inicio, pivo - 1, k, trocas, comparacoes);
            quickSortMediano(vetor, pivo + 1, fim, k, trocas, comparacoes);
        
        }


    }

    return;

}