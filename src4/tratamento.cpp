#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"

// Imprime saída 
void imprimirSaida(fstream &saida, unsigned estrutura, unsigned n, float numComparacoes, float numCopias, float tempoProcessamento){

    saida << estrutura << "," << n << "," << numComparacoes << "," << numCopias << "," << tempoProcessamento << endl;

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
    dataset >> descricao;

    // Extração de dados até o tamanho do conjunto e o fim do arquivo
    while(dataset.good() && i < n){

        // Pegando as informações de cada descricao
        dataset >> descricao;

        if(rand() % 3 == 0 && descricao != "" && descricao != " "){ // Selecionando descricoes a partir do resto de uma divisão por 3

            //Atribuindo uma descricao
            d[i] = descricao;

            i++;

        }
        
    }

    // Retornando o conjunto de descricoes
    return d;

}

void salvar(string* conjunto, unsigned n){

    // Arquivo de Descricao para salvar em disco
    fstream arqDescricao;

    // Caminho do arquivo
    string caminhoArq;

    // Definindo o caminho do arquivo
    if(n == 1000)
        caminhoArq = "../../d1000.txt";
    
    else if(n == 5000)
        caminhoArq = "../../d5000.txt";
    
    else if(n == 10000)
        caminhoArq = "../../d10000.txt";
    
    else if(n == 50000)
        caminhoArq = "../../d50000.txt";
    
    else if(n == 100000)
        caminhoArq = "../../d100000.txt";
    
    else
        caminhoArq = "../../d500000.txt";            

    arqDescricao.open(caminhoArq, ios::out);

    if(arqDescricao.is_open()){
    
        // Preenchendo o arquivo
        for(int i = 0; i < n; i++)
            arqDescricao << conjunto[i] << endl;

        arqDescricao.close();
    
    }
    else{
        cerr << "Não foi possível salvar o conjunto" << endl;
        exit(1);
    }

}

void salvarComprimido(string* conjunto, unsigned n){

    // Arquivo de Descricao para salvar em disco
    fstream arqDescricao;

    // Caminho do arquivo
    string caminhoArq;

    // Definindo o caminho do arquivo
    if(n == 1000)
        caminhoArq = "../../d1000comp.txt";
    
    else if(n == 5000)
        caminhoArq = "../../d5000comp.txt";
    
    else if(n == 10000)
        caminhoArq = "../../d10000comp.txt";
    
    else if(n == 50000)
        caminhoArq = "../../d50000comp.txt";
    
    else if(n == 100000)
        caminhoArq = "../../d100000comp.txt";
    
    else
        caminhoArq = "../../d500000comp.txt";            

    arqDescricao.open(caminhoArq, ios::out);

    if(arqDescricao.is_open()){
    
        // Preenchendo o arquivo
        for(int i = 0; i < n; i++)
            arqDescricao << conjunto[i] << endl;

        arqDescricao.close();
    
    }
    else{
        cerr << "Não foi possível salvar o conjunto" << endl;
        exit(1);
    }
}