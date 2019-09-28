#include "hashSondQuadratica.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

HashNode::HashNode(int key, int value)
{ 
    this->value = value; 
    this->key = key; 
}

int HashNode::getKey(){
    return this->key;
} 

HashMap::HashMap(int capacity) 
{ 
    //Initial capacity of hash array 
    this->capacity = capacity; 
    size = 0; 
    hashTable = new HashNode*[capacity]; 
    this->numColisoes = 0;
          
    //Initialise all elements of array as NULL 
    for(int i=0 ; i < capacity ; i++) 
        hashTable[i] = NULL; 
      
    //aux node with value and key -1 
    HashNode* aux = new HashNode(-1, -1); 
} 

// This implements hash function to find index 
// for a key 
int HashMap::hashCode(int key) 
{ 
    return key % capacity; 
} 


void HashMap::insertNode(int key, int value) 
{ 
    if(estaCheia()){
        return;
    }
    HashNode* temp = new HashNode(key, value); 
    bool houveColisao = false;
    // Apply hash function to find index for given key 
    int hashIndex = hashCode(key); 
    //find next free space  
    for(int i = 1; hashTable[hashIndex] != NULL && hashTable[hashIndex]->key != key 
            && hashTable[hashIndex]->key != -1; i++) 
    { 
        houveColisao = true;
        hashIndex = (key + (i*i)) % capacity; 
    } 

    if(houveColisao)
        this->numColisoes++;
          
    //if new node to be inserted increase the current size 
    if(hashTable[hashIndex] == NULL || hashTable[hashIndex]->key == -1) 
        size++; 

    hashTable[hashIndex] = temp; 
} 

//Function to delete a key value pair 
int HashMap::deleteNode(int key) 
{ 
    // Apply hash function to find index for given key 
    int hashIndex = hashCode(key); 
          
    //finding the node with given key 
    for(int i  = 1; hashTable[hashIndex] != NULL; i++) 
    { 
        //if node found 
        if(hashTable[hashIndex]->key == key) 
        { 
            HashNode *temp = hashTable[hashIndex];     
            //Insert aux node here for further use 
            hashTable[hashIndex] = aux; 
            size--; 
            return temp->value; 
        } 
        hashIndex = (key + (i*i)) % capacity; 
        } 
    //If not found return null 
    return -1; 
}
int HashMap::sizeofMap() 
{ 
    return size; 
}
bool HashMap::estaCheia()
{
    return size == capacity;
} 
bool HashMap::estaVazia() 
{ 
    return size == 0; 
} 

int HashMap::getNumColisoes(){

    return this->numColisoes;

}