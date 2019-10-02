#include <iostream>
#include <fstream>
#include "classes/review.h"
#include "tratamento.h"
#include "cenario1.h"
#include "cenario2.h"
#include "cenario3.h"
#include "cenario4.h"

using namespace std;

int menu()
{

    int selecao;

    cout << "MENU" << endl;
    cout << "----" << endl;
    cout << "[1] Cenário 1" << endl;
    cout << "[2] Cenário 2" << endl;
    cout << "[3] Cenário 3" << endl;
    cout << "[4] Cenário 4" << endl;
    cout << "[0] Encerrar" << endl;

    cin >> selecao;

    int clear = system("clear");

    return selecao;
}

void selecionar(int selecao){

    fstream entrada, dataset, saida;

    // ! serão 5 execuções para cada conjunto, sementes diferentes
    for (int i = 0; i < 5; i++){

        if (selecao)
            cout << "Execução: " << i + 1 << endl;

        switch (selecao){

            //Cenário 1
            case 1:{

                entrada.open("../../entrada.txt", ios::in);         // Arquivo de entrada só como leitura
                saida.open("../../saidaCenario1.csv", ios::out | ios::app); // Arquivo de saída como escrita
                dataset.open("../../processados.txt", ios::in);     // Arquivo de dados como leitura

                // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
                if (entrada.is_open())
                    if (dataset.is_open())
                        if (saida.is_open()){
                            
                            // Variaveis para leitura do arquivo de entrada
                            int qtdConjuntos, n;

                            // Lendo quantos conjuntos teremos
                            entrada >> qtdConjuntos;

                            while(entrada >> n){

                                Review* conjunto = new Review[n];
 
                                // Colocando dados no conjunto
                                conjunto = conjunto->leituraDados(dataset, n);
                                
                                // Executando para as versoes, o conjunto
                                fluxoCenario1(conjunto, n, saida); 

                                // Desalocando o conjunto
                                delete [] conjunto;

                            }
                        
                        }
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
            

                break;
            }

            //Cenário 2
            case 2:{

                //Loop para rodar para os cinco tipos de versões em única execução
                for (int versao = 0; versao < 5; versao++){

                    entrada.open("../../entrada.txt", ios::in);         // Arquivo de entrada só como leitura
                    saida.open("../../saidaCenario2.csv", ios::out | ios::app); // Arquivo de saída como escrita
                    dataset.open("../../processados.txt", ios::in);     // Arquivo de dados como leitura

                    // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
                    if (entrada.is_open())
                        if (dataset.is_open())
                            if (saida.is_open()){

                                // Variaveis para leitura do arquivo de entrada
                                int qtdConjuntos, n;

                                // Lendo quantos conjuntos teremos
                                entrada >> qtdConjuntos;

                                while(entrada >> n){

                                    Review* conjunto = new Review[n];
    
                                    // Colocando dados no conjunto
                                    conjunto = conjunto->leituraDados(dataset, n);
                                    
                                    // Executando para as versoes, o conjunto
                                    fluxoCenario2(conjunto, n, saida); 

                                    // Desalocando o conjunto
                                    delete [] conjunto;

                                }

                            }
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

                break;
            }

            //Cenário 3
            case 3:{

                //Loop para rodar para os cinco tipos de versões em única execução
                for (int versao = 0; versao < 5; versao++){

                    entrada.open("../../entrada.txt", ios::in);         // Arquivo de entrada só como leitura
                    saida.open("../../saidaCenario3.csv", ios::out | ios::app); // Arquivo de saída como escrita
                    dataset.open("../../processados.txt", ios::in);     // Arquivo de dados como leitura

                    // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
                    if (entrada.is_open())
                        if (dataset.is_open())
                            if (saida.is_open()){

                                switch (versao){

                                case 0: // * versao = 0 quicksort mediana k = 5

                                    cout << "Executando quicksort mediana k = 5" << endl;
                                    fluxoQuickSortMediana(entrada, dataset, saida, 5, versao); // Executando fluxo para conjunto de inteiros

                                    break;

                                case 1: // * versao = 1 insertion sort
                                    cout << "Executando insertion sort" << endl;
                                    fluxoInsertionSort(entrada, dataset, saida, versao); // Executando fluxo para conjunto de inteiros

                                    break;

                                case 2: // * versao = 2 merge sort
                                    cout << "Executando merge sort" << endl;
                                    fluxoMergeSort(entrada, dataset, saida, versao); // Executando fluxo para conjunto de inteiros

                                    break;

                                case 3: // * versao = 3 heapsort
                                    cout << "Executando heapsort" << endl;
                                    fluxoHeapSort(entrada, dataset, saida, versao); // Executando fluxo para conjunto de inteiros

                                    break;

                                case 4: // * versao = 4 gnomesort
                                    cout << "Executando gnomesort" << endl;
                                    fluxoGnomeSort(entrada, dataset, saida, versao); // Executando fluxo para conjunto de inteiros

                                    break;

                                default:
                                    break;
                                }
                            }
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

                break;
            }

            //Cenário 4
            case 4:{

                //Loop para rodar para os cinco tipos de versões em única execução
                for (int versao = 0; versao < 5; versao++){

                    entrada.open("../../entrada.txt", ios::in);         // Arquivo de entrada só como leitura
                    saida.open("../../saidaCenario4.csv", ios::out | ios::app); // Arquivo de saída como escrita
                    dataset.open("../../processados.txt", ios::in);     // Arquivo de dados como leitura

                    // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
                    if (entrada.is_open())
                        if (dataset.is_open())
                            if (saida.is_open()){

                                switch (versao){

                                case 0: // * versao = 0 hash sondagem linear

                                    cout << "Executando hash sondagem linear" << endl;
                                    fluxoHashSondLin(entrada, dataset, saida, versao); // Executando fluxo para conjunto de inteiros

                                    break;

                                case 1: // * versao = 1 hash sondagem quadratica
                                    cout << "Executando hash sondagem quadratica" << endl;
                                    fluxoHashSondQuad(entrada, dataset, saida, versao); // Executando fluxo para conjunto de inteiros

                                    break;

                                case 2: // * versao = 2 duplo hash
                                    cout << "Executando duplo hash" << endl;
                                    fluxoDuploHash(entrada, dataset, saida, versao); // Executando fluxo para conjunto de inteiros

                                    break;

                                case 3: // * versao = 3 hash encadeamento separado
                                    cout << "Executando hash encadeamento separado" << endl;
                                    fluxoHashEncadSeparado(entrada, dataset, saida, versao); // Executando fluxo para conjunto de inteiros

                                    break;

                                case 4: // * versao = 4 hash encadeamento coalescido
                                    cout << "Executando hash encadeamento coalescido" << endl;
                                    fluxoHashEncadCoal(entrada, dataset, saida, versao); // Executando fluxo para conjunto de inteiros

                                    break;

                                default:
                                    break;
                                }
                            }
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

                break;
            }

            default:
                break;
        }

        int clear = system("clear");
    }
}

int mainMenu(){

    int selecao = 1;

    while (selecao != 0){

        int clear = system("clear");
        selecao = menu();

        selecionar(selecao);

    }

    return 0;
}
