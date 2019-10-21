#include "arvoreRB.h"
#include "nodoRB.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#define RUB 1
#define PRET 0

arvoreRB::arvoreRB()
{
    this->raiz = NULL;
}

arvoreRB::~arvoreRB()
{

}

arvoreRB::insereChave(int chave, string user)
{
    nodoRB *novo = new nodoRB(chave, user); //aloca novo nodo

    //se �rvore vazia
    if(this->raiz == NULL)
        this->raiz = novo;
    //se n�o estiver vazia
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
    //fun��es para verificar e fazer tanto balanceamento quanto recoloriza��o
}
