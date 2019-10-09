#include <fstream>
#include <stack>
#include <list>
#include "noHash.h"

using namespace std;

//SONDAGEM LINEAR

class HashSondLin{ 
    
    private:
        //hash element array 
        NoHash **tabela; 
        unsigned capacidade; 
        //current tamanho 
        unsigned tamanho; 
        //auxiliar node 
        NoHash *aux; 
        unsigned numColisoes;
  
    public: 
        HashSondLin(unsigned capacidade);
        //~HashSondLin();
        unsigned hashCode(unsigned chave);
        void insereNo(unsigned chave, unsigned valor);
        unsigned deleteNo(unsigned chave);
        unsigned get(unsigned chave);
        unsigned getTamanho();
        bool estaVazia();
        bool estaCheia();
        void display();
        unsigned getNumColisoes();

}; 