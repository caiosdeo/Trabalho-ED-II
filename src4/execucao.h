//Biblioteca destinada para a execução do módulo
#ifndef EXECUCAO_H_INCLUDED
#define EXECUCAO_H_INCLUDED

//Inclusão de outras interfaces/bibliotecas
#include <fstream>

using namespace std;

/////////////////////////////////////////
// Protótipos das funções da bilioteca //
/////////////////////////////////////////

/**
 * Método para execução do programa
 * @author caiosdeo
*/
void executar();

/**
 * Execução específica para inserção na fase 4
 * Tratando as métricas, de um conjunto específico para cada algoritmo e colocando em um arquivo de saída.
 *
 * @author caiosdeo
 * @param conjunto conjunto de tamanho N
 * @param n tamanho do conjunto
 * @param saida Arquivo de saída com as métricas
 */
void fluxo(string* conjunto, int n, fstream &saida);

#endif //EXECUCAO_H_INCLUDED