//Biblioteca destinada para operações básicas com arquivos

#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

//Inclusão de outras interfaces/bibliotecas
#include <fstream>

using namespace std;

/////////////////////////////////////////
// Protótipos das funções da bilioteca //
/////////////////////////////////////////

/**
 * Leitura de quantos conjuntos de tamanho N serão trabalhados na execução do programa.
 * Atribuição de dados a cada conjunto, retornando os mesmos em uma matriz.
 *
 * @author caiosdeo
 * @param entrada Arquivo de entrada
 * @param dataset Arquivo com os dados
 * @return conjuntos Matriz com conjuntos
 */
Review** leitura(fstream &entrada, fstream &dataset);

#endif //ARQUIVO_H_INCLUDED