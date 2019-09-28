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
        int numColisoes;
  
    public: 
        HashSondQuad(int capacidade);
        int hashCode(int chave);
        void insereNo(int chave, int valor);
        int deleteNo(int chave);
        int tamanho();
        bool estaVazia();
        bool estaCheia();
        void display();
        int getNumColisoes();

}; 