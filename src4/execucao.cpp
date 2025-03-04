#include <iostream>
#include <fstream>
#include "tratamento.h"
#include "execucao.h"
#include "funcoesHuffman.h"
#include "lzw.h"

using namespace std;

void executar(){

    fstream entrada, dataset, saida;

    entrada.open("database/entradaFase4.txt"); // Arquivo de entrada

    // Variaveis para leitura do arquivo de entrada
    int qtdConjuntos, n;

    // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
    if(entrada.is_open()){

        // Lendo quantos conjuntos teremos
        entrada >> qtdConjuntos;

        //Limpando o arquivo
        saida.open("../saidaFase4.csv", ios::out);
        saida.close();

        //Abrindo arquivo de saida do cenário 
        saida.open("../saidaFase4.csv", ios::out | ios::app); // Arquivo de saída como escrita

        // Lendo os N
        while(entrada >> n){
            
            // Verificando se o arquivo de saida está aberto
            if(saida.is_open()){

                // ! serão 5 execuções para cada conjunto     
                for (int i = 0; i < 5; i++){

                    dataset.open("database/descricoes.txt", ios::in); // Arquivo de dados como leitura

                    if(dataset.is_open()){

                        // Armazenando N descrições
                        string* conjunto = leituraDescricoes(dataset, n);

                        dataset.close();

                        // Embaralhando as descrições
                        embaralharDescricoes(conjunto, n);

                        // Imprimindo o valor de N
                        cout << "N: " << n << endl;
                        // Imprimindo a execução atual do Fluxo
                        cout << "Execução: " << i + 1 << endl;

                        // Executando para as versoes, o conjunto
                        fluxo(conjunto, n, saida); 

                        //Limpa a tela
                        int clear = system("clear");

                    }
                    else
                        cout << "Não foi possível abrir o arquivo de dados" << endl;

                }
            
            }
            else
                cout << "Não foi possível abrir o arquivo de saída" << endl;                    

            // Salvando e fechando os arquivos usados
            //saida.close();                    
            
        }

    }
    else
        cout << "Não foi possível abrir o arquivo de entrada" << endl;

    //entrada.close();
    //dataset.close();

}

void fluxo(string* conjunto, int n, fstream &saida){

    //Loop para rodar para os dois algoritmos de compressão em única execução
    for (int versao = 0; versao < 2; versao++){

        // Conjunto auxiliar com as N descrições
        string* auxConjunto = conjunto;

        // Métricas de desempenho
        int armazenamento = 0;
        float taxaComp = 0;
        auto tempoProcessamento = 0;

        switch(versao){

            case 0:{ // * Algoritmo de Huffman

                cout << "Comprimindo com Algoritmo de Huffman" << endl;

                for(int i = 0; i < n; i++){

                    // Ponto de inicio de contagem para tempo de execução do algoritmo
                    auto inicio = chrono::high_resolution_clock::now();
                    
                    // * Chamada do algoritmo
                    string comprimida = comprimirHuffman(conjunto[i]);
                
                    // Ponto de parada de contagem para o tempo de execução do algoritmo
                    auto parada = chrono::high_resolution_clock::now();
            
                    //Tempo de processamento do algoritmo
                    tempoProcessamento += chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

                    taxaComp += taxaCompressao(conjunto[i], comprimida);
                    armazenamento += armazenamentoDisco(comprimida);

                }

                // Imprimindo resultados no arquivo de saída
                imprimirSaida(saida, versao, n, taxaComp / n, armazenamento / n, tempoProcessamento / n);

                break;

            }

            case 1:{ // * Algoritmo de LZW

                cout << "Comprimindo com Algoritmo de LZW" << endl;

                for(int i = 0; i < n; i++){

                    // Ponto de inicio de contagem para tempo de execução do algoritmo
                    auto inicio = chrono::high_resolution_clock::now();
                    
                    // * Chamada do algoritmo
                    string comprimida = comprimirLZW(conjunto[i]);

                    // Ponto de parada de contagem para o tempo de execução do algoritmo
                    auto parada = chrono::high_resolution_clock::now();
            
                    //Tempo de processamento do algoritmo
                    tempoProcessamento += chrono::duration_cast<chrono::milliseconds>(parada - inicio).count();

                    taxaComp += taxaCompressao(conjunto[i], comprimida);
                    armazenamento += armazenamentoDisco(comprimida);

                }

                // Imprimindo resultados no arquivo de saída
                imprimirSaida(saida, versao, n, taxaComp / n, armazenamento / n, tempoProcessamento / n);

                break;
            
            }

            default:
                break;

        }

    }
    
}
