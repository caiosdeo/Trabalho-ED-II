#include "noHash.h"

NoHash::NoHash(int chave, int valor)
{ 
    this->valor = valor; 
    this->chave = chave; 
}

int NoHash::getChave(){
    return this->chave;
} 
