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
    void removeChave(int chave, unsigned *numTrocas, unsigned *numComparacoes);
    void rotEsquerda(nodoRB *no, unsigned *numTrocas, unsigned *numComparacoes);
    void rotDireita(nodoRB *no, unsigned *numTrocas, unsigned *numComparacoes);
    void imprime();
    void fixDoubleBlack(nodoRB *no, unsigned *numTrocas, unsigned *numComparacoes);
    nodoRB *busca(int chave, nodoRB *no, unsigned *numTrocas, unsigned *numComparacoes);
    nodoRB *substituto(nodoRB *no);

private:
    nodoRB *raiz;
    nodoRB *libera(nodoRB *aux);
    void auxImprime(nodoRB *aux);
};

#endif // ARVORERB_H
