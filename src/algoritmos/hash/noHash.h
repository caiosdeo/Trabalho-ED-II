#ifndef NOHASH_H_INCLUDED
#define NOHASH_H_INCLUDED

#include <fstream>
#include <stack>
#include <list>

using namespace std;

class NoHash{ 

    private:
        int valor; 
        int chave; 

    public: 
        NoHash(int chave, int valor); 
        int getChave();
        int getValor();
};
#endif //NOHASH_H_INCLUDED