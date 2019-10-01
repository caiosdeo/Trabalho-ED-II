#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"
#include "../classes/review.h"
#include "../algoritmos/hash.h"
#include "cenario4.h"

using namespace std;

void fluxoHashSondLin(fstream &entrada, fstream &dataset, fstream &saida, int versao){

    // Variaveis para leitura do arquivo de entrada
    int qtdConjuntos, n;

    // Lendo quantos conjuntos teremos
    entrada >> qtdConjuntos;

    // Criação dos conjuntos 
    Review** conjuntos = new Review*[qtdConjuntos];

    for(int i = 0; entrada >> n; i++){

        conjuntos[i] = new Review[n]; // Para cada conjunto criar um vetor do tamanho n

        conjuntos[i] = conjuntos[i]->leituraDados(dataset, n); // Colocando dados no conjunto

        int *chaves = gerarConjuntoChaves(conjuntos[i], n); // Gerando chaves a serem usadas nas hash

        // * Chamada dos algoritmos
        HashSondLin hash = HashSondLin(n);

        for(int j = 0; j < n; j++)
            hash.insereNo(chaves[j], chaves[j]);

        // Métrica de desempenho
        unsigned long long int numColisoes = hash.getNumColisoes();

        // Imprimindo resultados no arquivo de saída
        imprimirSaidaHash(saida, versao, n, numColisoes);

    }

    // Desalocando os conjuntos
    for (int i = 0; i < qtdConjuntos; i++)
        delete [] conjuntos[i];
    delete [] conjuntos;
    
}

void fluxoHashSondQuad(fstream &entrada, fstream &dataset, fstream &saida, int versao){

    // Variaveis para leitura do arquivo de entrada
    int qtdConjuntos, n;

    // Lendo quantos conjuntos teremos
    entrada >> qtdConjuntos;

    // Criação dos conjuntos 
    Review** conjuntos = new Review*[qtdConjuntos];

    for(int i = 0; entrada >> n; i++){

        conjuntos[i] = new Review[n]; // Para cada conjunto criar um vetor do tamanho n

        conjuntos[i] = conjuntos[i]->leituraDados(dataset, n); // Colocando dados no conjunto

        int *chaves = gerarConjuntoChaves(conjuntos[i], n); // Gerando chaves a serem usadas nas hash

        // * Chamada dos algoritmos
        HashSondQuad hash = HashSondQuad(n);

        for(int j = 0; j < n; j++)
            hash.insereNo(chaves[j], chaves[j]);

        // Métrica de desempenho
        unsigned long long int numColisoes = hash.getNumColisoes();

        // Imprimindo resultados no arquivo de saída
        imprimirSaidaHash(saida, versao, n, numColisoes);

    }

    // Desalocando os conjuntos
    for (int i = 0; i < qtdConjuntos; i++)
        delete [] conjuntos[i];
    delete [] conjuntos;
    
}

void fluxoDuploHash(fstream &entrada, fstream &dataset, fstream &saida, int versao){

    // Variaveis para leitura do arquivo de entrada
    int qtdConjuntos, n;

    // Lendo quantos conjuntos teremos
    entrada >> qtdConjuntos;

    // Criação dos conjuntos 
    Review** conjuntos = new Review*[qtdConjuntos];

    for(int i = 0; entrada >> n; i++){

        conjuntos[i] = new Review[n]; // Para cada conjunto criar um vetor do tamanho n

        conjuntos[i] = conjuntos[i]->leituraDados(dataset, n); // Colocando dados no conjunto

        int *chaves = gerarConjuntoChaves(conjuntos[i], n); // Gerando chaves a serem usadas nas hash

        // * Chamada dos algoritmos
        duploHash hash = duploHash(n);

        for(int j = 0; j < n; j++)
            hash.inserirHash(chaves[j]);

        // Métrica de desempenho
        unsigned long long int numColisoes = hash.getNumColisoes();

        // Imprimindo resultados no arquivo de saída
        imprimirSaidaHash(saida, versao, n, numColisoes);

    }

    // Desalocando os conjuntos
    for (int i = 0; i < qtdConjuntos; i++)
        delete [] conjuntos[i];
    delete [] conjuntos;
    
}

void fluxoHashEncadSeparado(fstream &entrada, fstream &dataset, fstream &saida, int versao){

    // Variaveis para leitura do arquivo de entrada
    int qtdConjuntos, n;

    // Lendo quantos conjuntos teremos
    entrada >> qtdConjuntos;

    // Criação dos conjuntos 
    Review** conjuntos = new Review*[qtdConjuntos];

    for(int i = 0; entrada >> n; i++){

        conjuntos[i] = new Review[n]; // Para cada conjunto criar um vetor do tamanho n

        conjuntos[i] = conjuntos[i]->leituraDados(dataset, n); // Colocando dados no conjunto

        int *chaves = gerarConjuntoChaves(conjuntos[i], n); // Gerando chaves a serem usadas nas hash

        // * Chamada dos algoritmos
        HashEncadSeparado hash = HashEncadSeparado(n/10);

        for(int j = 0; j < n; j++)
            hash.insereItem(chaves[j]);

        // Métrica de desempenho
        unsigned long long int numColisoes = hash.contabilizarColisoes();

        // Imprimindo resultados no arquivo de saída
        imprimirSaidaHash(saida, versao, n, numColisoes);

    }

    // Desalocando os conjuntos
    for (int i = 0; i < qtdConjuntos; i++)
        delete [] conjuntos[i];
    delete [] conjuntos;
    
}

void fluxoHashEncadCoal(fstream &entrada, fstream &dataset, fstream &saida, int versao){

    // Variaveis para leitura do arquivo de entrada
    int qtdConjuntos, n;

    // Lendo quantos conjuntos teremos
    entrada >> qtdConjuntos;

    // Criação dos conjuntos 
    Review** conjuntos = new Review*[qtdConjuntos];

    for(int i = 0; entrada >> n; i++){

        conjuntos[i] = new Review[n]; // Para cada conjunto criar um vetor do tamanho n

        conjuntos[i] = conjuntos[i]->leituraDados(dataset, n); // Colocando dados no conjunto

        int *chaves = gerarConjuntoChaves(conjuntos[i], n); // Gerando chaves a serem usadas nas hash

        // Métrica de desempenho
        unsigned long long int numColisoes = 0;

        // * Chamada dos algoritmos
        hashEncadCoal hash = hashEncadCoal(n);

        for(int j = 0; j < n; j++)
            hash.insereItem(chaves[j], &numColisoes);

        // Imprimindo resultados no arquivo de saída
        imprimirSaidaHash(saida, versao, n, numColisoes);

    }

    // Desalocando os conjuntos
    for (int i = 0; i < qtdConjuntos; i++)
        delete [] conjuntos[i];
    delete [] conjuntos;
    
}