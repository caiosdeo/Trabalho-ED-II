#include<iostream>
#include<fstream>
#include "hashEncadeadoUsuarios.h"
#include "funcoesAuxiliares.h"

using namespace std;

int main(void){

    fstream dataset;

    unsigned n = 500000;
    dataset.open("../../processadosFase2_1.txt", ios::in);
    char** users = leituraNomeUsuarios(dataset, n);
    unsigned t = maiorValorString(users, n);
    HashEncadUsuarios tUsers = HashEncadUsuarios(t);
    for(int i = 0; i < n; i++)
        tUsers.insereItem(users[i]);
    tUsers.exibirFrequencias(11);

    return 0;

}