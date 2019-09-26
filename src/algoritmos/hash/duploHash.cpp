#include <iostream>
#include "duploHash.h"

using namespace std;

duploHash::duploHash(int tamanhoTabela){

    this->tabelaHash = new int(tamanhoTabela);
    this->tamanhoTabela = tamanhoTabela;
    this->tamanhoAtual = 0;
    this->numColisoes = 0;
    this->primo = this->getPrimo();

    for(int i = 0; i < tamanhoTabela; i++)
        tabelaHash[i] = -1;

}

duploHash::~duploHash(){
}

bool duploHash::estaCheia(){

    return this->tamanhoAtual == this->tamanhoTabela;

}

int duploHash::hash1(int chave){

    return chave % this->tamanhoTabela;

}

int duploHash::hash2(int chave){

    return this->primo - chave % this->primo;

}

bool duploHash::ePrimo(int num){

    for(int i = 2; i < num/2; i++)
        if(num % i == 0)
            return false;

    return true;

}

// função para inserir a chave na tabela de hash
void duploHash::inserirHash(int chave){ 
   
    if (this->estaCheia()) 
        return; 
     
    int indice = hash1(chave); 

    if(this->tabelaHash[indice] != -1){ 

        this->numColisoes++;
        int indice2 = hash2(chave); 
        int i = 1; 

        while(1){ 

            int novoIndice = (indice + i * indice2) % this->tamanhoTabela; 

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

        for (int i = 0; i < this->tamanhoTabela; i++){ 

            if (tabelaHash[i] != -1) 
                cout << i << " --> " << tabelaHash[i] << endl; 

            else
                cout << i << endl; 

        } 

}

int duploHash::getPrimo(){

    int t = this->tamanhoTabela-1;

    while(!this->ePrimo(t))
        t--;

    return t;

}

int duploHash::getNumColisoes(){
    return this->numColisoes;
}