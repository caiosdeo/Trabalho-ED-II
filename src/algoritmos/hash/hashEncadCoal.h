#ifndef HASHENCADCOAL_H
#define HASHENCADCOAL_H
#include "NoHash.h"

using namespace std;

///classe de hash coalescido (sem porao)
class hashEncadCoal
{
    private:
        int numeroChaves;
        NoHash *inicio;

    public:
        hashEncadCoal(int numeroChaves);
        ~hashEncadCoal();
        int funcaoHash(int chave);
        void insereItem(int chave);
        void removeItem(int chave);
        NoHash* getPosicao(int chave);
};


#endif // HASHENCADCOAL_H
