#include "hashSondQuadratica.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

HashSondQuad::HashSondQuad(unsigned capacidade) 
{ 
    //Initial capacidade of hash array 
    this->capacidade = capacidade; 
    tamanho = 0; 
    tabela = new NoHash*[capacidade]; 
    this->numColisoes = 0;
          
    //Initialise all elements of array as NULL 
    for(unsigned i=0 ; i < capacidade ; i++) 
        tabela[i] = NULL; 
      
    //aux node with valor and chave -1 
    NoHash* aux = new NoHash(-1, -1); 
} 

// This implements hash function to find index 
// for a chave 
unsigned HashSondQuad::hashCode(unsigned chave) 
{ 
    return chave % capacidade; 
} 


void HashSondQuad::insereNo(unsigned chave, unsigned valor) 
{ 
    if(estaCheia()){
        return;
    }
    
    NoHash* temp = new NoHash(chave, valor); 
    // Apply hash function to find index for given chave 
    unsigned hashIndex = hashCode(chave); 
    //find next free space  
    for(unsigned i = 1; tabela[hashIndex] != NULL && tabela[hashIndex]->getChave() != chave 
            && tabela[hashIndex]->getChave() != -1 && i < this->capacidade; i++) 
    { 
        this->numColisoes++;
        hashIndex = (chave + (i*i)) % capacidade; 
    } 
          
    //if new node to be inserted increase the current tamanho 
    if(tabela[hashIndex] == NULL || tabela[hashIndex]->getChave() == -1) 
        this->tamanho++; 

    tabela[hashIndex] = temp; 
} 

unsigned HashSondQuad::getTamanho() 
{ 
    return this->tamanho; 
}
bool HashSondQuad::estaCheia()
{
    return this->tamanho == capacidade;
} 
bool HashSondQuad::estaVazia() 
{ 
    return this->tamanho == 0; 
} 

unsigned HashSondQuad::getNumColisoes(){

    return this->numColisoes;

}