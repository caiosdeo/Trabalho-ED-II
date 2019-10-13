#include "hashEncadeadoUsuarios.h"
#include "funcoesAuxiliares.h"
#include<tuple>


HashEncadUsuarios::HashEncadUsuarios(unsigned n){

    this->n = n;
    this->tabela = new list<string>[this->n];

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

pair<string*, list<string>*> HashEncadUsuarios::gerarVetorFrequencia(){

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

    for(int i = 0; i < tamFreq; i++)
        freqUser[i] = tabFreq[i].front();

    heapSort(tabFreq, freqUser, tamFreq);

    return make_pair(freqUser, tabFreq);

}

void HashEncadUsuarios::exibirFrequencias(unsigned n){

    string* freq;
    list<string>* freqSize;
    tie(freq, freqSize) = this->gerarVetorFrequencia();
    for(int i = 0; i < n; i++)
        cout << i + 1 << " - " << freq[i] <<  " - " << freqSize[i].size() << endl;
    cout << endl;

}