#include <fstream>
#include <stack>
#include <list>
#include "noHash.h"

using namespace std;

//SONDAGEM LINEAR

class HashSondLin{ 
    
    private:
        NoHash **tabela; 
        unsigned capacidade; 
        unsigned tamanho; 
        NoHash *aux; 
        unsigned numColisoes;
  
    public: 
        HashSondLin(unsigned capacidade);
        unsigned hashCode(unsigned chave);
        void insereNo(unsigned chave, unsigned valor);
        unsigned getTamanho();
        bool estaCheia();
        unsigned getNumColisoes();

}; 