#include <iostream>
#include <fstream>
#include "../classes/review.h"
#include "../algoritmos/hash/auxiliaresHash.h"
#include "tratamento.h"
#include "cenario1.h"
#include "cenario2.h"
#include "cenario3.h"
#include "cenario4.h"

using namespace std;

unsigned menu()
{

    unsigned selecao;

    cout << "MENU" << endl;
    cout << "----" << endl;
    cout << "[1] Cenário 1" << endl;
    cout << "[2] Cenário 2" << endl;
    cout << "[3] Cenário 3" << endl;
    cout << "[4] Cenário 4" << endl;
    cout << "[0] Encerrar" << endl;

    cin >> selecao;

    unsigned clear = system("clear");

    return selecao;
}

void selecionar(unsigned selecao){

    fstream entrada, dataset, saida;

    // ! serão 5 execuções para cada conjunto, sementes diferentes
    for (unsigned i = 0; i < 5; i++){

        if (selecao)
            cout << "Execução: " << i + 1 << endl;

        switch (selecao){

            //Cenário 1
            case 1:{

                entrada.open("../../entrada1.txt", ios::in);         // Arquivo de entrada só como leitura
                saida.open("../../saidaCenario1.csv", ios::out | ios::app); // Arquivo de saída como escrita
                dataset.open("../../processadosFase1.txt", ios::in);     // Arquivo de dados como leitura

                // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
                if (entrada.is_open())
                    if (dataset.is_open())
                        if (saida.is_open()){
                            
                            // Variaveis para leitura do arquivo de entrada
                            unsigned qtdConjuntos, n;

                            // Lendo quantos conjuntos teremos
                            entrada >> qtdConjuntos;

                            while(entrada >> n){

                                if(n != 100000)
                                    continue;

                                Review* conjunto = (Review*)calloc(n, sizeof(Review));
 
                                // Colocando dados no conjunto
                                conjunto = conjunto->leituraDados(dataset, n);
                                
                                // Executando para as versoes, o conjunto
                                fluxoCenario1(conjunto, n, saida); 

                                // Desalocando o conjunto
                                free(conjunto);

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

                entrada.open("../../entrada24.txt", ios::in);         // Arquivo de entrada só como leitura
                saida.open("../../saidaCenario2.csv", ios::out | ios::app); // Arquivo de saída como escrita
                dataset.open("../../processadosFase1.txt", ios::in);     // Arquivo de dados como leitura

                // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
                if (entrada.is_open())
                    if (dataset.is_open())
                        if (saida.is_open()){

                            // Variaveis para leitura do arquivo de entrada
                            unsigned qtdConjuntos, n;

                            // Lendo quantos conjuntos teremos
                            entrada >> qtdConjuntos;

                            while(entrada >> n){

                                if(n != 500000)
                                    continue;

                                Review* conjunto = (Review*)calloc(n, sizeof(Review));

                                // Colocando dados no conjunto
                                conjunto = conjunto->leituraDados(dataset, n);
                                unsigned *v = gerarVetorIds(conjunto, n);
                                
                                // Desalocando o conjunto
                                free(conjunto);

                                // Executando para as versoes, o conjunto
                                fluxoCenario2(v, n, saida); 

                                // Desalocando os ids
                                free(v);

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

            //Cenário 3
            case 3:{

                entrada.open("../../entrada24.txt", ios::in);         // Arquivo de entrada só como leitura
                saida.open("../../saidaCenario3.csv", ios::out | ios::app); // Arquivo de saída como escrita
                dataset.open("../../processadosFase1.txt", ios::in);     // Arquivo de dados como leitura

                // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
                if (entrada.is_open())
                    if (dataset.is_open())
                        if (saida.is_open()){

                            // Variaveis para leitura do arquivo de entrada
                            unsigned qtdConjuntos, n;

                            // Lendo quantos conjuntos teremos
                            entrada >> qtdConjuntos;

                            while(entrada >> n){

                                if(n != 500000)
                                    continue;

                                Review* conjunto = (Review*)calloc(n, sizeof(Review));

                                // Colocando dados no conjunto
                                conjunto = conjunto->leituraDados(dataset, n);
                                unsigned *v = gerarVetorIds(conjunto, n);
                                
                                // Desalocando o conjunto
                                free(conjunto);

                                // Executando para as versoes, o conjunto
                                fluxoCenario3(v, n, saida);

                                // Desalocando os ids
                                free(v);

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

            //Cenário 4
            case 4:{

                entrada.open("../../entrada24.txt", ios::in);         // Arquivo de entrada só como leitura
                saida.open("../../saidaCenario4.csv", ios::out | ios::app); // Arquivo de saída como escrita
                dataset.open("../../processadosFase1.txt", ios::in);     // Arquivo de dados como leitura

                // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
                if (entrada.is_open())
                    if (dataset.is_open())
                        if (saida.is_open()){

                            // Variaveis para leitura do arquivo de entrada
                            unsigned qtdConjuntos, n;

                            // Lendo quantos conjuntos teremos
                            entrada >> qtdConjuntos;

                            while(entrada >> n){

                                if(n != 500000)
                                    continue;

                                Review* conjunto = (Review*)calloc(n, sizeof(Review));

                                // Colocando dados no conjunto
                                conjunto = conjunto->leituraDados(dataset, n);
                                unsigned *v = gerarConjuntoChaves(conjunto, n);

                                for(int i = 0; i < n; i++)
                                    cout << v[i] << " ";
                                cout << endl;
                                
                                // Desalocando o conjunto
                                free(conjunto);

                                // Executando para as versoes, o conjunto
                                fluxoCenario4(v, n, saida);

                                // Desalocando as chaves geradas
                                free(v);

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

            default:
                break;
        }

        unsigned clear = system("clear");
    }
}
