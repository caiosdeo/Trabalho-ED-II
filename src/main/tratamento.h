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

/**
 * Atribuição de dados a cada conjunto, retornando-o em um vetor.
 *
 * @author caiosdeo
 * @param dataset Arquivo com os dados
 * @param n Tamanho do conjunto
 * @return r Vetor com dados
 */
int* leituraDadosVetor(fstream &dataset, int n);

// * Cenário 1

/**
 * Execução específica para dados do tipo inteiro para o quicksort 
 * Leitura de quantos conjuntos de tamanho N serão trabalhados na execução do programa.
 * Atribuição de dados a cada conjunto, tratando as métricas e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param entrada Arquivo de entrada
 * @param dataset Arquivo com os dados
 * @param saida Arquivo de saída com as médias das métricas
 */
void fluxoQuickSortInteiro(fstream &entrada, fstream &dataset, fstream &saida);

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
void fluxoQuickSortReview(fstream &entrada, fstream &dataset, fstream &saida);

//* Cenário 2

/**
 * Execução específica para dados do tipo inteiro para o quicksort com mediana
 * Leitura de quantos conjuntos de tamanho N serão trabalhados na execução do programa.
 * Atribuição de dados a cada conjunto, tratando as métricas e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param entrada Arquivo de entrada
 * @param dataset Arquivo com os dados
 * @param saida Arquivo de saída com as médias das métricas
 * @param k int elementos para mediana
 */
void fluxoQuickSortMediana(fstream &entrada, fstream &dataset, fstream &saida, int k);

/**
 * Execução específica para dados do tipo inteiro para o quicksort com inserção
 * Leitura de quantos conjuntos de tamanho N serão trabalhados na execução do programa.
 * Atribuição de dados a cada conjunto, tratando as métricas e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param entrada Arquivo de entrada
 * @param dataset Arquivo com os dados
 * @param saida Arquivo de saída com as médias das métricas
 * @param m int tamanho partição para usar o insertionsort
 */
void fluxoQuickSortInsercao(fstream &entrada, fstream &dataset, fstream &saida, int m);

#endif //TRATAMENTO_H_INCLUDED