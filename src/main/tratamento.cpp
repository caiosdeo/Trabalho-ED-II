#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"
#include "../classes/review.h"
#include "../algoritmos/ordenacao.h"

void imprimirSaida(fstream &saida, int estrutura, int n, float numComparacoes, float numCopias, float tempoProcessamento){

    saida << estrutura << "," << n << "," << numComparacoes << "," << numCopias << "," << tempoProcessamento << endl;

}

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