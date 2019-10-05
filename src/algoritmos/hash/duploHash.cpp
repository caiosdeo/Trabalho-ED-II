#include <iostream>
#include "duploHash.h"

using namespace std;

duploHash::duploHash(unsigned tamanhoTabela){

    this->tabelaHash = new unsigned(tamanhoTabela);
    this->tamanhoTabela = tamanhoTabela;
    this->tamanhoAtual = 0;
    this->numColisoes = 0;
    this->primo = this->getPrimo();

    for(unsigned i = 0; i < tamanhoTabela; i++)
        tabelaHash[i] = -1;

}

duploHash::~duploHash(){
}

bool duploHash::estaCheia(){

    return this->tamanhoAtual == this->tamanhoTabela;

}

unsigned duploHash::hash1(unsigned chave){

    return chave % this->tamanhoTabela;

}

unsigned duploHash::hash2(unsigned chave){

    return this->primo - chave % this->primo;

}

bool duploHash::ePrimo(unsigned num){

    for(unsigned i = 2; i < num/2; i++)
        if(num % i == 0)
            return false;

    return true;

}

// função para inserir a chave na tabela de hash
void duploHash::inserirHash(unsigned chave){ 
   
    if (this->estaCheia()) 
        return; 
     
    unsigned indice = hash1(chave); 

    if(this->tabelaHash[indice] != -1){ 

        this->numColisoes++;
        unsigned indice2 = hash2(chave); 
        unsigned i = 1; 

        while(1){ 

            unsigned novoIndice = (indice + i * indice2) % this->tamanhoTabela; 

            if (tabelaHash[novoIndice] == -1){ 
                tabelaHash[novoIndice] = chave; 
                break; 
            } 

            i++; 

        } 

    } 

    else
        tabelaHash[indice] = chave; 

    this->tamanhoAtual++;

} 

void duploHash::mostrarHash(){ 

        for (unsigned i = 0; i < this->tamanhoTabela; i++){ 

            if (tabelaHash[i] != -1) 
                cout << i << " --> " << tabelaHash[i] << endl; 

            else
                cout << i << endl; 

        } 

}

unsigned duploHash::getPrimo(){

    unsigned t = this->tamanhoTabela-1;

    while(!this->ePrimo(t))
        t--;

    return t;

}

unsigned long duploHash::getNumColisoes(){
    return this->numColisoes;
}