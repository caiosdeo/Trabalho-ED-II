#ifndef ENCADCATEGORIAS_H_INCLUDED
#define ENCADCATEGORIAS_H_INCLUDED
#include <iostream>
#include <list>

using namespace std;

class HashEncadCategorias{

    // Atributos de HashEncadCategorias
    private:
        unsigned n; //Número do maior usuário.
        list<string> *tabela; // Vetor de lista de strings

    public:
        HashEncadCategorias(unsigned n); // Construtor
        void insereItem(string chave); // Insere item
        unsigned funcaoHash(string chave); // Função de hash
        unsigned getFrequencia(string chave); // Retorna frequência de dada categoria
        void exibirFrequencias(unsigned n); // exibe n frequências
    
    private:
        list<string>* gerarVetorFrequencia(); // Gera vetor de frequências

};

#endif //ENCADCATEGORIAS_H_INCLUDED