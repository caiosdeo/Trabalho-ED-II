#include <iostream>
#include <fstream>
#include <chrono>
#include "../classes/review.h"
#include "tratamento.h"
#include "../algoritmos/ordenacao.h"
#include "cenario3.h"

using namespace std;

void fluxoCenario3(unsigned* ids, unsigned n, fstream &saida){

    // Vetor de IDs
    unsigned* v = (unsigned*)calloc(n, sizeof(unsigned));

    // Inicialização das variaveis de tempo
    auto inicio = chrono::high_resolution_clock::now();
    auto parada = chrono::high_resolution_clock::now();
    auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

    // Visualizando o N
    cout << "N: " << n << endl;

    //Loop para rodar para os dois tipos de estruturas em única execução
    for (unsigned versao = 0; versao < 5; versao++){

        // Métricas de desempenho
        unsigned long numComparacoes = 0, numCopias = 0;

        switch(versao){

            case 0: // Quicksort mediana k = 5 // TODO: Verificar novamente o melhor do 2

                copiaVetor(v, ids, n);

                cout << "Executando quicksort mediana k = 5" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                quickSortMediano(v, 0, n-1, 5, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                parada = chrono::high_resolution_clock::now();

                break;

            case 1: // Insertion Sort

                copiaVetor(v, ids, n);

                cout << "Executando insertion sort" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                insertionSort(v, n, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                parada = chrono::high_resolution_clock::now();

                break;

            case 2: // Merge Sort
                
                copiaVetor(v, ids, n);

                cout << "Executando merge sort" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                mergeSort(v, 0, n-1, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                parada = chrono::high_resolution_clock::now();

                break;

            case 3: // Heap Sort

                copiaVetor(v, ids, n);

                cout << "Executando heap sort" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                heapSort(v, n, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                parada = chrono::high_resolution_clock::now();

                break;

            case 4: // Gnome Sort

                copiaVetor(v, ids, n);

                cout << "Executando gnome sort" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                gnomeSort(v, n, &numComparacoes, &numCopias);

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

    delete [] v;
    
}
