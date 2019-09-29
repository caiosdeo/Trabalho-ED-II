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
        HashSondLin(int capacidade);
        ~HashSondLin();
        int hashCode(int chave);
        void insereNo(int chave, int valor);
        int deleteNo(int chave);
        int get(int chave);
        int getTamanho();
        bool estaVazia();
        bool estaCheia();
        void display();
        int getNumColisoes();

}; 