#include <iostream>
#include <fstream>
#include "tratamento.h"

using namespace std;

int main(){

    // Variaveis para manipular arquivos
    fstream entrada, dataset, saida; 

    /**
     * Variavel para controlar o tipo de dado:
     * 0 - Vetores de inteiros
     * 1 - Vetores de Reviews
     */
    int estrutura = 0;

    //Limpando o arquivo de saída 
    saida.open("../../saida.txt", ios::out);    
    saida.close();

    // ! serão 5 execuções para cada conjunto, sementes diferentes
    for(int i = 0; i < 5; i++){

        entrada.open("../../entrada.txt", ios::in); // Arquivo de entrada só como leitura
        saida.open("../../saida.txt", ios::out | ios::app); // Arquivo de saída como escrita
        dataset.open("../../processados.txt", ios::in); // Arquivo de dados como leitura

        // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
        if(entrada.is_open())
            if(dataset.is_open())
                if(saida.is_open())
                    if(estrutura)
                        executarDadosReview(entrada, dataset, saida); // Executando fluxo para conjunto de reviews
                    else
                        executarDadosVetor(entrada, dataset, saida); // Executando fluxo para conjunto de inteiros
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

    }

    return 0;

}