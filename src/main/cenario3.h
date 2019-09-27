//Biblioteca destinada para fluxos do cenario
#ifndef CENARIO3_H_INCLUDED
#define CENARIO3_H_INCLUDED

//Inclusão de outras interfaces/bibliotecas
#include <fstream>
#include <chrono>

using namespace std;

/**
 * Execução específica para dados do tipo inteiro para o insertion sort
 * Leitura de quantos conjuntos de tamanho N serão trabalhados na execução do programa.
 * Atribuição de dados a cada conjunto, tratando as métricas e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param entrada Arquivo de entrada
 * @param dataset Arquivo com os dados
 * @param saida Arquivo de saída com as médias das métricas
 * @param versao int parametro para identificar a variação do algoritmos
 */
void fluxoInsertionSort(fstream &entrada, fstream &dataset, fstream &saida, int versao);

/**
 * Execução específica para dados do tipo inteiro para o merge sort
 * Leitura de quantos conjuntos de tamanho N serão trabalhados na execução do programa.
 * Atribuição de dados a cada conjunto, tratando as métricas e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param entrada Arquivo de entrada
 * @param dataset Arquivo com os dados
 * @param saida Arquivo de saída com as médias das métricas
 * @param versao int parametro para identificar a variação do algoritmos
 */
void fluxoMergeSort(fstream &entrada, fstream &dataset, fstream &saida, int versao);

/**
 * Execução específica para dados do tipo inteiro para o heap sort
 * Leitura de quantos conjuntos de tamanho N serão trabalhados na execução do programa.
 * Atribuição de dados a cada conjunto, tratando as métricas e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param entrada Arquivo de entrada
 * @param dataset Arquivo com os dados
 * @param saida Arquivo de saída com as médias das métricas
 * @param versao int parametro para identificar a variação do algoritmos
 */
void fluxoHeapSort(fstream &entrada, fstream &dataset, fstream &saida, int versao);

/**
 * Execução específica para dados do tipo inteiro para o pigeonhole sort
 * Leitura de quantos conjuntos de tamanho N serão trabalhados na execução do programa.
 * Atribuição de dados a cada conjunto, tratando as métricas e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param entrada Arquivo de entrada
 * @param dataset Arquivo com os dados
 * @param saida Arquivo de saída com as médias das métricas
 * @param versao int parametro para identificar a variação do algoritmos
 */
void fluxoPigeonholeSort(fstream &entrada, fstream &dataset, fstream &saida, int versao);

#endif //CENARIO3_H_INCLUDED