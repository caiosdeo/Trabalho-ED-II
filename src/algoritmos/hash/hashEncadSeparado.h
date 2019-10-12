#include <iostream>
#include <list>

using namespace std;

class HashEncadSeparado{

    private:
        unsigned balde; //Número de baldes
        list<unsigned> *tabela;

    public:
        HashEncadSeparado(unsigned baldes);
        void insereItem(unsigned chave);
        unsigned funcaoHash(unsigned chave);
        unsigned contabilizarColisoes();

};