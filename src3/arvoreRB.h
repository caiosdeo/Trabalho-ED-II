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
        void rotEsquerda(nodoRB *no);
        void rotDireita(nodoRB *no);
        void imprime();
        void fixDoubleBlack(nodoRB *no);
        nodoRB* busca(int chave, nodoRB *no);
        nodoRB* substituto(nodoRB *no);

    private:
        nodoRB *raiz;
        nodoRB* libera(nodoRB *aux);
        void auxImprime(nodoRB *aux);
};

#endif // ARVORERB_H
