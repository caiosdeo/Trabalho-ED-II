#include "hashEncadCategorias.h"
#include "funcoesAuxiliares.h"
#include<tuple>


HashEncadCategorias::HashEncadCategorias(unsigned n){

    this->n = n;
    this->tabela = new list<string>[this->n];

}

unsigned HashEncadCategorias::funcaoHash(string chave){ 
    return (converterStringUnsigned(chave) % this->n); 
}

void HashEncadCategorias::insereItem(string chave){

    unsigned indice = funcaoHash(chave);
    tabela[indice].push_back(chave);
}

unsigned HashEncadCategorias::getFrequencia(string chave){

    return this->tabela[this->funcaoHash(chave)].size();

}

list<string>* HashEncadCategorias::gerarVetorFrequencia(){

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

    heapSort(tabFreq, tamFreq);

    return tabFreq;

}

void HashEncadCategorias::exibirFrequencias(unsigned n){

    list<string>* freq;
    freq = this->gerarVetorFrequencia();
    cout << "Frequência das categorias:" << endl;
    for(int i = 0; i < n; i++)
        cout << i + 1 << " - " << freq[i].front() <<  " - " << freq[i].size() << endl;
    cout << endl;

}