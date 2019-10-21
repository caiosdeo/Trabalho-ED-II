#include "arvoreRB.h"
#include "nodoRB.h"
#include <iostream>
#include <string>
#define RUB 1
#define PRET 0

using namespace std;

arvoreRB::arvoreRB()
{
    this->raiz = NULL;
}

nodoRB* arvoreRB::libera(nodoRB *aux)
{
    if(aux != NULL)
    {
        aux->setEsq(libera(aux->getEsq()));
        aux->setDir(libera(aux->getDir()));
        delete aux;
        aux = NULL;
    }
    return NULL;
}

arvoreRB::~arvoreRB()
{
    this->raiz = libera(this->raiz);
}

void arvoreRB::insereChave(int chave, string user)
{
    nodoRB *novo = new nodoRB(chave, user); //aloca novo nodo

    //se árvore vazia
    if(this->raiz == NULL)
        this->raiz = novo;
    //se não estiver vazia
    else
    {
        nodoRB *aux = this->raiz;
        while(aux != NULL)
        {
            if(chave < aux->getChave())
            {
                if(aux->getEsq() == NULL)
                {
                    aux->setEsq(novo);
                    novo->setPai(aux);
                    break;
                }
                aux = aux->getEsq();
            }
            else
            {
                if(aux->getDir() == NULL)
                {
                    aux->setDir(novo);
                    novo->setPai(aux);
                    break;
                }
                aux = aux->getDir();
            }
        }
    }
    //funções para verificar e fazer tanto balanceamento quanto recolorização
}
