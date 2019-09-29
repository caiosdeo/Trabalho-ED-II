// Definição e funções da classe duploHash
class duploHash{

    private:
        int* tabelaHash;
        int tamanhoAtual;
        int tamanhoTabela;
        int primo;
        unsigned long long int numColisoes;

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
        unsigned long long int getNumColisoes();

};