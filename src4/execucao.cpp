#include <iostream>
#include <fstream>
#include "tratamento.h"
#include "execucao.h"

using namespace std;

void executar(){

    fstream entrada, dataset, saida;

    entrada.open("../database/entrada24.txt"); // Arquivo de entrada
    dataset.open("../database/descricoes.csv", ios::in); // Arquivo de dados como leitura

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
                saida.open("../../saidaFase4.csv", ios::out);
                saida.close();

                //Abrindo arquivo de saida do cenário 
                saida.open("../../saidaFase4.csv", ios::out | ios::app); // Arquivo de saída como escrita

                // Verificando se o arquivo de saida está aberto
                if(saida.is_open()){

                    // ! serão 5 execuções para cada conjunto     
                    for (int i = 0; i < 5; i++){

                        // Colocando dados no conjunto
                        string* conjunto = leituraDescricoes(dataset, n);

                        // Embaralhando as descrições
                        embaralharDescricoes(conjunto, n);

                        // Imprimindo o valor de N
                        cout << "N: " << n << endl;
                        // Imprimindo a execução atual do Fluxo
                        cout << "Execução: " << i + 1 << endl;

                        // Salvando o conjnto
                        salvar(conjunto, n);

                        // TODO: chamar fluxo de compressão aqui
                        // Executando para as versoes, o conjunto
                        fluxo(conjunto, n, saida); 

                        // Salvando o conjunto comprimido
                        salvarComprimido(conjunto, n);

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

void fluxo(string* conjunto, unsigned n, fstream &saida){

    //Loop para rodar para os dois algoritmos de compressão em única execução
    for (int versao = 0; versao < 2; versao++){

        // Métricas de desempenho
        unsigned long long numComparacoes = 0, numCopias = 0;

        switch(versao){

            case 0:{ // * Algoritmo de Huffman

                cout << "Comprimindo com Algoritmo de Huffman" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                auto inicio = chrono::high_resolution_clock::now();
                
                // * Chamada do algoritmo
                // TODO: Chamar algoritmo de compressão no conjunto
                // TODO: Pegar as métricas

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                auto parada = chrono::high_resolution_clock::now();
        
                //Tempo de processamento do algoritmo
                auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();
            
                // Imprimindo resultados no arquivo de saída
                imprimirSaida(saida, versao, n, numComparacoes, numCopias, tempoProcessamento);

                break;

            }

            case 1:{ // * Algoritmo de LZW

                cout << "Comprimindo com Algoritmo de LZW" << endl;

                // Ponto de inicio de contagem para tempo de execução do algoritmo
                auto inicio = chrono::high_resolution_clock::now();
                
                // * Chamada do algoritmo
                // TODO: Chamar algoritmo de compressão no conjunto
                // TODO: Pegar as métricas

                // Ponto de parada de contagem para o tempo de execução do algoritmo
                auto parada = chrono::high_resolution_clock::now();
        
                //Tempo de processamento do algoritmo
                auto tempoProcessamento = chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();
            
                // Imprimindo resultados no arquivo de saída
                imprimirSaida(saida, versao, n, numComparacoes, numCopias, tempoProcessamento);

                break;
            
            }

            default:
                break;

        }

    }
    
}
