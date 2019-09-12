#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"
#include "../classes/review.h"
#include "../algoritmos/quickSortRecursivo.h"

int* leituraDadosVetor(fstream &dataset, int n){

    // Conjunto de IDs
    int* ids = new int[n];
    
    //Variaveis para ler o documento
    string id, user, rating;

    //Variavel auxiliar para controlar o tamanho do conjunto
    int i = 0;

    // Alterando a semente com o tempo
    srand(time(NULL));

    // Eliminando a primeira linha do arquivo
    getline(dataset, user, ',');
    getline(dataset, rating, ',');
    getline(dataset, id, '\n');

    // Extração de dados até o tamanho do conjunto e o fim do arquivo
    while(dataset.good() && i < n){

        // Pegando as informações de cada registro
        getline(dataset, user, ',');
        getline(dataset, rating, ',');
        getline(dataset, id, '\n');

        if(rand() % 11 == 0){ // Selecionando registros a partir do resto de uma divisão por 11

            ids[i] = stoi(id); // Atribuindo o id do jogo

            i++;

        }
        
    }

    // Retornando o conjunto de reviews
    return ids;

}

// ! FLUXO PARA DADOS EM VETOR DE INTEIRO

void executarDadosVetor(fstream &entrada, fstream &dataset, fstream &saida){

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
        quickSortRecursivoIds(conjuntos[i], 0, n-1, &numComparacoes, &numCopias);

        // Ponto de parada de contagem para o tempo de execução do algoritmo
        auto parada = chrono::high_resolution_clock::now();

        //Tempo de processamento do algoritmo
        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio);

        // Imprimindo resultados no arquivo de saída
        imprimirSaida(saida, 0, n, numComparacoes, numCopias, tempoProcessamento);
        
    }

    // Desalocando os conjuntos
    for(int i = 0; i < qtdConjuntos; i++)
        delete [] conjuntos[i];
    delete [] conjuntos;
    
}

// ! FLUXO PARA DADOS EM VETOR DE REVIEWS

void executarDadosReview(fstream &entrada, fstream &dataset, fstream &saida){

    // Variaveis para leitura do arquivo de entrada
    int qtdConjuntos, n;

    // Lendo quantos conjuntos teremos
    entrada >> qtdConjuntos;

    // Criação dos conjuntos 
    Review** conjuntos = new Review*[qtdConjuntos];

    for(int i = 0; entrada >> n; i++){

        conjuntos[i] = new Review[n]; // Para cada conjunto criar um vetor do tamanho n

        conjuntos[i] = conjuntos[i]->leituraDados(dataset, n); // Colocando dados no conjunto

        // Métricas de desempenho
        int numComparacoes = 0, numCopias = 0;

        // Ponto de inicio de contagem para tempo de execução do algoritmo
        auto inicio = chrono::high_resolution_clock::now();

        // * Chamada dos algoritmos
        quickSortRecursivoEstruturas(conjuntos[i], 0, n-1, &numComparacoes, &numCopias);

        // Ponto de parada de contagem para o tempo de execução do algoritmo
        auto parada = chrono::high_resolution_clock::now();

        //Tempo de processamento do algoritmo
        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio);

        // Imprimindo resultados no arquivo de saída
        imprimirSaida(saida, 1, n, numComparacoes, numCopias, tempoProcessamento);

    }

    // Desalocando os conjuntos
    for (int i = 0; i < qtdConjuntos; i++)
        delete [] conjuntos[i];
    delete [] conjuntos;
    
}

void imprimirSaida(fstream &saida, int estrutura, int n, float numComparacoes, float numCopias, std::chrono::__enable_if_is_duration<std::chrono::milliseconds> tempoProcessamento){

    saida << estrutura << "," << n << "," << numComparacoes << "," << numCopias << "," << tempoProcessamento.count() << endl;

}