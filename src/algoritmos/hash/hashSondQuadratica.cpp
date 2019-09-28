#include "hashSondQuadratica.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

HashSondQuad::HashSondQuad(int capacidade) 
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
int HashSondQuad::hashCode(int chave) 
{ 
    return chave % capacidade; 
} 


void HashSondQuad::insereNo(int chave, int valor) 
{ 
    if(estaCheia()){
        return;
    }
    NoHash* temp = new NoHash(chave, valor); 
    bool houveColisao = false;
    // Apply hash function to find index for given chave 
    int hashIndex = hashCode(chave); 
    //find next free space  
    for(int i = 1; tabela[hashIndex] != NULL && tabela[hashIndex]->getChave() != chave 
            && tabela[hashIndex]->getChave() != -1; i++) 
    { 
        houveColisao = true;
        hashIndex = (chave + (i*i)) % capacidade; 
    } 

    if(houveColisao)
        this->numColisoes++;
          
    //if new node to be inserted increase the current tamanho 
    if(tabela[hashIndex] == NULL || tabela[hashIndex]->getChave() == -1) 
        tamanho++; 

    tabela[hashIndex] = temp; 
} 

//Function to delete a chave valor pair 
int HashSondQuad::deleteNo(int chave) 
{ 
    // Apply hash function to find index for given chave 
    int hashIndex = hashCode(chave); 
          
    //finding the node with given chave 
    for(int i  = 1; tabela[hashIndex] != NULL; i++) 
    { 
        //if node found 
        if(tabela[hashIndex]->getChave() == chave) 
        { 
            NoHash *temp = tabela[hashIndex];     
            //Insert aux node here for further use 
            tabela[hashIndex] = aux; 
            tamanho--; 
            return temp->getValor(); 
        } 
        hashIndex = (chave + (i*i)) % capacidade; 
    } 
    //If not found return null 
    return -1; 
}
int HashSondQuad::getTamanho() 
{ 
    return tamanho; 
}
bool HashSondQuad::estaCheia()
{
    return tamanho == capacidade;
} 
bool HashSondQuad::estaVazia() 
{ 
    return tamanho == 0; 
} 

int HashSondQuad::getNumColisoes(){

    return this->numColisoes;

}