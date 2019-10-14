#include "hashEncadeadoUsuarios.h"
#include "funcoesAuxiliares.h"
#include<tuple>

// Construtor
HashEncadUsuarios::HashEncadUsuarios(unsigned n){

    // Inicializando atributos
    this->n = n;
    this->tabela = new list<string>[this->n];

}

// Função de hash
unsigned HashEncadUsuarios::funcaoHash(string chave){ 
    return (converterStringInteiro(chave) % this->n); 
}

// Função que insere item na tabela
void HashEncadUsuarios::insereItem(string chave){

    unsigned indice = funcaoHash(chave);
    tabela[indice].push_back(chave);
}

// Retorna a frequência da chave
unsigned HashEncadUsuarios::getFrequencia(string chave){

    return this->tabela[this->funcaoHash(chave)].size();

}

// Retorna usuários associados a suas respectivas frequências
list<string>* HashEncadUsuarios::gerarVetorFrequencia(){

    unsigned tamFreq = 0;

    // Contabiliza posições não vazias
    for(int i = 0; i < this->n; i++)
        if(this->tabela[i].size() != 0)
            tamFreq++;

    // Aloca lista para frequências
    list<string> *tabFreq = new list<string>[tamFreq];

    // Copia posições não vazias para tabela para frequências
    for(int i = 0, j = 0; i < this->n; i++)
        if(this->tabela[i].size() != 0){

            tabFreq[j] = this->tabela[i];
            j++;

        }

    // Chama o Heap Sort para ordenação decrescente das frequências
    heapSort(tabFreq, tamFreq);

    // Retorna vetor de frequências e de usuários
    return tabFreq;

}

// Exibe a frequência dos usuários
void HashEncadUsuarios::exibirFrequencias(unsigned n){

    list<string>* freq;
    freq = this->gerarVetorFrequencia();
    cout << "Frequência dos usuários:" << endl;
    for(int i = 0; i < n; i++)
        cout << i + 1 << " - " << freq[i].front() <<  " - " << freq[i].size() << endl;
    cout << endl;

}