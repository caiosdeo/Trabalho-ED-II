#include <iostream>
#include <list>
#include "hashEncadSeparado.h"

HashEncadSeparado::HashEncadSeparado(int baldes){

    this->balde = baldes;
    this->tabela = new list<int>[this->balde];
}

HashEncadSeparado::~HashEncadSeparado(){

    delete this->tabela;
}

int HashEncadSeparado::funcaoHash(int chave) { 
    return (chave % this->balde); 
}

void HashEncadSeparado::insereItem(int chave){

    int indice = funcaoHash(chave);
    tabela[indice].push_back(chave);
}

void HashEncadSeparado::removeItem(int chave){

    int indice = funcaoHash(chave);

    list<int>::iterator i;
    for(i = tabela[indice].begin(); i != tabela[indice].end(); i++)
        if(*i == chave)
            break;

    if(i != tabela[indice].end())
        tabela[indice].erase(i);

}

void HashEncadSeparado::imprimirHash(){
    
    for (int i = 0; i < balde; i++) { 
        cout << i; 
        for (auto x : tabela[i]) 
            cout << " --> " << x; 
        cout << endl; 
  } 

}
