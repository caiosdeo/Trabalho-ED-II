//Biblioteca destinada para fluxos do cenario
#ifndef CENARIO3_H_INCLUDED
#define CENARIO3_H_INCLUDED

//Inclusão de outras interfaces/bibliotecas
#include <fstream>
#include <chrono>

using namespace std;

/**
 * Execução específica para cenário 3
 * Tratando as métricas, de um conjunto específico para cada algoritmo e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param conjunto conjunto de tamanho N
 * @param saida Arquivo de saída com as métricas
 */
void fluxoCenario3(Review* conjunto, int n, fstream &saida);


#endif //CENARIO3_H_INCLUDED