#include <iostream>
#include <fstream>
#include "menu.h"
#include "cenario4.h"

using namespace std;

int main(){

    //mainMenu();

    fstream entrada, saida, dataset;

    entrada.open("../../entrada.txt", ios::in);         // Arquivo de entrada só como leitura
    saida.open("../../saidaCenario4.csv", ios::out | ios::app); // Arquivo de saída como escrita
    dataset.open("../../processados.txt", ios::in);  

    fluxoHashSondLin(entrada, dataset, saida, 0);

    entrada.close();
    dataset.close();
    saida.close();

    return 0;

}