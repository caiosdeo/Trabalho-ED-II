//Biblioteca destinada para fluxos do cenario
#ifndef CENARIO2_H_INCLUDED
#define CENARIO2_H_INCLUDED

//Inclusão de outras interfaces/bibliotecas
#include <fstream>
#include <chrono>

using namespace std;

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
 * @param versao int parametro para identificar a variação do algoritmos
 */
void fluxoQuickSortMediana(fstream &entrada, fstream &dataset, fstream &saida, int k, int versao);

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
 * @param versao int parametro para identificar a variação do algoritmos
 */
void fluxoQuickSortInsercao(fstream &entrada, fstream &dataset, fstream &saida, int m, int versao);

#endif //CENARIO2_H_INCLUDED