#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"
#include "../classes/review.h"
#include "../algoritmos/ordenacao.h"

using namespace std;

void fluxoCenario1(Review* conjunto, int n, fstream &saida){

    // Vetor de IDs
    int* ids;

    // Inicialização das variaveis de tempo
    auto inicio = chrono::high_resolution_clock::now();
    auto parada = chrono::high_resolution_clock::now();
    auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

    // Visualizando o N
    cout << "N: " << n << endl;

    //Loop para rodar para os dois tipos de estruturas em única execução
    for (int versao = 0; versao < 2; versao++){

        // Métricas de desempenho
        unsigned long long int numComparacoes = 0, numCopias = 0;

        switch(versao){

            case 0: // Quicksort vetor inteiro

                ids = gerarVetorIds(conjunto, n);

                cout << "Executando quicksort para vetor int" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                quickSortRecursivoIds(ids, 0, n-1, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                parada = chrono::high_resolution_clock::now();
        
                //Tempo de processamento do algoritmo
                tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

                break;

            case 1:{ // Quicksort vetor inteiro

                //Copiando o vetor original
                Review aux[n]; 
                for (int i = 0; i < n; i++)
                    aux[i] = conjunto[i];

                cout << "Executando quicksort para vetor Review" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                inicio = chrono::high_resolution_clock::now();
                
                // * Chamada dos algoritmos
                quickSortRecursivoEstruturas(aux, 0, n-1, &numComparacoes, &numCopias);

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                parada = chrono::high_resolution_clock::now();

                //Tempo de processamento do algoritmo
                tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

                break;
            
            }
            
            default:
                break;

        }

        // Imprimindo resultados no arquivo de saída
        imprimirSaida(saida, versao, n, numComparacoes, numCopias, tempoProcessamento);
    
    }
    
}
