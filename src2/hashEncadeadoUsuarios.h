#ifndef ENCADUSUARIOS_H_INCLUDED
#define ENCADUSUARIOS_H_INCLUDED
#include <iostream>
#include <list>

using namespace std;

class HashEncadUsuarios{

    // Atributos de HashEncadUsuarios
    private:
        unsigned n; //Número do maior usuário.
        list<string> *tabela; // Vetor de lista de strings

    public:
        HashEncadUsuarios(unsigned n); // Construtor
        void insereItem(string chave); // Insere item
        unsigned funcaoHash(string chave); // Função de hash
        unsigned getFrequencia(string chave); // Retorna frequência de dado usuário
        void exibirFrequencias(unsigned n); // exibe n frequências
    
    private:
        list<string>* gerarVetorFrequencia(); // Gera vetor de frequências

};

#endif //ENCADUSUARIOS_H_INCLUDED