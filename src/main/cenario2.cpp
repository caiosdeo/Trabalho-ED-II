#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"
#include "../algoritmos/ordenacao.h"

using namespace std;

void fluxoCenario2(unsigned* ids, unsigned n, fstream &saida){

    // Inicialização das variaveis de tempo
    auto inicio = chrono::high_resolution_clock::now();
    auto parada = chrono::high_resolution_clock::now();
    auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

    //Loop para rodar para os dois tipos de estruturas em única execução
    for (unsigned versao = 0; versao < 5; versao++){

        // Métricas de desempenho
        unsigned long long numComparacoes = 0, numCopias = 0;

        switch(versao){

            case 0: // QuickSort

                //copiaVetor(v, ids, n);

                cout << "Executando quicksort" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                quickSortRecursivoIds(ids, 0, n-1, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                parada = chrono::high_resolution_clock::now();

                break;

            case 1: // QuickSort Mediana k = 3

                //copiaVetor(v, ids, n);
                embaralharIds(ids, n);

                cout << "Executando quicksort mediana k = 3" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                quickSortMediano(ids, 0, n-1, 3, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                parada = chrono::high_resolution_clock::now();

                break;

            case 2: // QuickSort Mediana k = 5

                //copiaVetor(v, ids, n);
                embaralharIds(ids, n);

                cout << "Executando quicksort mediana k = 5" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                quickSortMediano(ids, 0, n-1, 5, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                parada = chrono::high_resolution_clock::now();

                break;

            case 3: // QuickSort Inserção m = 10

                //copiaVetor(v, ids, n);
                embaralharIds(ids, n);

                cout << "Executando quicksort insercao m = 10" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                insertionQuickSort(ids, 0, n-1, 10, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                parada = chrono::high_resolution_clock::now();

                break;

            case 4: // QuickSort Inserção m = 100

                //copiaVetor(v, ids, n);
                embaralharIds(ids, n);

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



                               