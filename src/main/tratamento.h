//Biblioteca destinada para operações na main

#ifndef TRATAMENTO_H_INCLUDED
#define TRATAMENTO_H_INCLUDED

//Inclusão de outras interfaces/bibliotecas
#include <fstream>
#include <chrono>

using namespace std;

/////////////////////////////////////////
// Protótipos das funções da bilioteca //
/////////////////////////////////////////

/**
 * Impressão das métricas em um arquivo de saída
 *
 * @author caiosdeo
 * @param saida Arquivo de saída com as métricas
 * @param estrutura 0 para vetor de int; 1 para vetor de struct
 * @param n Tamanho do conjunto
 * @param numComparacoes Valor de comparações
 * @param numCopias Valor de cópias
 * @param tempoProcessamento valor de tempo de processamento
 */
void imprimirSaida(fstream &saida, int estrutura, int n, float numComparacoes, float numCopias, float tempoProcessamento);

/**
 * Impressão das métricas em um arquivo de saída para as hash
 *
 * @author caiosdeo
 * @param saida Arquivo de saída com as métricas
 * @param versao 0 para vetor de int; 1 para vetor de struct
 * @param n Tamanho do conjunto
 * @param numColisoes numero de colisoa hash
 */
void imprimirSaidaHash(fstream &saida, int versao, int n, float numColisoes);


/**
 * Atribuição de dados a cada conjunto, retornando-o em um vetor.
 *
 * @author caiosdeo
 * @param dataset Arquivo com os dados
 * @param n Tamanho do conjunto
 * @return r Vetor com dados
 */
int* leituraDadosVetor(fstream &dataset, int n);

#endif //TRATAMENTO_H_INCLUDED