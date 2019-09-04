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

    Review* r = new Review[n];
    
    int id;
    string user;
    float rating;

    int i = 0;

    srand(time(NULL));

    // Eliminando a primeira linha do arquivo
    dataset >> user >> rating >> id;

    while(dataset >> user >> rating >> id){

        if(rand() % 11 == 0){ // Selecionando registros a partir do resto de uma divisão por 11

            r[i].user = user;
            r[i].rating = rating;
            r[i].id = id;

            i++;

        }
        
    }

    return r;

}