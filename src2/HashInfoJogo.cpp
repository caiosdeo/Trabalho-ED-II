#include <iostream>
#include "HashInfoJogo.h"
#include "funcoesAuxiliares.h"

using namespace std;

// Construtor da HashInfoJogo
HashInfoJogo::HashInfoJogo(unsigned tamanhoTabela){

    // Inicialização dos atributos
    this->tabelaHash = new InfoJogo[tamanhoTabela];
    this->tamanhoTabela = tamanhoTabela;
    this->tamanhoAtual = 0;
    this->numColisoes = 0;

    // Setando -1 para as posições vazias da tabela hash
    for(int i = 0; i < tamanhoTabela; i++)
        tabelaHash[i].setId(-1);

}

// Retorna true se a tabela hash estiver cheia
bool HashInfoJogo::estaCheia(){

    return this->tamanhoAtual == this->tamanhoTabela;

}

// Função de hash 1
unsigned HashInfoJogo::hash1(unsigned chave){

    return chave % this->tamanhoTabela;

}

// Função de hash 2
unsigned HashInfoJogo::hash2(unsigned chave, unsigned resto){

    unsigned id = resto - chave % (resto+1);
    return id >= 0 ? id : -id;

}

// função para inserir a chave na tabela de hash
void HashInfoJogo::inserirHash(InfoJogo info){ 
   
    // Confere se a tabela está cheia
    if (this->estaCheia()) 
        return; 

    // Somatório dos campos para a chave
    unsigned chave = info.getIdJogo();
    chave += info.getId();
    chave += converterStringInteiro(info.getCategoria());

    // Cálculo de índice utilizando hash 1
    unsigned indice = hash1(chave); 

    // Verifica colisão
    if(this->tabelaHash[indice].getId() > 0){ 

        // Incrementa o número de colisões
        this->numColisoes++;
        // Cálculo de índice utilizando hash 2
        unsigned indice2 = hash2(chave, indice); 
        unsigned i = 0; 

        while(true){ 

            unsigned novoIndice = (indice2 + i) % this->tamanhoTabela;

            // Confere posição vazia
            if (tabelaHash[novoIndice].getId() < 0){ 
                tabelaHash[novoIndice] = info;  // Insere chave
                break; 
            } 

            // Incrementa colisões
            this->numColisoes++;
            i++; 

        } 

    } 

    else
        tabelaHash[indice] = info; // Insere chave

    this->tamanhoAtual++; // Incrementa tamanho da corrente da tabela

} 

// Gets e sets

unsigned HashInfoJogo::getNumColisoes(){
    return this->numColisoes;
}

InfoJogo* HashInfoJogo::getTabelaHash(){
    return this->tabelaHash;
}