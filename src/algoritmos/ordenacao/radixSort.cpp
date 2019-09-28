#include "radixSort.h"

#include <iostream>

using namespace std; 
  
int maior(int* v, int n, int* numComparacoes, int* numTrocas){ 
    
    int maior = v[0]; 
    
    for (int i = 1; i < n; i++){ 
        
        if (v[i] > maior) 
            maior = v[i]; 
    
    }
    
    return maior; 
} 
 
void countSort(int v[], int n, int exp, int* numComparacoes, int* numTrocas){ 

    int saida[n]; // vetor de saída 
    int i;
    int contagem[2] = {0}; 
  
    // Armazenando a contagem de ocorrências de um número em contagem[] 
    for (i = 0; i < n; i++){
        contagem[ (v[i]/exp)%2 ]++; 
        (*numTrocas) += 2;
    }
  
    // Alterando contagem[i] para que contagem[i] contenha a posição atual do digito de saida
    for (i = 1; i < 2; i++){
        contagem[i] += contagem[i - 1]; 
        (*numTrocas) += 2;
    }

    // Construindo o saida[] 
    for (i = n - 1; i >= 0; i--){

        saida[contagem[ (v[i]/exp)%2 ] - 1] = v[i]; 
        contagem[ (v[i]/exp)%2 ]--; 
        (*numTrocas) += 6;

    } 

    // Copiando saida[] para v[], para que v[] contenha os números ordenados
    for (i = 0; i < n; i++) {
        v[i] = saida[i]; 
        (*numTrocas) += 2;
    }

} 
  
void radixSort(int *v, int n, int* numComparacoes, int* numTrocas){

    // Achando o maior valor para saber o número de dígitos 
    int m = maior(v, n, numComparacoes, numTrocas); 
  
    // Usando o countsort para cada dígito.
    // Usando exp que é 2^i com i sendo o dígito do número atual

    for (int exp = 1; m/exp > 0; exp *= 2) 
        countSort(v, n, exp, numComparacoes, numTrocas); 
} 