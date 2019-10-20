#include <iostream>
#include <fstream>
#include "review.h"
#include "tratamento.h"
#include "execucao.h"

using namespace std;

void executar(){

    fstream entrada, dataset, saida;

    entrada.open("../database/entrada24.txt"); // Arquivo de entrada
    dataset.open("../database/processadosFase1.txt", ios::in); // Arquivo de dados como leitura

    // Variaveis para leitura do arquivo de entrada
    unsigned qtdConjuntos, n;

    // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
    if(entrada.is_open()){
        if(dataset.is_open()){

            // Lendo quantos conjuntos teremos
            entrada >> qtdConjuntos;

            // Lendo os N
            while(entrada >> n){

                //Limpando o arquivo
                saida.open("../saidaFase3.csv", ios::out);
                saida.close();

                //Abrindo arquivo de saida do cenário 
                saida.open("../saidaFase3.csv", ios::out | ios::app); // Arquivo de saída como escrita

                // Verificando se o arquivo de saida está aberto
                if(saida.is_open()){

                    // ! serão 5 execuções para cada conjunto     
                    for (int i = 0; i < 5; i++){

                        // Colocando dados no conjunto
                        Review* conjunto = conjunto->leituraDados(dataset, n);

                        // Imprimindo o valor de N
                        cout << "N: " << n << endl;
                        // Imprimindo a execução atual do Fluxo
                        cout << "Execução: " << i + 1 << endl;

                        embaralharEstruturas(conjunto, n);
                        
                        // Executando para as versoes, o conjunto
                        fluxo(conjunto, n, saida); 

                        //Limpa a tela
                        unsigned clear = system("clear");

                    }
                
                }
                else
                    cout << "Não foi possível abrir o arquivo de saída" << endl;                    

                // Salvando e fechando os arquivos usados
                //saida.close();                    
                
            }

        }
        else
            cout << "Não foi possível abrir o arquivo de dados" << endl;
    }
    else
        cout << "Não foi possível abrir o arquivo de entrada" << endl;

    //entrada.close();
    //dataset.close();

}

