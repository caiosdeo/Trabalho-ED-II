#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"
#include "../classes/review.h"
#include "../algoritmos/hash.h"
#include "cenario4.h"

using namespace std;

void fluxoCenario4(Review* conjunto, int n, fstream &saida){

    // Vetor de IDs
    int* chaves;

    // Declaracao de Hashs

    // Visualizando o N
    cout << "N: " << n << endl;

    //Loop para rodar para os dois tipos de estruturas em única execução
    for (int versao = 0; versao < 5; versao++){

        chaves = gerarConjuntoChaves(conjunto, n); // Gerando chaves a serem usadas nas hash

        // Métricas de desempenho
        unsigned long long int numColisoes = 0;

        switch(versao){

            case 0:{ // Hash sondagem linear

                cout << "Executando hash sondagem linear" << endl;
                
                // * Chamada dos algoritmos
                HashSondLin hashLin = HashSondLin(n);

                for(int j = 0; j < n; j++)
                    hashLin.insereNo(chaves[j], chaves[j]);

                // Métrica de desempenho
                numColisoes = hashLin.getNumColisoes();

                break;
            }
            
            case 1:{ // Hash sondagem quadratica

                cout << "Executando hash sondagem quadratica" << endl;
                
                // * Chamada dos algoritmos
                HashSondQuad hashQuad = HashSondQuad(n);

                for(int j = 0; j < n; j++)
                    hashQuad.insereNo(chaves[j], chaves[j]);

                // Métrica de desempenho
                numColisoes = hashQuad.getNumColisoes();

                break;
            }

            case 2:{ // Duplo Hash

                cout << "Executando duplo hash" << endl;
                
                // * Chamada dos algoritmos
                duploHash dHash = duploHash(n);

                for(int j = 0; j < n; j++)
                    dHash.inserirHash(chaves[j]);

                // Métrica de desempenho
                numColisoes = dHash.getNumColisoes();
                
                break;
            }

            case 3:{ // Hash Encadeamento Separado

                cout << "Executando hash encadeamento separado" << endl;

                // * Chamada dos algoritmos
                HashEncadSeparado hashEncadSep = HashEncadSeparado(n/10);

                for(int j = 0; j < n; j++)
                    hashEncadSep.insereItem(chaves[j]);

                // Métrica de desempenho
                numColisoes = hashEncadSep.contabilizarColisoes();

                break;
            }
            
            case 4:{ // Hash Encadeamento Coalescido

                cout << "Executando hash encadeamento coalescido" << endl;

                // * Chamada dos algoritmos
                hashEncadCoal hashEncadCoa = hashEncadCoal(n);

                for(int j = 0; j < n; j++)
                    hashEncadCoa.insereItem(chaves[j], &numColisoes);                

                break;
            }
            
            default:
                break;
        }

        // Imprimindo resultados no arquivo de saída
        imprimirSaidaHash(saida, versao, n, numColisoes);
    
    }
    
}