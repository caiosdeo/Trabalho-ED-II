#include <iostream>
#include <fstream>
#include "tratamento.h"

using namespace std;

int main(){

    fstream entrada;
    fstream dataset;
    fstream saida; 

    entrada.open("../../entrada.txt", ios::in);
    saida.open("../../saida.txt", ios::out);
    dataset.open("../../processados.txt", ios::in);

    if(entrada.is_open())
        if(dataset.is_open())
            if(saida.is_open())
                leitura(entrada, dataset, saida, 1);
            else
                cout << "Não foi possível abrir o arquivo de saída" << endl;
        else
            cout << "Não foi possível abrir o arquivo de dados" << endl;
    else
        cout << "Não foi possível abrir o arquivo de entrada" << endl;

    entrada.close();
    saida.close();
    dataset.close();

    return 0;

}