// Definição e funções da classe duploHash
class duploHash{

    private:
        unsigned* tabelaHash;
        unsigned tamanhoAtual;
        unsigned tamanhoTabela;
        unsigned primo;
        unsigned long numColisoes;

    public:
        duploHash(unsigned tamanhoTabela);
        ~duploHash();
        bool estaCheia();
        unsigned hash1(unsigned chave);
        unsigned hash2(unsigned chave, unsigned resto);
        void inserirHash(unsigned chave);
        void mostrarHash();
        unsigned long getNumColisoes();

};