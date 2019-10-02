//Biblioteca destinada para operações na main

#ifndef TRATAMENTO_H_INCLUDED
#define TRATAMENTO_H_INCLUDED

//Inclusão de outras interfaces/bibliotecas
#include <fstream>
#include <chrono>
#include "../classes/review.h"

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
 * Geração de vetor de ids.
 *
 * @author caiosdeo
 * @param conjunto vetor de Reviews
 * @param n Tamanho do conjunto
 * @return ids Vetor de ids
 */
int* gerarVetorIds(Review* conjunto, int n);

#endif //TRATAMENTO_H_INCLUDED