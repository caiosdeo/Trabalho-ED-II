#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"
#include "../algoritmos/ordenacao.h"

using namespace std;

void fluxoCenario2(Review* conjunto, int n, fstream &saida){

    //Loop para rodar para os dois tipos de estruturas em única execução
    for (int versao = 0; versao < 5; versao++){

        int* ids = gerarVetorIds(conjunto, n);

        // Métricas de desempenho
        unsigned long long int numComparacoes = 0, numCopias = 0;

        switch(versao){

            case 0:

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                auto inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                quickSortRecursivoIds(ids, 0, n-1, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                auto parada = chrono::high_resolution_clock::now();

            case 1:

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                auto inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                quickSortMediano(ids, 0, n-1, 3, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                auto parada = chrono::high_resolution_clock::now();

            case 2:

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                auto inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                quickSortMediano(ids, 0, n-1, 5, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                auto parada = chrono::high_resolution_clock::now();

            case 3:

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                auto inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                insertionQuickSort(ids, 0, n-1, 10, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                auto parada = chrono::high_resolution_clock::now();

            case 4:

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                auto inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                insertionQuickSort(ids, 0, n-1, 100, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                auto parada = chrono::high_resolution_clock::now();

        }

        //Tempo de processamento do algoritmo
        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

        // Imprimindo resultados no arquivo de saída
        imprimirSaida(saida, versao, n, numComparacoes, numCopias, tempoProcessamento);
    
    }
    
}



                               