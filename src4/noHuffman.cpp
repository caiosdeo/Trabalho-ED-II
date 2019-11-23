#include "noHuffman.h"

// Construtores e destrutor
NoHuff::NoHuff(){
    this->esquerdo = nullptr;
    this->direito = nullptr;
}

NoHuff::NoHuff(char info, int freq){

    this->info = info;
    this->freq = freq;
    this->direito = nullptr;
    this->esquerdo = nullptr;

}

NoHuff::NoHuff(int freq, NoHuff* direito, NoHuff* esquerdo){

    this->info = '\0';
    this->freq = freq;
    this->direito = direito;
    this->esquerdo = esquerdo;

}

NoHuff::~NoHuff(){
}


// Funções de get
char NoHuff::getInfo(){
    return this->info;
}

int NoHuff::getFrequencia(){
    return this->freq;
}

NoHuff* NoHuff::getDireito(){
    return this->direito;
}

NoHuff* NoHuff::getEsquerdo(){
    return this->esquerdo;
}

// Funções de set
void NoHuff::setInfo(char info){
    this->info = info;
}

void NoHuff::setFreq(int freq){
    this->freq = freq;
}

void NoHuff::setDireito(NoHuff* direito){
    this->direito = direito;
}

void NoHuff::setEsquerdo(NoHuff* esquerdo){
    this->esquerdo = esquerdo;
}