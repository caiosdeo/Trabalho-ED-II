#include "auxiliaresHash.h"

int converterStringInteiro(string str){

    int valorString = 0;

    for(int i = 0; i < str.size(); i++)
        valorString += str[i];

    return valorString;

}

int* gerarConjuntoChaves(Review* review, int n){

    int* chaves = new int(n);

    for(int i =0; i < n; i++)
        chaves[i] = review[i].getId() + converterStringInteiro(review[i].getUser());

    return chaves;

}