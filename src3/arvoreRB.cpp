#include "arvoreRB.h"
#include "nodoRB.h"
#include <iostream>
#include <string>
#define VER 1
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
        {
            novo->setCor(PRET);
            this->raiz = novo;
        }
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
    balancearInsercao(novo);
}

void arvoreRB::balancearInsercao(nodoRB *x)
{
    if(x != this->raiz)
    {
        nodoRB *auxPai = x->getPai();
        if(auxPai != NULL && auxPai->getCor() != PRET)
        {
            if(!recolorir(x))
            {
                auxBalancear(x, auxPai);
            }
        }
    }
}

bool arvoreRB::recolorir(nodoRB *x)
{
    nodoRB *auxPai = x->getPai();
    if(this->raiz->getCor() == VER) this->raiz->setCor(PRET);
    nodoRB *avo = auxPai->getPai(), *tio;
    if(avo->getEsq() != auxPai)
        tio = avo->getEsq();
    else
        tio = avo->getDir();
    if(tio != NULL && tio->getCor() != PRET)
    {
        auxRecolorir(x);
        return true;
    }
    return false;
}

void arvoreRB::auxRecolorir(nodoRB *x)
{
    nodoRB *auxPai = x->getPai(), *auxAvo, *auxTio;
    if(auxPai != NULL)
    {
        auxPai->setCor(PRET);
        auxAvo = auxPai->getPai();
        if(auxAvo != NULL)
        {
            auxAvo->setCor(VER);
            if(auxAvo->getEsq() != auxPai)
                auxTio = auxAvo->getEsq();
            else
                auxTio = auxAvo->getDir();
            if(auxTio != NULL)
                auxTio->setCor(PRET);
            auxRecolorir(auxAvo);
        }
    }
}

void arvoreRB::auxBalancear(nodoRB *x, nodoRB *auxPai)
{
    nodoRB *auxAvo = auxPai->getPai();
    if(auxAvo->getDir() == auxPai && auxPai->getDir() == x)
    {
        rotacaoEsq(auxPai, auxAvo);
        auxPai->setCor(PRET);
        auxAvo->setCor(VER);
    }
    if(auxAvo->getEsq() == auxPai && auxPai->getEsq() == x)
    {
        rotacaoDir(auxPai, auxAvo);
        auxPai->setCor(PRET);
        auxAvo->setCor(VER);
    }
    if(auxAvo->getEsq() == auxPai && auxPai->getDir() == x)
    {
        rotacaoEsq(x, auxPai);
        rotacaoDir(x, auxAvo);
        x->setCor(PRET);
        x->getDir()->setCor(VER);
    }
    if(auxAvo->getDir() == auxPai && auxPai->getEsq() == x)
    {
        rotacaoDir(x, auxPai);
        rotacaoEsq(x, auxAvo);
        x->setCor(PRET);
        auxAvo->setCor(VER);
    }
}
//Função de rotação à esquerda
void arvoreRB::rotacaoEsq(nodoRB *x, nodoRB *pai)
{
    nodoRB *auxAvo = pai->getPai();
    if(auxAvo != NULL)
    {
        if(auxAvo->getEsq() == pai)
            auxAvo->setEsq(x);
        else
            auxAvo->setDir(x);
        if(auxAvo == this->raiz)
            this->raiz = x;
    }
    x->setPai(auxAvo);
    pai->setPai(x);
    pai->setDir(x->getEsq());
    x->setEsq(pai);
}
//Função de rotação à direita
void arvoreRB::rotacaoDir(nodoRB *x, nodoRB *pai)
{
    nodoRB *auxAvo = pai->getPai();
    if(auxAvo != NULL)
    {
        if(auxAvo->getEsq() == pai)
            auxAvo->setEsq(x);
        else
            auxAvo->setDir(x);
        if(auxAvo == this->raiz)
            this->raiz = x;
    }
    x->setPai(auxAvo);
    pai->setPai(x);
    pai->setEsq(x->getDir());
    x->setDir(pai);
}
