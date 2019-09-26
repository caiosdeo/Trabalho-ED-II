#include <iostream>
#include <fstream>
#include "tratamento.h"

using namespace std;

int menu(){

    int selecao;

    cout << "MENU" << endl;
    cout << "----" << endl;
    cout << "[1] Cenário 1" << endl;
    cout << "[2] Cenário 2" << endl;
    cout << "[3] Cenário 3" << endl;
    cout << "[4] Cenário 4" << endl;
    cout << "[0] Sair" << endl;

    cin >> selecao;

    int i = system("clear");

    return selecao;

}

void selecionar(int selecao, fstream& saida){

    fstream entrada, dataset;

     // ! serão 5 execuções para cada conjunto, sementes diferentes
    for(int i = 0; i < 5; i++){

        cout << "Execução: " << i + 1 << endl;                 

        switch (selecao){

            //Cenário 1
            case 1:{

                saida << endl << "Cenário 1" << endl;

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
                                    fluxoQuickSortReview(entrada, dataset, saida); // Executando fluxo para conjunto de reviews
                                    cout << "Fim de execução para Reviews" << endl;
                                }else{
                                    cout << "Inicio de execução para inteiros" << endl;
                                    fluxoQuickSortInteiro(entrada, dataset, saida); // Executando fluxo para conjunto de inteiros
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

                break;
            }

            //Cenário 2
            case 2:{
                
                saida << endl << "Cenário 2" << endl;

                //Loop para rodar para os dois tipos de estruturas em única execução
                for(int j = 0; j < 3; j++){

                    entrada.open("../../entrada.txt", ios::in); // Arquivo de entrada só como leitura
                    saida.open("../../saida.csv", ios::out | ios::app); // Arquivo de saída como escrita
                    dataset.open("../../processados.txt", ios::in); // Arquivo de dados como leitura   

                    // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
                    if(entrada.is_open())
                        if(dataset.is_open())
                            if(saida.is_open()){
                                if(j == 0){ // * j = 0 quicksort comum
                                
                                    cout << "Inicio de execução quicksort" << endl;
                                    fluxoQuickSortInteiro(entrada, dataset, saida); // Executando fluxo para conjunto de inteiros
                                    cout << "Fim de execução quicksort" << endl;
                                
                                }else if(j == 1){ // * j = 1 quicksort mediana
                                
                                    cout << "Inicio de execução quicksort mediana" << endl;
                                    //fluxoQuickSortMediana(entrada, dataset, saida, 3); // Executando fluxo para conjunto de inteiros
                                    cout << "Fim de execução quicksort mediana" << endl;

                                }else{ // j = 2

                                    cout << "Inicio de execução quicksort insercao" << endl;
                                    fluxoQuickSortInsercao(entrada, dataset, saida, 10); // Executando fluxo para conjunto de inteiros
                                    cout << "Fim de execução quicksort insercao" << endl;

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

                break;
            }

            //Cenário 3
            case 3:{

                break;
            }

            //Cenário 4
            case 4:{
                
                break;
            }

            default:
                cout << "Saindo..." << endl;
                break;

        }

    }

}

int mainMenu(){

    int selecao = 1;

    fstream saida;

    while(selecao != 0){   

        saida.open("../../saida.csv", ios::out | ios::app); 

        int i = system("clear");
        selecao = menu();

        if(saida.is_open())
            selecionar(selecao, saida);

        else
            cout << "Não foi possível abrir o arquivo de saida" << endl;

    }

    return 0;
}
