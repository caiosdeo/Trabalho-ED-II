#include <fstream>
#include <stack>
#include <list>
#include "noHash.h"

using namespace std;

class HashSondQuad{ 
    private:
        NoHash **tabela; 
        unsigned capacidade;
        unsigned tamanho; 
        NoHash *aux; 
        unsigned numColisoes;
  
    public: 
        HashSondQuad(unsigned capacidade);
        unsigned hashCode(unsigned chave);
        void insereNo(unsigned chave, unsigned valor);
        unsigned getTamanho();
        bool estaCheia();
        unsigned getNumColisoes();

}; 