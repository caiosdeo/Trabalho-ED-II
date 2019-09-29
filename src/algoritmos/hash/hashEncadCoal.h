#ifndef HASHENCADCOAL_H
#define HASHENCADCOAL_H
<<<<<<< HEAD
#include <stdio.h>
=======
>>>>>>> e1444e77b917beba6cad8571b18fca014b0edc21
#include "noHashCoal.h"

using namespace std;

///classe de hash coalescido (sem porao)
class hashEncadCoal
{
    private:
        int numeroChaves;
        noHashCoal *inicio;
        noHashCoal *ultimo;

    public:
        hashEncadCoal(int numeroChaves);
        ~hashEncadCoal();
        int funcaoHash(int chave);
        void insereItem(int chave);
        void removeItem(int chave);
        noHashCoal* getPosicao(int chave, noHashCoal *crash);
};


#endif // HASHENCADCOAL_H
