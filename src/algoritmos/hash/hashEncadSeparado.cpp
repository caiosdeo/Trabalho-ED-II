#include <iostream>
#include <list>
#include "hashEncadSeparado.h"

/**
 * Construtor da Hash
 *
 * @author caiosdeo
 * @param baldes quantidade de baldes da tabela
 */
HashEncadSeparado::HashEncadSeparado(unsigned baldes){

    this->balde = baldes;
    this->tabela = new list<unsigned>[this->balde];

}

/**
 * Função para retornar o indice da chave na tabela hash
 *
 * @author caiosdeo
 * @param chave chave para inserção na tabela
 * @return indice posição na tabela hash
 */
unsigned HashEncadSeparado::funcaoHash(unsigned chave) { 
    return (chave % this->balde); 
}

/**
 * Função de inserção de uma chave na tabela hash
 *
 * @author caiosdeo
 * @param chave chave para que deseja inserir na tabela
 */
void HashEncadSeparado::insereItem(unsigned chave){

    unsigned indice = funcaoHash(chave);
    tabela[indice].push_back(chave);
}

/**
 * Funçao que retorna o número de todas as colisões ocorridas
 *
 * @author eliascassis
 * @return numColisoes numero de colisões ocorridas
 */
unsigned HashEncadSeparado::contabilizarColisoes(){

    unsigned numColisoes = 0;

    for(unsigned i = 0; i < this->balde; i++)
        numColisoes += this->tabela[i].size() - 1;

    return numColisoes;

}