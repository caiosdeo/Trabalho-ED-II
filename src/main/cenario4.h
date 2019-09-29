//Biblioteca destinada para fluxos do cenario
#ifndef CENARIO4_H_INCLUDED
#define CENARIO4_H_INCLUDED

//Inclusão de outras interfaces/bibliotecas
#include <fstream>
#include <chrono>

using namespace std;

/**
 * Execução específica para dados do tipo inteiro para hash sondagem linear
 * Leitura de quantos conjuntos de tamanho N serão trabalhados na execução do programa.
 * Atribuição de dados a cada conjunto, tratando as métricas e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param entrada Arquivo de entrada
 * @param dataset Arquivo com os dados
 * @param saida Arquivo de saída com as médias das métricas
 * @param versao int parametro para identificar a variação do algoritmos
 */
void fluxoHashSondLin(fstream &entrada, fstream &dataset, fstream &saida, int versao);

/**
 * Execução específica para dados do tipo inteiro para hash sondagem quadratica
 * Leitura de quantos conjuntos de tamanho N serão trabalhados na execução do programa.
 * Atribuição de dados a cada conjunto, tratando as métricas e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param entrada Arquivo de entrada
 * @param dataset Arquivo com os dados
 * @param saida Arquivo de saída com as médias das métricas
 * @param versao int parametro para identificar a variação do algoritmos
 */
void fluxoHashSondQuad(fstream &entrada, fstream &dataset, fstream &saida, int versao);

/**
 * Execução específica para dados do tipo inteiro para duplo hash
 * Leitura de quantos conjuntos de tamanho N serão trabalhados na execução do programa.
 * Atribuição de dados a cada conjunto, tratando as métricas e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param entrada Arquivo de entrada
 * @param dataset Arquivo com os dados
 * @param saida Arquivo de saída com as médias das métricas
 * @param versao int parametro para identificar a variação do algoritmos
 */
void fluxoDuploHash(fstream &entrada, fstream &dataset, fstream &saida, int versao);

/**
 * Execução específica para dados do tipo inteiro para hash encadeamento separado
 * Leitura de quantos conjuntos de tamanho N serão trabalhados na execução do programa.
 * Atribuição de dados a cada conjunto, tratando as métricas e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param entrada Arquivo de entrada
 * @param dataset Arquivo com os dados
 * @param saida Arquivo de saída com as médias das métricas
 * @param versao int parametro para identificar a variação do algoritmos
 */
void fluxoHashEncadSeparado(fstream &entrada, fstream &dataset, fstream &saida, int versao);

/**
 * Execução específica para dados do tipo inteiro para hash encadeamento coalescido
 * Leitura de quantos conjuntos de tamanho N serão trabalhados na execução do programa.
 * Atribuição de dados a cada conjunto, tratando as métricas e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param entrada Arquivo de entrada
 * @param dataset Arquivo com os dados
 * @param saida Arquivo de saída com as médias das métricas
 * @param versao int parametro para identificar a variação do algoritmos
 */
void fluxoHashEncadCoal(fstream &entrada, fstream &dataset, fstream &saida, int versao);

#endif //CENARIO4_H_INCLUDED