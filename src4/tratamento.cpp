#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"
#include "noHuffman.h"
#include <tuple>
#include <cmath>

// Imprime saída 
void imprimirSaida(fstream &saida, unsigned estrutura, unsigned n, float taxaCompressao, float armazenamento, float tempoProcessamento){

    saida << estrutura << "," << n << "," << taxaCompressao << "," << armazenamento << "," << tempoProcessamento << endl;

}

void embaralharDescricoes(string *d, unsigned n){

    for(unsigned i = 0; i < n/2; i+=2)
        swapDescricoes(d, i, (n-1)-i);

    for(unsigned i = 0; i < n - 1; i+=2)
        swapDescricoes(d, i, i+1);

}

void swapDescricoes(string* a, int i, int j){

    string aux;

    aux = a[i];
    a[i] = a[j];
    a[j] = aux;

}

// Converte uma string em um inteiro 
int converterStringInteiro(string str){

    int valorString = 0;
    // Somatório do valor ascii dos caracteres da string
    for(int  i = 0; str[i] != '\0'; i++)
        valorString += str[i];

    return valorString;

}

string* leituraDescricoes(fstream &dataset, int n){

    // Conjunto de descricoes
    string* d = new string[n];
    
    //Variaveis para ler o documento
    string descricao;

    //Variavel auxiliar para controlar o tamanho do conjunto
    int i = 0;

    // Alterando a semente com o tempo
    srand(time(0));

    // Eliminando a primeira linha do arquivo
    getline(dataset,descricao);

    // Loop para definir o conjunto reiniciando o arquivo
    while(i < n){

        // Extração de dados até o tamanho do conjunto e o fim do arquivo
        while(dataset.good() && i < n){

            if(i == n) // Se o tamanho do conjunto é igual ao n
                continue; // Sai do laço 
              
            // Pegando as informações de cada descricao
            getline(dataset,descricao);

            // Selecionando descricoes a partir do resto de uma divisão por 3
            if(rand() % 3 == 0 && descricao[0] != 0 && descricao[0] != (char)' '){ 
                
                //Atribuindo uma descricao
                d[i] = descricao;

                i++;

            }

        }

        // Voltando para o inicio do arquivo de dados
        dataset.clear();
        dataset.seekg(0, ios::beg);
        
    }

    // Retornando o conjunto de descricoes
    return d;

}

float taxaCompressao(string m, string cM){

    return cM.size() / m.size();

}

int armazenamentoDisco(string m){

    return m.size();

}
