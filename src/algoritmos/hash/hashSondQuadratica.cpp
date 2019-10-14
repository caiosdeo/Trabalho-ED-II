#include "hashSondQuadratica.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

/**
 * Construtor
 *
 * @author caiosdeo
 * @param capacidade quantidade de chaves que a tabela irá suportar
 */
HashSondQuad::HashSondQuad(unsigned capacidade) 
{ 
    //Capacidade inicial 
    this->capacidade = capacidade; 
    tamanho = 0; 
    tabela = new NoHash*[capacidade]; 
    this->numColisoes = 0;
          
    // Inicializando a todos com NULL 
    for(unsigned i=0 ; i < capacidade ; i++) 
        tabela[i] = NULL; 
      
    // Nó aux valor e chave -1 
    NoHash* aux = new NoHash(-1, -1); 
} 

/**
 * Função para retornar o indice da chave na tabela hash
 *
 * @author caiosdeo
 * @param chave chave para inserção na tabela
 * @return indice posição na tabela hash
 */
unsigned HashSondQuad::hashCode(unsigned chave) 
{ 
    return chave % capacidade; 
} 

/**
 * Função de inserção de uma chave na tabela hash
 *
 * @author caiosdeo
 * @param chave chave para que deseja inserir na tabela
 * @param valor valor do nó
 */
void HashSondQuad::insereNo(unsigned chave, unsigned valor) 
{ 
    if(estaCheia()){
        return;
    }
    
    NoHash* temp = new NoHash(chave, valor); 

    // Aplicando função hash para retornar indice da chave 
    unsigned hashIndex = hashCode(chave);

    // Procurando o próximo espaço vazio  
    for(unsigned i = 1; tabela[hashIndex] != NULL && tabela[hashIndex]->getChave() != chave && tabela[hashIndex]->getChave() != -1 && i < this->capacidade; i++) 
    { 
        this->numColisoes++;
        hashIndex = (chave + (i*i)) % capacidade; 
    } 
          
    // Se o novo vai ser inserido, aumenta o tamanho
    if(tabela[hashIndex] == NULL || tabela[hashIndex]->getChave() == -1) 
        this->tamanho++; 

    tabela[hashIndex] = temp; 
} 

unsigned HashSondQuad::getTamanho() 
{ 
    return this->tamanho; 
}

/**
 * Função para saber se a tabela está vazia
 *
 * @author prrp
 */
bool HashSondQuad::estaCheia()
{
    return this->tamanho == capacidade;
} 
 
/**
 * Funçao que retorna o número de todas as colisões ocorridas
 *
 * @author eliascassis
 * @return numColisoes numero de colisões ocorridas
 */
unsigned HashSondQuad::getNumColisoes(){

    return this->numColisoes;

}