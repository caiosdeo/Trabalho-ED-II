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

void embaralharIds(unsigned *v, unsigned n){

    for(unsigned i = 0; i < n/2; i+=2)
        swap(v, i, n-i);

    for(unsigned i = 0; i < n - 1; i+=2)
        swap(v, i, i+1);

}

void embaralharEstruturas(Review *r, unsigned n){

    for(unsigned i = 0; i < n/2; i+=2)
        swapEstruturas(r, i, n-i);

    for(unsigned i = 0; i < n - 1; i+=2)
        swapEstruturas(r, i, i+1);

}

unsigned* gerarVetorIds(Review* conjunto, unsigned n){

    //Vetor unsigned           
    unsigned* ids = (unsigned*)calloc(n, sizeof(unsigned));
    
    // Copiando os IDs do conjunto para o vetor de ID
    for (unsigned j = 0; j < n; j++)
        ids[j] = conjunto[j].getId();

    //embaralharIds(ids, n);
    
    // Retornando o conjunto de reviews
    return ids;

}

void copiaVetor(unsigned* v, unsigned* ids, unsigned n){

    for(int i = 0; i < n; i++)
        v[i] = ids[i];

}