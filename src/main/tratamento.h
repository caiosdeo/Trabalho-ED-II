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
 * @param estrutura 0 para vetor de unsigned; 1 para vetor de struct
 * @param n Tamanho do conjunto
 * @param numComparacoes Valor de comparações
 * @param numCopias Valor de cópias
 * @param tempoProcessamento valor de tempo de processamento
 */
void imprimirSaida(fstream &saida, unsigned estrutura, unsigned n, float numComparacoes, float numCopias, float tempoProcessamento);

/**
 * Impressão das métricas em um arquivo de saída para as hash
 *
 * @author caiosdeo
 * @param saida Arquivo de saída com as métricas
 * @param versao 0 para vetor de unsigned; 1 para vetor de struct
 * @param n Tamanho do conjunto
 * @param numColisoes numero de colisoa hash
 */
void imprimirSaidaHash(fstream &saida, unsigned versao, unsigned n, float numColisoes);


/**
 * Geração de vetor de ids.
 *
 * @author caiosdeo
 * @param conjunto vetor de Reviews
 * @param n Tamanho do conjunto
 * @return ids Vetor de ids
 */
unsigned* gerarVetorIds(Review* conjunto, unsigned n);


/**
 * Embaralhamento de vetor de ids.
 *
 * @author eliascassis
 * @param conjunto vetor de ids
 * @param n Tamanho do conjunto
 * @return v Vetor de ids embaralhado
 */
void embaralharIds(unsigned *v, unsigned n);

/**
 * Embaralhamento de vetor de reviews.
 *
 * @author eliascassis
 * @param conjunto vetor de Reviews
 * @param n Tamanho do conjunto
 * @return v Vetor de reviews embaralhado
 */
void embaralharEstruturas(Review *r, unsigned n);

#endif //TRATAMENTO_H_INCLUDED