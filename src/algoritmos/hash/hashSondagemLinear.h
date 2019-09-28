#include <fstream>
#include <stack>
#include <list>
#include "noHash.h"

using namespace std;

//SONDAGEM LINEAR

class HashSondLin{ 
    //hash element array 
    NoHash **tabela; 
    int capacidade; 
    //current tamanho 
    int tamanho; 
    //auxiliar node 
    NoHash *aux; 
    int numColisoes;
  
    public: 
        HashSonLin(int capacidade);
        int hashCode(int chave);
        void insereNo(int chave, int value);
        int deleteNo(int chave);
        int get(int chave);
        int tamanho();
        bool estaVazia();
        bool estaCheia();
        void display();
        int getNumColisoes();

}; 