void fluxo(Review* conjunto, unsigned n, fstream &saida){

    // Vetor de IDs
    unsigned* ids = gerarVetorIds(conjunto, n);

    //Loop para rodar para os dois tipos de estruturas em única execução
    for (int versao = 0; versao < 3; versao++){

        // Métricas de desempenho
        unsigned long long numComparacoes = 0, numCopias = 0;

        switch(versao){

            case 0:{ // * Árvore Rubro Negra

                // TODO: Criar árvore aqui

                for(int estado = 0; estado < 2; estado++){

                    if(estado){ // Estado de Busca

                        cout << "Busca por X na Arvore Rubro Negra" << endl;

                        // TODO: Definir X
                        // unsigned x = ids[n/3];

                        // Ponto de inicio de contagem para tempo de execução do algoritmo
                        auto inicio = chrono::high_resolution_clock::now();
                        
                        // * Chamada dos algoritmos
                        // TODO: Chamar método de Busca da árvore para o X
                        // TODO: Pegar as métricas de comparação e acessos

                        // Ponto de parada de contagem para o tempo de execução do algoritmo
                        auto parada = chrono::high_resolution_clock::now();
                
                        //Tempo de processamento do algoritmo
                        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();
                    
                        // Imprimindo resultados no arquivo de saída
                        imprimirSaida(saida, versao, estado, n, numComparacoes, numCopias, tempoProcessamento);

                    }
                    else{
                        cout << "Inserção na Arvore Rubro Negra" << endl;

                        // Ponto de inicio de contagem para tempo de execução do algoritmo
                        auto inicio = chrono::high_resolution_clock::now();
                        
                        // * Chamada dos algoritmos
                        // TODO: Colocar o laço para inserção na árvore aqui
                        // TODO: Pegar as métricas de comparação e acessos

                        // Ponto de parada de contagem para o tempo de execução do algoritmo
                        auto parada = chrono::high_resolution_clock::now();
                
                        //Tempo de processamento do algoritmo
                        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

                        // Imprimindo resultados no arquivo de saída
                        imprimirSaida(saida, versao, estado, n, numComparacoes, numCopias, tempoProcessamento);

                    }

                }

                break;

            }

            case 1:{ // * Árvore B d = 2

                // TODO: Criar árvore aqui

                for(int estado = 0; estado < 2; estado++){

                    if(estado){ // Estado de Busca

                        cout << "Busca por X na Arvore Rubro Negra" << endl;

                        // TODO: Definir X
                        // unsigned x = ids[n/3];

                        // Ponto de inicio de contagem para tempo de execução do algoritmo
                        auto inicio = chrono::high_resolution_clock::now();
                        
                        // * Chamada dos algoritmos
                        // TODO: Chamar método de Busca da árvore para o X
                        // TODO: Pegar as métricas de comparação e acessos

                        // Ponto de parada de contagem para o tempo de execução do algoritmo
                        auto parada = chrono::high_resolution_clock::now();
                
                        //Tempo de processamento do algoritmo
                        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();
                    
                        // Imprimindo resultados no arquivo de saída
                        imprimirSaida(saida, versao, estado, n, numComparacoes, numCopias, tempoProcessamento);

                    }

                    else{
                        cout << "Inserção na Arvore Rubro Negra" << endl;

                        // Ponto de inicio de contagem para tempo de execução do algoritmo
                        auto inicio = chrono::high_resolution_clock::now();
                        
                        // * Chamada dos algoritmos
                        // TODO: Colocar o laço para inserção na árvore aqui
                        // TODO: Pegar as métricas de comparação e acessos

                        // Ponto de parada de contagem para o tempo de execução do algoritmo
                        auto parada = chrono::high_resolution_clock::now();
                
                        //Tempo de processamento do algoritmo
                        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

                        // Imprimindo resultados no arquivo de saída
                        imprimirSaida(saida, versao, estado, n, numComparacoes, numCopias, tempoProcessamento);
                    
                    }

                }

                break;
            
            }
            
            case 2:{ // * Árvore B d = 20

                // TODO: Criar árvore aqui

                for(int estado = 0; estado < 2; estado++){

                    if(estado){ // Estado de Busca

                        cout << "Busca por X na Arvore Rubro Negra" << endl;

                        // TODO: Definir X
                        // unsigned x = ids[n/3];

                        // Ponto de inicio de contagem para tempo de execução do algoritmo
                        auto inicio = chrono::high_resolution_clock::now();
                        
                        // * Chamada dos algoritmos
                        // TODO: Chamar método de Busca da árvore para o X
                        // TODO: Pegar as métricas de comparação e acessos

                        // Ponto de parada de contagem para o tempo de execução do algoritmo
                        auto parada = chrono::high_resolution_clock::now();
                
                        //Tempo de processamento do algoritmo
                        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();
                    
                        // Imprimindo resultados no arquivo de saída
                        imprimirSaida(saida, versao, estado, n, numComparacoes, numCopias, tempoProcessamento);

                    }

                    else{
                        cout << "Inserção na Arvore Rubro Negra" << endl;

                        // Ponto de inicio de contagem para tempo de execução do algoritmo
                        auto inicio = chrono::high_resolution_clock::now();
                        
                        // * Chamada dos algoritmos
                        // TODO: Colocar o laço para inserção na árvore aqui
                        // TODO: Pegar as métricas de comparação e acessos

                        // Ponto de parada de contagem para o tempo de execução do algoritmo
                        auto parada = chrono::high_resolution_clock::now();
                
                        //Tempo de processamento do algoritmo
                        auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();
                    
                        // Imprimindo resultados no arquivo de saída
                        imprimirSaida(saida, versao, estado, n, numComparacoes, numCopias, tempoProcessamento);

                    }

                }

                break;
            
            }

            default:
                break;

        }

        free(ids);

    }
    
}
