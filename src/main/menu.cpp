#include <iostream>
#include <fstream>
#include "tratamento.h"
#include "cenario1.h"
#include "cenario2.h"
#include "cenario3.h"

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

                //Loop para rodar para os dois tipos de estruturas em única execução
                for (int versao = 0; versao < 2; versao++){

                    entrada.open("../../entrada.txt", ios::in);         // Arquivo de entrada só como leitura
                    saida.open("../../saidaCenario1.csv", ios::out | ios::app); // Arquivo de saída como escrita
                    dataset.open("../../processados.txt", ios::in);     // Arquivo de dados como leitura

                    // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
                    if (entrada.is_open())
                        if (dataset.is_open())
                            if (saida.is_open()){
                                
                                if (versao){//Como versao só possui dois valores, ele irá alternar nos processos
                                    cout << "Executando quickSort para Reviews" << endl;
                                    fluxoQuickSortReview(entrada, dataset, saida); // Executando fluxo para conjunto de reviews
                                
                                }else{
                                    cout << "Executando quickSort para inteiros" << endl;
                                    fluxoQuickSortInteiro(entrada, dataset, saida); // Executando fluxo para conjunto de inteiros
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

                                switch (versao){
                                case 0: // * versao = 0 quicksort comum

                                    cout << "Executando quicksort" << endl;
                                    fluxoQuickSortInteiro(entrada, dataset, saida); // Executando fluxo para conjunto de inteiros

                                    break;

                                case 1: // * versao = 1 quicksort mediana k = 3

                                    cout << "Executando quicksort mediana k = 3" << endl;
                                    fluxoQuickSortMediana(entrada, dataset, saida, 3, versao); // Executando fluxo para conjunto de inteiros

                                    break;

                                case 2: // * versao = 2 quicksort mediana k = 5

                                    cout << "Executando quicksort mediana k = 5" << endl;
                                    fluxoQuickSortMediana(entrada, dataset, saida, 5, versao); // Executando fluxo para conjunto de inteiros

                                    break;

                                case 3: // * versao = 3 quicksort inserção m = 10

                                    cout << "Executando quicksort insercao m = 10" << endl;
                                    fluxoQuickSortInsercao(entrada, dataset, saida, 10, versao); // Executando fluxo para conjunto de inteiros

                                    break;

                                case 4: // * versao = 4 quicksort insercao m = 100

                                    cout << "Executando quicksort insercao m = 100" << endl;
                                    fluxoQuickSortInsercao(entrada, dataset, saida, 100, versao); // Executando fluxo para conjunto de inteiros

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

                                case 0: // TODO: pegar a melhor versão do cenário 2 versao = 0 quicksort comum
                                    cout << "Executando quicksort" << endl;
                                    fluxoQuickSortInteiro(entrada, dataset, saida); // Executando fluxo para conjunto de inteiros

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
