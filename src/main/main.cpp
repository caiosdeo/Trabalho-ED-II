#include <iostream>
#include <fstream>
#include "tratamento.h"

using namespace std;

int main(){

    // Variaveis para manipular arquivos
    fstream entrada, dataset, saida; 

    //Limpando o arquivo de saída 
    saida.open("../../saida.txt", ios::out);    
    saida.close();

    // ! serão 5 execuções para cada conjunto, sementes diferentes
    for(int i = 0; i < 5; i++){

        cout << "Execução: " << i + 1 << endl;

        //Loop para rodar para os dois tipos de estruturas em única execução
        for(int j = 0; j < 2; j++){

            entrada.open("../../entrada.txt", ios::in); // Arquivo de entrada só como leitura
            saida.open("../../saida.csv", ios::out | ios::app); // Arquivo de saída como escrita
            dataset.open("../../processados.txt", ios::in); // Arquivo de dados como leitura

            // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
            if(entrada.is_open())
                if(dataset.is_open())
                    if(saida.is_open()){
                        if(j){ //Como j só possui dois valores, ele irá alternar nos processos
                            cout << "Inicio de execução para Reviews" << endl;
                            executarDadosReview(entrada, dataset, saida); // Executando fluxo para conjunto de reviews
                            cout << "Fim de execução para Reviews" << endl;
                        }else{
                            cout << "Inicio de execução para inteiros" << endl;
                            executarDadosVetor(entrada, dataset, saida); // Executando fluxo para conjunto de inteiros
                            cout << "Fim de execução para inteiros" << endl;
                        }
                    }else
                        cout << "Não foi possível abrir o arquivo de saída" << endl;
                else
                    cout << "Não foi possível abrir o arquivo de dados" << endl;
            else
                cout << "Não foi possível abrir o arquivo de entrada" << endl;

            // Salvando e fechando os arquivos usados
            entrada.close();
            saida.close();
            dataset.close();

        }

    }

    return 0;

}