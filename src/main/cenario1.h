//Biblioteca destinada para fluxos do cenario

#ifndef CENARIO1_H_INCLUDED
#define CENARIO1_H_INCLUDED

//Inclusão de outras interfaces/bibliotecas
#include <fstream>
#include <chrono>

using namespace std;

/**
 * Execução específica para cenário 1
 * Tratando as métricas, de um conjunto específico para cada algoritmo e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param conjunto conjunto de tamanho N
 * @param saida Arquivo de saída com as métricas
 */
void fluxoCenario1(Review* conjunto, fstream &saida);

#endif //CENARIO1_H_INCLUDED