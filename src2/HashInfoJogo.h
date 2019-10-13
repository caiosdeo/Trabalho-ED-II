// Definição e funções da classe HashInfoJogo
#include "InfoJogo.h"

class HashInfoJogo{

    private:
        InfoJogo* tabelaHash;
        unsigned tamanhoAtual;
        unsigned tamanhoTabela;
        unsigned primo;
        unsigned numColisoes;

    public:
        HashInfoJogo(unsigned tamanhoTabela);
        ~HashInfoJogo();
        bool estaCheia();
        unsigned hash1(unsigned chave);
        unsigned hash2(unsigned chave, unsigned resto);
        void inserirHash(InfoJogo chave);
        unsigned getNumColisoes();

};