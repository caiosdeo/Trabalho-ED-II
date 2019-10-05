//Biblioteca destinada para operações de menu na main
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//Inclusão de outras interfaces/bibliotecas
#include <fstream>

using namespace std;

/////////////////////////////////////////
// Protótipos das funções da bilioteca //
/////////////////////////////////////////

/**
 * Procedimento de impressão do menu do programa
 * @author caiosdeo 
 */
unsigned menu();

/**
 * Método para execução de uma opção do menu
 * @author caiosdeo
 * @param selecao unsigned opção selecionada
 * @param saida ofstream& endereço do arquivo de saída
*/
void selecionar(unsigned selecao);


#endif //MENU_H_INCLUDED