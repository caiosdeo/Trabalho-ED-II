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
 * @param estrutura 0 para vetor de unsigned; 1 para vetor de struct
 * @param n Tamanho do conjunto
 * @param taxaCompressao Taxa de compressão
 * @param armazenamento Armazenamento em Disco
 * @param tempoProcessamento valor de tempo de processamento
 */
void imprimirSaida(fstream &saida, unsigned estrutura, unsigned n, float taxaCompressao, float armazenamento, float tempoProcessamento);

/**
 * Embaralhamento de vetor de descrições.
 *
 * @author eliascassis
 * @param conjunto vetor de descrições
 * @param n Tamanho do conjunto
 * @return v Vetor de descrições embaralhado
 */
void embaralharDescricoes(string *d, unsigned n);

/**
 * Swap para descrições
 * 
 * @author eliascassis
 * @param a Vetor de descrições
 * @param i posição i
 * @param j posição j
 * @return void
 */
void swapDescricoes(string* a, int i, int j);

/**
 * Valor correspondente de string em unsigned
 *
 * @author eliascassis
 * @param string str string
 * @return valorString correspondente inteiro da soma dos caracteres da string.
 */
int converterStringInteiro(string str);

/**
 * Atribuição de dados a cada conjunto, retornando-o em um vetor.
 *
 * @author caiosdeo
 * @param dataset Arquivo com os dados
 * @param n Tamanho do conjunto
 * @return d Vetor com dados
 */
string* leituraDescricoes(fstream &dataset, int n);

#endif //TRATAMENTO_H_INCLUDED