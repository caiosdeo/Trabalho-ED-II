#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"
#include "../algoritmos/ordenacao.h"
#include "cenario3.h"

using namespace std;

// ! FLUXO PARA DADOS EM VETOR DE INTEIRO INSERTION SORT

void fluxoInsertionSort(fstream &entrada, fstream &dataset, fstream &saida, int versao){

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
        insertionSort(conjuntos[i], n, &numCopias, &numComparacoes);

        // Ponto de parada de contagem para o tempo de execução do algoritmo
        auto parada = chrono::high_resolution_clock::now();

        //Tempo de processamento do algoritmo
        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

        // Imprimindo resultados no arquivo de saída
        imprimirSaida(saida, versao, n, numComparacoes, numCopias, tempoProcessamento);
        
    }

    // Desalocando os conjuntos
    for(int i = 0; i < qtdConjuntos; i++)
        delete [] conjuntos[i];
    delete [] conjuntos;
    
}

// ! FLUXO PARA DADOS EM VETOR DE INTEIRO MERGESORT

void fluxoMergeSort(fstream &entrada, fstream &dataset, fstream &saida, int versao){

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
        mergeSort(conjuntos[i], 0, n-1, &numComparacoes, &numCopias);

        // Ponto de parada de contagem para o tempo de execução do algoritmo
        auto parada = chrono::high_resolution_clock::now();

        //Tempo de processamento do algoritmo
        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

        // Imprimindo resultados no arquivo de saída
        imprimirSaida(saida, versao, n, numComparacoes, numCopias, tempoProcessamento);
        
    }

    // Desalocando os conjuntos
    for(int i = 0; i < qtdConjuntos; i++)
        delete [] conjuntos[i];
    delete [] conjuntos;
    
}

// ! FLUXO PARA DADOS EM VETOR DE INTEIRO HEAPSORT

void fluxoHeapSort(fstream &entrada, fstream &dataset, fstream &saida, int versao){

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
        heapSort(conjuntos[i], n, &numCopias, &numComparacoes);

        // Ponto de parada de contagem para o tempo de execução do algoritmo
        auto parada = chrono::high_resolution_clock::now();

        //Tempo de processamento do algoritmo
        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

        // Imprimindo resultados no arquivo de saída
        imprimirSaida(saida, versao, n, numComparacoes, numCopias, tempoProcessamento);
        
    }

    // Desalocando os conjuntos
    for(int i = 0; i < qtdConjuntos; i++)
        delete [] conjuntos[i];
    delete [] conjuntos;
    
}

// ! FLUXO PARA DADOS EM VETOR DE INTEIRO PIGEONHOLESORT

void fluxoGnomeSort(fstream &entrada, fstream &dataset, fstream &saida, int versao){

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
        // TODO: Mudar aqui para o gnome sort
        //gnomeSort(conjuntos[i], n, &numComparacoes, &numCopias);

        // Ponto de parada de contagem para o tempo de execução do algoritmo
        auto parada = chrono::high_resolution_clock::now();

        //Tempo de processamento do algoritmo
        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

        // Imprimindo resultados no arquivo de saída
        imprimirSaida(saida, versao, n, numComparacoes, numCopias, tempoProcessamento);
        
    }

    // Desalocando os conjuntos
    for(int i = 0; i < qtdConjuntos; i++)
        delete [] conjuntos[i];
    delete [] conjuntos;
    
}