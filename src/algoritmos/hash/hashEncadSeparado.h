#include <iostream>
#include <list>

using namespace std;

class HashEncadSeparado{

    private:
        unsigned balde; //Número de baldes
        list<unsigned> *tabela;

    public:
        HashEncadSeparado(unsigned baldes);
        ~HashEncadSeparado();
        void insereItem(unsigned chave);
        void removeItem(unsigned chave);
        unsigned funcaoHash(unsigned chave);
        void imprimirHash();
        unsigned long contabilizarColisoes();

};