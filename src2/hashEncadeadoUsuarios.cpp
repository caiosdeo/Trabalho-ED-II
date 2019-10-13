#include <iostream>
#include <list>
#include "hashEncadeadoUsuarios.h"
#include "funcoesAuxiliares.h"

HashEncadUsuarios::HashEncadUsuarios(unsigned n){

    this->n = n;
    this->tabela = (new list<string>[this->n]);

}

unsigned HashEncadUsuarios::funcaoHash(string chave){ 
    return (converterStringUnsigned(chave) % this->n); 
}

void HashEncadUsuarios::insereItem(string chave){

    unsigned indice = funcaoHash(chave);
    tabela[indice].push_back(chave);
}

unsigned HashEncadUsuarios::getFrequencia(string chave){

    return this->tabela[this->funcaoHash(chave)].size();

}

string* HashEncadUsuarios::gerarVetorFrequencia(){

    unsigned tamFreq = 0;

    for(int i = 0; i < this->n; i++)
        if(this->tabela[i].size() != 0)
            tamFreq++;

    list<string> *tabFreq = (new list<string>[tamFreq]);  

    for(int i = 0, j = 0; i < this->n; i++)
        if(this->tabela[i].size() != 0){

            tabFreq[j] = this->tabela[i];
            j++;

        }

    string* freqUser = (string*)malloc(tamFreq*sizeof(string));

    for(int i = 0, j = 0; i < n; i++)
        freqUser[j] = tabela[i].front();

    heapSort(tabFreq, freqUser, tamFreq);

    return freqUser;

}

void HashEncadUsuarios::exibirFrequencias(unsigned n){

    string* freq = this->gerarVetorFrequencia();
    for(int i = 0; i < n; i++)
        cout << i + 1 << " - " << freq[i] << endl;
    cout << endl;

}

/*unsigned HashEncadUsuarios::contabilizarColisoes(){

    unsigned numColisoes = 0;

    for(unsigned i = 0; i < this->n; i++)
        numColisoes += this->tabela[i].size() - 1;

    return numColisoes;

}*/