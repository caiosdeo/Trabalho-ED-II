#include <iostream>
#include <list>

using namespace std;

class HashEncadSeparado{

    private:
        int balde; //Número de baldes
        list<int> *tabela;

    public:
        HashEncadSeparado(int baldes);
        ~HashEncadSeparado();
        void insereItem(int chave);
        void removeItem(int chave);
        int funcaoHash(int chave);
        void imprimirHash();
        unsigned long contabilizarColisoes();

};