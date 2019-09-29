#include <fstream>
#include <stack>
#include <list>
#include "noHash.h"

using namespace std;

class HashSondQuad{ 
    private:
        NoHash **tabela; 
        int capacidade;
        int tamanho; 
        NoHash *aux; 
        unsigned long long int numColisoes;
  
    public: 
        HashSondQuad(int capacidade);
        int hashCode(int chave);
        void insereNo(int chave, int valor);
        int deleteNo(int chave);
        int getTamanho();
        bool estaVazia();
        bool estaCheia();
        void display();
        unsigned long long int getNumColisoes();

}; 