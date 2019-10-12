#include "hashSondagemLinear.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

HashSondLin::HashSondLin(unsigned capacidade)
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
unsigned HashSondLin::hashCode(unsigned chave) 
{ 
    return chave % capacidade; 
} 


void HashSondLin::insereNo(unsigned chave, unsigned valor) 
{ 
    if(estaCheia()){
        return;
    }
    NoHash* temp = new NoHash(chave, valor); 
    // Apply hash function to find index for given chave 
    unsigned hashIndex = hashCode(chave); 
    //find next free space  
    while(tabela[hashIndex] != NULL && tabela[hashIndex]->getChave() != chave 
            && tabela[hashIndex]->getChave() != -1) 
    { 
        this->numColisoes++;
        hashIndex++; 
        hashIndex %= capacidade; 
    } 
          
    //if new node to be inserted increase the current tamanho 
    if(tabela[hashIndex] == NULL || tabela[hashIndex]->getChave() == -1) 
        tamanho++; 
    tabela[hashIndex] = temp; 
} 

//Function to search the valor for a given chave 
unsigned HashSondLin::get(unsigned chave) 
{ 
    //finding the node with given chave    
    for(unsigned i = 0; i < capacidade; i++){
        unsigned index = hashCode(chave);
        if(tabela[index]->getChave() == chave) 
            return tabela[index]->getValor(); 
    }
    
    //If not found return null 
    return -1; 
    } 

//Return current tamanho  
unsigned HashSondLin::getTamanho() 
{ 
    return tamanho; 
} 
bool HashSondLin::estaCheia()
{
    return tamanho == capacidade;
} 
bool HashSondLin::estaVazia() 
{ 
    return tamanho == 0; 
} 

unsigned HashSondLin::getNumColisoes(){

    return this->numColisoes;

}