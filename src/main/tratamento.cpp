#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"
#include "../classes/review.h"
#include "../algoritmos/ordenacao.h"

void imprimirSaida(fstream &saida, int estrutura, int n, float numComparacoes, float numCopias, float tempoProcessamento){

    saida << estrutura << "," << n << "," << numComparacoes << "," << numCopias << "," << tempoProcessamento << endl;

}

void imprimirSaidaHash(fstream &saida, int versao, int n, float numColisoes){

    saida << versao << "," << n << "," << numColisoes << endl;

}

int* gerarVetorIds(Review* conjunto, int n){

    //Vetor de inteiros            
    int* ids = new int[n];
    
    // Copiando os IDs do conjunto para o vetor de ID
    for (int j = 0; j < n; j++)
        ids[j] = conjunto[j].getId();
    
    // Retornando o conjunto de reviews
    return ids;

}