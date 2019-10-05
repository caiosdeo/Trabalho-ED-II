//Biblioteca destinada para fluxos do cenario
#ifndef CENARIO4_H_INCLUDED
#define CENARIO4_H_INCLUDED

//Inclusão de outras interfaces/bibliotecas
#include <fstream>
#include <chrono>
#include "../classes/review.h"

using namespace std;

/**
 * Execução específica para cenário 4
 * Tratando as métricas, de um conjunto específico para cada algoritmo e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param conjunto conjunto de tamanho N
 * @param saida Arquivo de saída com as métricas
 */
void fluxoCenario4(unsigned* ids, unsigned n, fstream &saida);

#endif //CENARIO4_H_INCLUDED