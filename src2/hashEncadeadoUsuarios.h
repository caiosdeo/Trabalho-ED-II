#ifndef ENCADUSUARIOS_H_INCLUDED
#define ENCADUSUARIOS_H_INCLUDED
#include <iostream>
#include <list>

using namespace std;

class HashEncadUsuarios{

    private:
        unsigned n; //Número do maior usuário.
        list<string> *tabela;

    public:
        HashEncadUsuarios(unsigned n);
        void insereItem(string chave);
        unsigned funcaoHash(string chave);
        unsigned getFrequencia(string chave); // Retorna frequência de dado usuário
        void exibirFrequencias(unsigned n); // exibe n frequências
    
    private:
        pair<string*, list<string>*> gerarVetorFrequencia(); 

};

#endif //ENCADUSUARIOS_H_INCLUDED