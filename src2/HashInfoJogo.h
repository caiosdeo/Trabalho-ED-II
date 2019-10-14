#ifndef HASHINFOJOGO_H_INCLUDED
#define HASHINFOJOGO_H_INCLUDED

// Definição e funções da classe HashInfoJogo
#include "InfoJogo.h"

class HashInfoJogo{

    // Atributos da tabela hash
    private:
        InfoJogo* tabelaHash;
        unsigned tamanhoAtual;
        unsigned tamanhoTabela;
        unsigned numColisoes;

    public:
        HashInfoJogo(unsigned tamanhoTabela);
        bool estaCheia();
        // Função de hash 1
        unsigned hash1(unsigned chave);
        // Função de hash 2
        unsigned hash2(unsigned chave, unsigned resto);
        void inserirHash(InfoJogo chave); // Insere chave na tabela hash
        unsigned getNumColisoes(); // Retorna o número de colisões
        InfoJogo* getTabelaHash(); // Retorna referência da tabela hash

};
#endif //HASHINFOJOGO_H_INCLUDED