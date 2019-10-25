#ifndef ARVORERB_H
#define ARVORERB_H
#include "nodoRB.h"
#include <iostream>
#include <string>


class arvoreRB
{
    public:
        arvoreRB();
        ~arvoreRB();
        void insereChave(int chave, string user);
        void removeChave(int chave);
        void imprime();

    private:
        nodoRB *raiz;
        nodoRB* libera(nodoRB *aux);
        nodoRB* rotacaoEsq(nodoRB *aux);
        nodoRB* rotacaoDir(nodoRB *aux);
};

#endif // ARVORERB_H
