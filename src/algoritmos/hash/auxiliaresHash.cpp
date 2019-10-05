#include "auxiliaresHash.h"
#include<iostream>

unsigned  converterStringUnsigned(string str){

    unsigned valorString = 0;

    for(unsigned  i = 0; i < str.size(); i++)
        valorString += str[i];

    return valorString;

}

unsigned * gerarConjuntoChaves(Review* review, unsigned  n){

    unsigned * chaves = new unsigned (n);

    for(unsigned  i = 0; i < n; i++){
        chaves[i] = review[i].getId() + converterStringUnsigned(review[i].getUser());
        cout << "Chegou aqui " << i << endl;
    }

    return chaves;

}