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

    if(selecao == 1)
        entrada.open("../../entrada1.txt", ios::in); // Arquivo de entrada cenário 1 só como leitura
    else
        entrada.open("../../entrada24.txt", ios::in); // Arquivo de entrada cenário 2-4 só como leitura

    dataset.open("../../processadosFase1.txt", ios::in); // Arquivo de dados como leitura

    // Variaveis para leitura do arquivo de entrada
    unsigned qtdConjuntos, n;

    // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
    if(entrada.is_open()){
        if(dataset.is_open()){

            // Lendo quantos conjuntos teremos
            entrada >> qtdConjuntos;

            // Lendo os N
            while(entrada >> n){

                // Colocando dados no conjunto
                Review* conjunto = conjunto->leituraDados(dataset, n);

                // Imprimindo o valor de N
                cout << "N: " << n << endl;

                // Escolhendo o cenário
                switch (selecao){

                    //Cenário 1
                    case 1:{

                        //Abrindo arquivo de saida do cenário 
                        saida.open("../../saidaCenario1.csv", ios::out | ios::app); // Arquivo de saída como escrita

                        // Verificando se o arquivo de saida está aberto
                        if(saida.is_open()){

                            // ! serão 5 execuções para cada conjunto     
                            for (unsigned i = 0; i < 5; i++){

                                // Imprimindo a execução atual do Fluxo
                                cout << "Execução: " << i + 1 << endl;

                                embaralharEstruturas(conjunto, n);
                                
                                // Executando para as versoes, o conjunto
                                fluxoCenario1(conjunto, n, saida); 

                            }
                        
                        }
                        else
                            cout << "Não foi possível abrir o arquivo de saída" << endl;                    

                        // Salvando e fechando os arquivos usados
                        saida.close();                    

                        break;
                    }

                    //Cenário 2
                    case 2:{

                        //Abrindo arquivo de saida do cenário 
                        saida.open("../../saidaCenario2.csv", ios::out | ios::app); // Arquivo de saída como escrita

                        // Verificando se o arquivo de saida está aberto
                        if (saida.is_open()){

                            unsigned *v = gerarVetorIds(conjunto, n);

                            // ! serão 5 execuções para cada conjunto, sementes diferentes      
                            for (unsigned i = 0; i < 5; i++){

                                // Imprimindo a execução atual do Fluxo
                                cout << "Execução: " << i + 1 << endl;

                                if(n != 500000)
                                    continue;

                                // Executando para as versoes, o conjunto
                                fluxoCenario2(v, n, saida); 

                            }

                            // Desalocando os ids
                            free(v);

                        }
                        else
                            cout << "Não foi possível abrir o arquivo de saída" << endl;

                        // Salvando e fechando os arquivos usados
                        saida.close();

                        break;
                    }

                    //Cenário 3
                    case 3:{

                        //Abrindo arquivo de saida do cenário 
                        saida.open("../../saidaCenario3.csv", ios::out | ios::app); // Arquivo de saída como escrita

                        // Verificando se o arquivo de saida está aberto
                        if (saida.is_open()){

                            unsigned *v = gerarVetorIds(conjunto, n);

                            // ! serão 5 execuções para cada conjunto, sementes diferentes      
                            for (unsigned i = 0; i < 5; i++){

                                // Imprimindo a execução atual do Fluxo
                                cout << "Execução: " << i + 1 << endl;

                                if(n != 500000)
                                    continue;

                                // Executando para as versoes, o conjunto
                                fluxoCenario3(v, n, saida);

                            }

                            // Desalocando os ids
                            free(v);
                            
                        }
                        else
                            cout << "Não foi possível abrir o arquivo de saída" << endl;

                        // Salvando e fechando os arquivos usados
                        saida.close();

                        break;
                    }

                    //Cenário 4
                    case 4:{

                        //Abrindo arquivo de saida do cenário 
                        saida.open("../../saidaCenario4.csv", ios::out | ios::app); // Arquivo de saída como escrita

                        // Verificando se o arquivo de saida está aberto
                        if (saida.is_open()){

                            unsigned *v = gerarConjuntoChaves(conjunto, n);

                            // ! serão 5 execuções para cada conjunto, sementes diferentes      
                            for (unsigned i = 0; i < 5; i++){

                                // Imprimindo a execução atual do Fluxo
                                cout << "Execução: " << i + 1 << endl;

                                if(n != 1000)
                                    continue;

                                // Executando para as versoes, o conjunto
                                fluxoCenario4(v, n, saida);

                            }

                            // Desalocando as chaves geradas
                                free(v);

                        }
                        else
                            cout << "Não foi possível abrir o arquivo de saída" << endl;

                        // Salvando e fechando os arquivos usados
                        saida.close();

                        break;
                    }

                    default:
                        break;
                }

                unsigned clear = system("clear");

                free(conjunto);
                
            }

        }
        else
            cout << "Não foi possível abrir o arquivo de dados" << endl;
    }
    else
        cout << "Não foi possível abrir o arquivo de entrada" << endl;

    entrada.close();
    dataset.close();

}
