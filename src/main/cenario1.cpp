#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"
#include "../classes/review.h"
#include "../algoritmos/ordenacao.h"

using namespace std;

void fluxoCenario1(Review* conjunto, int n, fstream &saida){

    //Loop para rodar para os dois tipos de estruturas em única execução
    for (int versao = 0; versao < 2; versao++){

        // Métricas de desempenho
        unsigned long long int numComparacoes = 0, numCopias = 0;

        switch(versao){

            case 0:

                int* ids = gerarVetorIds(conjunto, n);

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                auto inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                quickSortRecursivoIds(ids, 0, n-1, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                auto parada = chrono::high_resolution_clock::now();

            case 1:

                //Copiando o vetor original
                Review aux[n]; 
                for (int i = 0; i < n; i++)
                    aux[i] = conjunto[i];

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                auto inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                quickSortRecursivoEstruturas(aux, 0, n-1, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                auto parada = chrono::high_resolution_clock::now();

            default:
                break;

        }

        //Tempo de processamento do algoritmo
        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

        // Imprimindo resultados no arquivo de saída
        imprimirSaida(saida, versao, n, numComparacoes, numCopias, tempoProcessamento);
    
    }
    
}
