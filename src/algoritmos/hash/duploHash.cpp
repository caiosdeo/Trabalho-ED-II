#include <iostream>
#include "duploHash.h"

using namespace std;

/**
 * Construtor
 *
 * @author eliascasssis
 * @param tamanhoTabela quantidade de chaves que a tabela irá suportar
 */
duploHash::duploHash(unsigned tamanhoTabela){

    this->tabelaHash = (unsigned*)calloc(tamanhoTabela, sizeof(unsigned));;
    this->tamanhoTabela = tamanhoTabela;
    this->tamanhoAtual = 0;
    this->numColisoes = 0;

    // -1 para representar posição vazia
    for(unsigned i = 0; i < tamanhoTabela; i++)
        tabelaHash[i] = -1;

}

/**
 * Destrutor
 *
 * @author eliascasssis
 */
duploHash::~duploHash(){
    free(this->tabelaHash);
}

/**
 * Função para verificar se a tabela está cheia
 *
 * @author eliascasssis
 */
bool duploHash::estaCheia(){

    return this->tamanhoAtual == this->tamanhoTabela;

}

/**
 * Função para retornar o indice da chave na tabela hash
 *
 * @author eliascassis
 * @param chave chave para inserção na tabela
 * @return indice posição na tabela hash
 */
unsigned duploHash::hash1(unsigned chave){

    return chave % this->tamanhoTabela;

}

/**
 * Função para retornar o salto caso ocorra colisão
 *
 * @author eliascassis
 * @param chave chave para inserção na tabela
 * @return indice posição na tabela hash
 */
unsigned duploHash::hash2(unsigned chave, unsigned resto){

    unsigned id = resto - chave % (resto+1);
    return id >= 0 ? id : -id;

}

/**
 * Função de inserção de uma chave na tabela hash
 *
 * @author caiosdeo
 * @param chave chave para que deseja inserir na tabela
 */
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

            this->numColisoes++;
            i++; 

        } 

    } 

    else
        tabelaHash[indice] = chave; 

    this->tamanhoAtual++;

} 

/**
 * Funçao que retorna o número de todas as colisões ocorridas
 *
 * @author eliascassis
 * @return numColisoes numero de colisões ocorridas
 */
unsigned duploHash::getNumColisoes(){
    return this->numColisoes;
}