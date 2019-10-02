#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"
#include "../algoritmos/ordenacao.h"

using namespace std;

void fluxoCenario2(Review* conjunto, int n, fstream &saida){

    // Vetor de IDs
    int* ids;

    // Inicialização das variaveis de tempo
    auto inicio = chrono::high_resolution_clock::now();
    auto parada = chrono::high_resolution_clock::now();
    auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

    // Visualizando o N
    cout << "N: " << n << endl;

    //Loop para rodar para os dois tipos de estruturas em única execução
    for (int versao = 0; versao < 5; versao++){

        ids = gerarVetorIds(conjunto, n);

        // Métricas de desempenho
        unsigned long long int numComparacoes = 0, numCopias = 0;

        switch(versao){

            case 0:

                cout << "Executando quicksort" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                quickSortRecursivoIds(ids, 0, n-1, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                parada = chrono::high_resolution_clock::now();

                break;

            case 1:

                cout << "Executando quicksort mediana k = 3" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                quickSortMediano(ids, 0, n-1, 3, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                parada = chrono::high_resolution_clock::now();

                break;

            case 2:

                cout << "Executando quicksort mediana k = 5" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                quickSortMediano(ids, 0, n-1, 5, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                parada = chrono::high_resolution_clock::now();

                break;

            case 3:

                cout << "Executando quicksort insercao m = 10" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                insertionQuickSort(ids, 0, n-1, 10, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                parada = chrono::high_resolution_clock::now();

                break;

            case 4:

                cout << "Executando quicksort insercao m = 100" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                insertionQuickSort(ids, 0, n-1, 100, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                parada = chrono::high_resolution_clock::now();

                break;

            default:
                break;

        }

        //Tempo de processamento do algoritmo
        tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

        // Imprimindo resultados no arquivo de saída
        imprimirSaida(saida, versao, n, numComparacoes, numCopias, tempoProcessamento);
    
    }
    
}



                               