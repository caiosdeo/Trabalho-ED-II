#include <iostream>
#include <list>
#include "hashEncadSeparado.h"

HashEncadSeparado::HashEncadSeparado(unsigned baldes){

    this->balde = baldes;
    this->tabela = new list<unsigned>[this->balde];

}

HashEncadSeparado::~HashEncadSeparado(){

    //delete this->tabela;
}

unsigned HashEncadSeparado::funcaoHash(unsigned chave) { 
    return (chave % this->balde); 
}

void HashEncadSeparado::insereItem(unsigned chave){

    unsigned indice = funcaoHash(chave);
    tabela[indice].push_back(chave);
}

void HashEncadSeparado::removeItem(unsigned chave){

    unsigned indice = funcaoHash(chave);

    list<unsigned>::iterator i;
    for(i = tabela[indice].begin(); i != tabela[indice].end(); i++)
        if(*i == chave)
            break;

    if(i != tabela[indice].end())
        tabela[indice].erase(i);

}

void HashEncadSeparado::imprimirHash(){
    
    for (unsigned i = 0; i < balde; i++) { 
        cout << i; 
        for (auto x : tabela[i]) 
            cout << " --> " << x; 
        cout << endl; 
  } 

}

unsigned long HashEncadSeparado::contabilizarColisoes(){

    unsigned long numColisoes = 0;

    for(unsigned i = 0; i < this->balde; i++)
        numColisoes += this->tabela[i].size();

    return numColisoes;

}