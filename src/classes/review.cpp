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
    Review* r = (Review*)calloc(n, sizeof(Review));
    
    //Variaveis para ler o documento
    string id, user, rating;
    unsigned tString;

    //Variavel auxiliar para controlar o tamanho do conjunto
    int i = 0;

    // Alterando a semente com o tempo
    srand(time(0));

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

        if(rand() % 3 == 0){ // Selecionando registros a partir do resto de uma divisão por 3

            //Atribuindo um nome de usuário
            tString = user.size();
            r[i].user = (char*)malloc(sizeof(char) * tString);//(char*)calloc(tString, sizeof(char));
            for(int j = 0; j < tString; j++)
                r[i].user[j] = user[j];
            r[i].rating = stof(rating); // Atribuindo o rating do review
            r[i].id = stoul(id); // Atribuindo o id do jogo do review

            i++;

        }
        
    }

    // Retornando o conjunto de reviews
    return r;

}

// Gets e sets
int Review::getId(){

    return this->id;

}

char* Review::getUser(){

    return this->user;

}

float Review::getRating(){

    return this->rating;

}