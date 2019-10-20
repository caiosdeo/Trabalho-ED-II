//Biblioteca destinada para operações na main

#ifndef TRATAMENTO_H_INCLUDED
#define TRATAMENTO_H_INCLUDED

//Inclusão de outras interfaces/bibliotecas
#include <fstream>
#include <chrono>
#include "review.h"

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
 * @param estado 0 para insercao; 1 para busca
 * @param n Tamanho do conjunto
 * @param numComparacoes Valor de comparações
 * @param numCopias Valor de cópias
 * @param tempoProcessamento valor de tempo de processamento
 */
void imprimirSaida(fstream &saida, unsigned estrutura, int estado, unsigned n, float numComparacoes, float numCopias, float tempoProcessamento);

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
 * Embaralhamento de vetor de reviews.
 *
 * @author eliascassis
 * @param conjunto vetor de Reviews
 * @param n Tamanho do conjunto
 * @return v Vetor de reviews embaralhado
 */
void embaralharEstruturas(Review *r, unsigned n);

/**
 * Swap para estruturas
 * 
 * @author eliascassis
 * @param a Vetor de reviews
 * @param i posição i
 * @param j posição j
 * @return void
 */
void swapEstruturas(Review* a, unsigned i, unsigned j);

/**
 * Valor correspondente de string em unsigned
 *
 * @author eliascassis
 * @param string str string
 * @return valorString correspondente inteiro da soma dos caracteres da string.
 */
int converterStringInteiro(string str);

#endif //TRATAMENTO_H_INCLUDED