#include <iostream>
#include "HashInfoJogo.h"
#include "funcoesAuxiliares.h"

using namespace std;

HashInfoJogo::HashInfoJogo(unsigned tamanhoTabela){

    this->tabelaHash = new InfoJogo[tamanhoTabela];
    this->tamanhoTabela = tamanhoTabela;
    this->tamanhoAtual = 0;
    this->numColisoes = 0;

    for(int i = 0; i < tamanhoTabela; i++)
        tabelaHash[i].setId(-1);

}

bool HashInfoJogo::estaCheia(){

    return this->tamanhoAtual == this->tamanhoTabela;

}

unsigned HashInfoJogo::hash1(unsigned chave){

    return chave % this->tamanhoTabela;

}

unsigned HashInfoJogo::hash2(unsigned chave, unsigned resto){

    unsigned id = resto - chave % (resto+1);
    return id >= 0 ? id : -id;

}

// função para inserir a chave na tabela de hash
void HashInfoJogo::inserirHash(InfoJogo info){ 
   
    if (this->estaCheia()) 
        return; 

    // Somatório dos campos para a chave
    unsigned chave = info.getIdJogo();
    chave += info.getId();
    chave += converterStringUnsigned(info.getCategoria());

    unsigned indice = hash1(chave); 

    if(this->tabelaHash[indice].getId() > 0){ 

        this->numColisoes++;
        unsigned indice2 = hash2(chave, indice); 
        unsigned i = 0; 

        while(true){ 

            unsigned novoIndice = (indice2 + i) % this->tamanhoTabela;

            if (tabelaHash[novoIndice].getId() < 0){ 
                tabelaHash[novoIndice] = info; 
                break; 
            } 

            i++; 

        } 

    } 

    else
        tabelaHash[indice] = info; 

    this->tamanhoAtual++;

} 

unsigned HashInfoJogo::getNumColisoes(){
    return this->numColisoes;
}

InfoJogo* HashInfoJogo::getTabelaHash(){
    return this->tabelaHash;
}