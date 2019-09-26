#include <iostream>
#include <fstream>
#include "menu.h"

using namespace std;

int main(){

    // Variaveis para manipular arquivos
    fstream saida; 

    //Limpando o arquivo de saída 
    saida.open("../../saida.csv", ios::out);    
    saida.close();

    mainMenu();

    return 0;

}