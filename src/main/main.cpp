#include <iostream>
#include <fstream>
#include "tratamento.h"

using namespace std;

int main(){

    // Variaveis para manipular arquivos
    fstream entrada, dataset, saida; 

    entrada.open("../../entrada.txt", ios::in); // Arquivo de entrada só como leitura
    saida.open("../../saida.txt", ios::out); // Arquivo de saída como escrita
    dataset.open("../../processados.txt", ios::in); // Arquivo de dados como leitura

    // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
    if(entrada.is_open())
        if(dataset.is_open())
            if(saida.is_open())
                leitura(entrada, dataset, saida, 1); // Executando
            else
                cout << "Não foi possível abrir o arquivo de saída" << endl;
        else
            cout << "Não foi possível abrir o arquivo de dados" << endl;
    else
        cout << "Não foi possível abrir o arquivo de entrada" << endl;

    // Salvando e fechando os arquivos usados
    entrada.close();
    saida.close();
    dataset.close();

    return 0;

}