//Biblioteca destinada para fluxos do cenario

#ifndef CENARIO1_H_INCLUDED
#define CENARIO1_H_INCLUDED

//Inclusão de outras interfaces/bibliotecas
#include <fstream>
#include <chrono>

using namespace std;

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

#endif //CENARIO1_H_INCLUDED