#include <iostream>
#include "duploHash.h"

using namespace std;

duploHash::duploHash(unsigned tamanhoTabela){

    this->tabelaHash = (unsigned*)calloc(tamanhoTabela, sizeof(unsigned));;
    this->tamanhoTabela = tamanhoTabela;
    this->tamanhoAtual = 0;
    this->numColisoes = 0;

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

unsigned duploHash::hash2(unsigned chave, unsigned resto){

    return resto - chave % resto;

}

// função para inserir a chave na tabela de hash
void duploHash::inserirHash(unsigned chave){ 
   
    if (this->estaCheia()) 
        return; 
     
    unsigned indice = hash1(chave); 

    if(this->tabelaHash[indice] != -1){ 

        this->numColisoes++;
        unsigned indice2 = hash2(chave, indice); 
        unsigned i = 0; 

        while(true){ 

            unsigned novoIndice = (indice2 + i) % this->tamanhoTabela;

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

unsigned long duploHash::getNumColisoes(){
    return this->numColisoes;
}