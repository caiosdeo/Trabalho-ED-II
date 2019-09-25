#include "hashSondagemLinear.h"
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

HashMap::HashMap() 
{ 
    //Initial capacity of hash array 
    capacity = 20; 
    size=0; 
    arr = new HashNode*[capacity]; 
          
    //Initialise all elements of array as NULL 
    for(int i=0 ; i < capacity ; i++) 
        arr[i] = NULL; 
      
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
    HashNode* temp = new HashNode(key, value); 
    // Apply hash function to find index for given key 
    int hashIndex = hashCode(key); 
    //find next free space  
    while(arr[hashIndex] != NULL && arr[hashIndex]->key != key 
            && arr[hashIndex]->key != -1) 
    { 
        hashIndex++; 
        hashIndex %= capacity; 
    } 
          
    //if new node to be inserted increase the current size 
    if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1) 
        size++; 
    arr[hashIndex] = temp; 
} 

//Function to delete a key value pair 
int HashMap::deleteNode(int key) 
{ 
    // Apply hash function to find index for given key 
    int hashIndex = hashCode(key); 
          
    //finding the node with given key 
    while(arr[hashIndex] != NULL) 
    { 
        //if node found 
        if(arr[hashIndex]->key == key) 
        { 
            HashNode *temp = arr[hashIndex]; 
                  
            //Insert aux node here for further use 
            arr[hashIndex] = aux; 
                  
            // Reduce size 
            size--; 
            return temp->value; 
        } 
        hashIndex++; 
        hashIndex %= capacity; 
  
        } 
    //If not found return null 
    return -1; 
} 

//Function to search the value for a given key 
int HashMap::get(int key) 
{ 
    //finding the node with given key    
    for(int i = 0; i < capacity; i++){
        int index = hashCode(key);
        if(arr[index]->key == key) 
            return arr[index]->value; 
    }
    
    //If not found return null 
    return -1; 
    } 

//Return current size  
int HashMap::sizeofMap() 
{ 
    return size; 
} 

//Return true if size is 0 
bool HashMap::isEmpty() 
{ 
    return size == 0; 
} 