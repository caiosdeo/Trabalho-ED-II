#include <iostream>
#include <list>
#include "hashEncadSeparado.h"

HashEncadSeparado::HashEncadSeparado(unsigned baldes){

    this->balde = baldes;
    this->tabela = new list<unsigned>[this->balde];

}

unsigned HashEncadSeparado::funcaoHash(unsigned chave) { 
    return (chave % this->balde); 
}

void HashEncadSeparado::insereItem(unsigned chave){

    unsigned indice = funcaoHash(chave);
    tabela[indice].push_back(chave);
}

unsigned HashEncadSeparado::contabilizarColisoes(){

    unsigned numColisoes = 0;

    for(unsigned i = 0; i < this->balde; i++)
        numColisoes += this->tabela[i].size() - 1;

    return numColisoes;

}