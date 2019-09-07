//Biblioteca destinada para operações na main

#ifndef TRATAMENTO_H_INCLUDED
#define TRATAMENTO_H_INCLUDED

//Inclusão de outras interfaces/bibliotecas
#include <fstream>

using namespace std;

/////////////////////////////////////////
// Protótipos das funções da bilioteca //
/////////////////////////////////////////

/**
 * Execução específica para dados do tipo inteiro
 * Leitura de quantos conjuntos de tamanho N serão trabalhados na execução do programa.
 * Atribuição de dados a cada conjunto, tratando as métricas e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param entrada Arquivo de entrada
 * @param dataset Arquivo com os dados
 * @param saida Arquivo de saída com as médias das métricas
 */
void executarDadosVetor(fstream &entrada, fstream &dataset, fstream &saida);

/**
 * Atribuição de dados a cada conjunto, retornando-o em um vetor.
 *
 * @author caiosdeo
 * @param dataset Arquivo com os dados
 * @param n Tamanho do conjunto
 * @return r Vetor com dados
 */
int* leituraDadosVetor(fstream &dataset, int n);

/**
 * Execução específica para dados do tipo Review
 * Leitura de quantos conjuntos de tamanho N serão trabalhados na execução do programa.
 * Atribuição de dados a cada conjunto, tratando as métricas e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param entrada Arquivo de entrada
 * @param dataset Arquivo com os dados
 * @param saida Arquivo de saída com as médias das métricas
 */
void executarDadosReview(fstream &entrada, fstream &dataset, fstream &saida);

/**
 * Impressão das médias das métricas em um arquivo de saída
 *
 * @author caiosdeo
 * @param saida Arquivo de saída com as médias das métricas
 * @param estrutura 0 para vetor de int; 1 para vetor de struct
 * @param n Tamanho do conjunto
 * @param numComparacoes Valor médio de comparações
 * @param numCopias Valor médio de cópias
 * @param tempoProcessamento valor médio de tempo de processamento
 */
void imprimirSaida(fstream &saida, int estrutura, int n, float numComparacoes, float numCopias, float tempoProcessamento);

#endif //TRATAMENTO_H_INCLUDED