#include "hashSondagemLinear.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

HashSondLin::HashSondLin(int capacidade)
{ 
    //Initial capacidade of hash array 
    this->capacidade = capacidade; 
    tamanho = 0; 
    tabela = new NoHash*[capacidade]; 
    this->numColisoes = 0;
          
    //Initialise all elements of array as NULL 
    for(int i=0 ; i < capacidade ; i++) 
        tabela[i] = NULL; 
      
    //aux node with valor and chave -1 
    NoHash* aux = new NoHash(-1, -1); 
} 

// This implements hash function to find index 
// for a chave 
int HashSondLin::hashCode(int chave) 
{ 
    return chave % capacidade; 
} 


void HashSondLin::insereNo(int chave, int valor) 
{ 
    if(estaCheia()){
        return;
    }
    NoHash* temp = new NoHash(chave, valor); 
    bool houveColisao = false;
    // Apply hash function to find index for given chave 
    int hashIndex = hashCode(chave); 
    //find next free space  
    while(tabela[hashIndex] != NULL && tabela[hashIndex]->getChave() != chave 
            && tabela[hashIndex]->getChave() != -1) 
    { 
        houveColisao = true;
        hashIndex++; 
        hashIndex %= capacidade; 
    } 

    if(houveColisao)
        this->numColisoes++;
          
    //if new node to be inserted increase the current tamanho 
    if(tabela[hashIndex] == NULL || tabela[hashIndex]->getChave() == -1) 
        tamanho++; 
    tabela[hashIndex] = temp; 
} 

//Function to delete a chave valor pair 
int HashSondLin::deleteNo(int chave) 
{ 
    // Apply hash function to find index for given chave 
    int hashIndex = hashCode(chave); 
          
    //finding the node with given chave 
    while(tabela[hashIndex] != NULL) 
    { 
        //if node found 
        if(tabela[hashIndex]->getChave() == chave) 
        { 
            NoHash *temp = tabela[hashIndex]; 
                  
            //Insert aux node here for further use 
            tabela[hashIndex] = aux; 
                  
            // Reduce tamanho 
            tamanho--; 
            return temp->getValor(); 
        } 
        hashIndex++; 
        hashIndex %= capacidade; 
  
        } 
    //If not found return null 
    return -1; 
} 

//Function to search the valor for a given chave 
int HashSondLin::get(int chave) 
{ 
    //finding the node with given chave    
    for(int i = 0; i < capacidade; i++){
        int index = hashCode(chave);
        if(tabela[index]->getChave() == chave) 
            return tabela[index]->getValor(); 
    }
    
    //If not found return null 
    return -1; 
    } 

//Return current tamanho  
int HashSondLin::getTamanho() 
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

int HashSondLin::getNumColisoes(){

    return this->numColisoes;

}