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
        int getAltura();
        bool recolorir(nodoRB *x);

    private:
        nodoRB *raiz;
        nodoRB* libera(nodoRB *aux);
        void rotacaoEsq(nodoRB *pai, nodoRB *avo);
        void rotacaoDir(nodoRB *pai, nodoRB *avo);
        void balancearInsercao(nodoRB *x);
        void auxBalancear(nodoRB *x, nodoRB *auxPai);
        void auxRecolorir(nodoRB *x);

};

#endif // ARVORERB_H
