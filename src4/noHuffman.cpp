#include "noHuffman.h"

// Construtor
NoHuff::NoHuff(char info, int freq, NoHuff* direito, NoHuff* esquerdo){

    this->info = info;
    this->freq = freq;
    this->direito = direito;
    this->esquerdo = esquerdo;

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