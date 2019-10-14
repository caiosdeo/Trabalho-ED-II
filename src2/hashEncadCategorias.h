#ifndef ENCADCATEGORIAS_H_INCLUDED
#define ENCADCATEGORIAS_H_INCLUDED
#include <iostream>
#include <list>

using namespace std;

class HashEncadCategorias{

    private:
        unsigned n; //Número do maior usuário.
        list<string> *tabela;

    public:
        HashEncadCategorias(unsigned n);
        void insereItem(string chave);
        unsigned funcaoHash(string chave);
        unsigned getFrequencia(string chave); // Retorna frequência de dado usuário
        void exibirFrequencias(unsigned n); // exibe n frequências
    
    private:
        pair<string*, list<string>*> gerarVetorFrequencia(); 

};

#endif //ENCADCATEGORIAS_H_INCLUDED