#ifndef NOHASH_H_INCLUDED
#define NOHASH_H_INCLUDED

#include <fstream>
#include <stack>
#include <list>

using namespace std;

class NoHash{ 

    private:
        unsigned valor; 
        unsigned chave; 

    public: 
        NoHash(unsigned chave, unsigned valor); 
        unsigned getChave();
        unsigned getValor();
};
#endif //NOHASH_H_INCLUDED