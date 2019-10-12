#ifndef HASHENCADCOAL_H
#define HASHENCADCOAL_H
#include <stdio.h>

using namespace std;

///classe de hash coalescido (sem porao)
class hashEncadCoal
{
    private:
        unsigned numeroChaves;
        unsigned* tabela;
        unsigned* colisoes;


    public:
        hashEncadCoal(unsigned numeroChaves);
        ~hashEncadCoal();
        unsigned getIndiceColisao(unsigned indice);
        unsigned funcaoHash(unsigned chave);
        void insereItem(unsigned chave, unsigned *countColisoes);
        
};


#endif // HASHENCADCOAL_H
