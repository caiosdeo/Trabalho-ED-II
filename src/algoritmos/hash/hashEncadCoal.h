#ifndef HASHENCADCOAL_H
#define HASHENCADCOAL_H
#include <stdio.h>
#include "noHashCoal.h"

using namespace std;

///classe de hash coalescido (sem porao)
class hashEncadCoal
{
    private:
        unsigned numeroChaves; //unsignedeiro para numero total de Chaves
        noHashCoal *inicio; //ponteiro para primeiro noHashCoal
        noHashCoal *ultimo; //ponteiro para ultimo noHashCoal

    public:
        hashEncadCoal(unsigned numeroChaves);
        ~hashEncadCoal();
        unsigned funcaoHash(unsigned chave);
        void insereItem(unsigned chave, unsigned long *countColisoes);
        void removeItem(unsigned chave);
        noHashCoal* getPosicao(unsigned chave, noHashCoal *crash);
};


#endif // HASHENCADCOAL_H
