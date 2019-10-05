#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"
#include "../classes/review.h"
#include "../algoritmos/ordenacao.h"

void imprimirSaida(fstream &saida, unsigned estrutura, unsigned n, float numComparacoes, float numCopias, float tempoProcessamento){

    saida << estrutura << "," << n << "," << numComparacoes << "," << numCopias << "," << tempoProcessamento << endl;

}

void imprimirSaidaHash(fstream &saida, unsigned versao, unsigned n, float numColisoes){

    saida << versao << "," << n << "," << numColisoes << endl;

}

unsigned* gerarVetorIds(Review* conjunto, unsigned n){

    //Vetor de unsignedeiros            
    unsigned* ids = new unsigned[n];
    
    // Copiando os IDs do conjunto para o vetor de ID
    for (unsigned j = 0; j < n; j++)
        ids[j] = conjunto[j].getId();
    
    // Retornando o conjunto de reviews
    return ids;

}