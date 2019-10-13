#include "InfoJogo.h"
#include "HashInfoJogo.h"
#include "funcoesAuxiliares.h"
#include <iostream>
#include <fstream>

/**
 * Atribuição de dados a cada conjunto, retornando-o em um vetor.
 *
 * @author caiosdeo
 * @param dataset Arquivo com os dados
 * @param n Tamanho do conjunto
 * @return r Vetor com dados
 */
HashInfoJogo* InfoJogo::leituraDados(fstream &dataset, int n){

    // Conjunto de Avaliacoes
    InfoJogo info;
    HashInfoJogo* tabelaAvaliacao;

    //Variaveis para ler o documento
    string id, categoria, idJogo;
    unsigned tString;

    //Variavel auxiliar para controlar o tamanho do conjunto
    int i = 0;

    // Alterando a semente com o tempo
    srand(time(0));

    // Eliminando a primeira linha do arquivo
    getline(dataset, id, ',');
    getline(dataset, categoria, ',');
    getline(dataset, idJogo, '\n');

    // Extração de dados até o tamanho do conjunto e o fim do arquivo
    while(dataset.good() && i < n){

        // Pegando as informações de cada registro
        getline(dataset, categoria, ',');
        getline(dataset, idJogo, ',');
        getline(dataset, id, '\n');

        if(rand() % 3 == 0){ // Selecionando registros a partir do resto de uma divisão por 3

            info.setCategoria(categoria);
            info.setId(id);
            info.setIdJogo(idJogo);

            tabelaAvaliacao->inserirHash(info);

            i++;

        }
        
    }

    // Retornando o conjunto de avaliacoes
    return tabelaAvaliacao;

}

unsigned InfoJogo::getId(){

    return this->id;

}

char* InfoJogo::getUser(){

    return this->categoria;

}

unsigned InfoJogo::getIdJogo(){

    return this->idJogo;

}