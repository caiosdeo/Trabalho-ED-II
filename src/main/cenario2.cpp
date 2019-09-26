#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"
#include "../classes/review.h"
#include "../algoritmos/ordenacao.h"

using namespace std;

// ! FLUXO PARA DADOS EM VETOR DE INTEIRO QUICKSORT MEDIANA

void fluxoQuickSortMediana(fstream &entrada, fstream &dataset, fstream &saida, int k, int j){

    // Variaveis para leitura do arquivo de entrada
    int qtdConjuntos, n;

    // Lendo quantos conjuntos teremos
    entrada >> qtdConjuntos;

    // Criação dos conjuntos 
    int** conjuntos = new int*[qtdConjuntos];

    for(int i = 0; entrada >> n; i++){

        conjuntos[i] = new int[n]; // Para cada conjunto criar um vetor do tamanho n

        conjuntos[i] = leituraDadosVetor(dataset, n); // Colocando dados no conjunto

        // Métricas de desempenho
        int numComparacoes = 0, numCopias = 0;

        // Ponto de inicio de contagem para tempo de execução do algoritmo
        auto inicio = chrono::high_resolution_clock::now();

        // * Chamada dos algoritmos
        quickSortMediano(conjuntos[i], 0, n-1, k, &numCopias, &numComparacoes);

        // Ponto de parada de contagem para o tempo de execução do algoritmo
        auto parada = chrono::high_resolution_clock::now();

        //Tempo de processamento do algoritmo
        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

        // Imprimindo resultados no arquivo de saída
        imprimirSaida(saida, j, n, numComparacoes, numCopias, tempoProcessamento);
        
    }

    // Desalocando os conjuntos
    for(int i = 0; i < qtdConjuntos; i++)
        delete [] conjuntos[i];
    delete [] conjuntos;
    
}

// ! FLUXO PARA DADOS EM VETOR DE INTEIRO QUICKSORT INSERÇÃO

void fluxoQuickSortInsercao(fstream &entrada, fstream &dataset, fstream &saida, int m, int j){

    // Variaveis para leitura do arquivo de entrada
    int qtdConjuntos, n;

    // Lendo quantos conjuntos teremos
    entrada >> qtdConjuntos;

    // Criação dos conjuntos 
    int** conjuntos = new int*[qtdConjuntos];

    for(int i = 0; entrada >> n; i++){

        conjuntos[i] = new int[n]; // Para cada conjunto criar um vetor do tamanho n

        conjuntos[i] = leituraDadosVetor(dataset, n); // Colocando dados no conjunto

        // Métricas de desempenho
        int numComparacoes = 0, numCopias = 0;

        // Ponto de inicio de contagem para tempo de execução do algoritmo
        auto inicio = chrono::high_resolution_clock::now();

        // * Chamada dos algoritmos
        insertionQuickSort(conjuntos[i], 0, n-1, m, &numComparacoes, &numCopias);

        // Ponto de parada de contagem para o tempo de execução do algoritmo
        auto parada = chrono::high_resolution_clock::now();

        //Tempo de processamento do algoritmo
        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

        // Imprimindo resultados no arquivo de saída
        imprimirSaida(saida, j, n, numComparacoes, numCopias, tempoProcessamento);
        
    }

    // Desalocando os conjuntos
    for(int i = 0; i < qtdConjuntos; i++)
        delete [] conjuntos[i];
    delete [] conjuntos;
    
}