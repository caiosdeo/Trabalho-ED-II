#include <iostream>
#include <fstream>
#include "tratamento.h"
#include "../classes/review.h"

void imprimirSaida(fstream &saida, int estrutura, int n, float numComparacoes, float numCopias, float tempoProcessamento){

    saida << estrutura << "," << n << "," << numComparacoes << "," << numCopias << "," << tempoProcessamento << endl;

}

void leitura(fstream &entrada, fstream &dataset, fstream &saida, int estrutura){

    // Variaveis para leitura do arquivo de entrada
    int qtdConjuntos;
    int n;

    // Lendo quantos conjuntos teremos
    entrada >> qtdConjuntos;

    // Criação dos conjuntos 
    Review** conjuntos = new Review*[qtdConjuntos];

    for(int i = 0; entrada >> n; i++){

        conjuntos[i] = new Review[n]; // Para cada conjunto criar um vetor do tamanho n

        conjuntos[i] = conjuntos[i]->leituraDados(dataset, n); // Colocando dados no conjunto

        // Métricas de desempenho
        float numComparacoes = 0, numCopias = 0, tempoProcessamento = 0;

        /**
         * ! serão 5 execuções para cada conjunto, sementes diferentes
         * TODO: aqui vai ficar as chamadas para funções de ordenação
         * TODO: passando os endereços das métricas de desempenho
         * TODO: estas variáveis são acumulativas para as métricas
         */

        // TODO: calcular médias das métricas de desempenho dividindo as variáveis por 5 

        // Imprimindo resultados no arquivo de saída
        imprimirSaida(saida, estrutura, n, numComparacoes, numCopias, tempoProcessamento);

    }
    
}
