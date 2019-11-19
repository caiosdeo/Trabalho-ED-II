#include "noHuffman.h"

// Construtores e destrutor
NoHuff::NoHuff(){
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

// Funções para construir a árvore de Huffman
// Função de swap para vetor de nós de Huffman
void swap(NoHuff* huffHeap, int i, int j){

    NoHuff aux;

    aux = huffHeap[i];
    huffHeap[i] = huffHeap[j];
    huffHeap[j] = aux;

}

// Constrói uma heap de mínimo
void heapify(NoHuff *huffHeap, unsigned tam, unsigned indice){
    
    unsigned menor = indice; // Pai
    unsigned esq = 2*indice + 1; // Filho da esquerda
    unsigned dir = 2*indice + 2; // Filho da direita

    // Atualiza menor valor se necessário
    if (esq < tam && huffHeap[esq].getFrequencia() < huffHeap[menor].getFrequencia()){
        menor = esq;
    }

    // Atualiza menor valor se necessário
    if (dir < tam && huffHeap[dir].getFrequencia() < huffHeap[menor].getFrequencia()){
        menor = dir;
    }

    // Confere se o menor não é o pai 
    if (menor != indice) {
        // Troca pai com o menor filho
        swap(huffHeap, indice, menor);
        heapify(huffHeap, tam, menor); // Chama heapify
    }

}

// Constrói a árvore de Huffman
void huffTree(NoHuff *huffHeap, unsigned tam){

    // Auxiliares para os filhos à direita e à esquerda
    NoHuff auxDir;
    NoHuff auxEsq;

    while(tam > 1){

        // Constrói a heap de mínimo (menor da esquerda)
        for (int i = tam / 2 -1; i >= 0; i--)
            heapify(huffHeap, tam, i);

        auxEsq = huffHeap[0]; // retira menor frequência
        swap(huffHeap, 0, tam-1); // Desconsidera menor frequência retirada
        tam--;

        // Constrói a heap de mínimo (menor da direita)
        for (int i = tam / 2 -1; i >= 0; i--)
            heapify(huffHeap, tam, i);

        auxDir = huffHeap[0]; // retira menor frequência
        swap(huffHeap, 0, tam-1); // Desconsidera menor frequência retirada
        int novaFreq = auxDir.getFrequencia() + auxEsq.getFrequencia(); // Somando frequências dos filhos
        NoHuff pai = NoHuff(novaFreq, &auxDir, &auxEsq); // Alocando pai

        huffHeap[tam-1] = pai; // Colocando pai na huffHeap

    }


}