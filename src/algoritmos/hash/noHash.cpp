#include "noHash.h"

NoHash::NoHash(unsigned chave, unsigned valor)
{ 
    this->valor = valor; 
    this->chave = chave; 
}

unsigned NoHash::getChave(){
    return this->chave;
} 

unsigned NoHash::getValor(){
    return this->valor;
} 