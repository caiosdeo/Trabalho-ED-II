#include "../classes/review.h"

// Definição e funções da classe duploHash
class duploHash{

    private:
        int* tabelaHash;
        int tamanhoAtual;
        int tamanhoTabela;
        int primo;

    public:
        duploHash(int tamanhoTabela);
        ~duploHash();
        bool estaCheia();
        int hash1(int chave);
        int hash2(int chave);
        bool ePrimo(int x);
        int getPrimo();
        void inserirHash(int chave);
        void mostrarHash();

};