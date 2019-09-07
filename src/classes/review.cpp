#include <iostream>
#include <fstream>
#include "review.h"

/**
 * Atribuição de dados a cada conjunto, retornando-o em um vetor.
 *
 * @author caiosdeo
 * @param dataset Arquivo com os dados
 * @param n Tamanho do conjunto
 * @return r Vetor com dados
 */
Review* Review::leituraDados(fstream &dataset, int n){

    // Conjunto de Reviews
    Review* r = new Review[n];
    
    //Variaveis para ler o documento
    string id, user, rating;

    //Variavel auxiliar para controlar o tamanho do conjunto
    int i = 0;

    // Alterando a semente com o tempo
    srand(time(NULL));

    // Eliminando a primeira linha do arquivo
    getline(dataset, user, ',');
    getline(dataset, rating, ',');
    getline(dataset, id, '\n');

    // Extração de dados até o tamanho do conjunto e o fim do arquivo
    while(dataset.good() && i < n){

        // Pegando as informações de cada registro
        getline(dataset, user, ',');
        getline(dataset, rating, ',');
        getline(dataset, id, '\n');

        if(rand() % 11 == 0){ // Selecionando registros a partir do resto de uma divisão por 11

            r[i].user = user; //Atribuindo um nome de usuário 
            r[i].rating = stof(rating); // Atribuindo o rating do review
            r[i].id = stoi(id); // Atribuindo o id do jogo do review

            i++;

        }
        
    }

    // Retornando o conjunto de reviews
    return r;

}

int Review::getId(){

    return this->getId();

}