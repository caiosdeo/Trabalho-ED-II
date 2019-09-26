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
int menu();

/**
 * Método para execução de uma opção do menu
 * @author caiosdeo
 * @param selecao int opção selecionada
 * @param saida ofstream& endereço do arquivo de saída
*/
void selecionar(int selecao, fstream& saida);

/**
 * Método para selecionar uma opção do menu
 * @author caiosdeo
 * @param saida ofstream& endereço do arquivo de saída
 * @return 0
*/
int mainMenu();

#endif //MENU_H_INCLUDED