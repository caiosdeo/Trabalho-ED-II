#include "nodoRB.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#define RED 1
#define BLACK 0

using namespace std;

nodoRB::nodoRB(int id, string user)
{
    this->id = id;
    this->user = user;
    this->dir = NULL;
    this->esq = NULL;
    this->pai = NULL;
    this->cor = RED;
}

int nodoRB::getId()
{
    return this->id;
}

string nodoRB::getUser()
{
    return this->user;
}

bool nodoRB::getCor()
{
    return this->cor;
}

nodoRB* nodoRB::getEsq()
{
    return this->esq;
}

nodoRB* nodoRB::getDir()
{
    return this->dir;
}

nodoRB* nodoRB::getPai()
{
    return this->pai;
}

void nodoRB::setId(int id)
{
    this->id = id;
}

void nodoRB::setUser(string user)
{
    this->user = user;
}

void nodoRB::setCor(bool cor)
{
    this->cor = cor;
}

void nodoRB::setEsq(nodoRB *esq)
{
    this->esq = esq;
}

void nodoRB::setDir(nodoRB *dir)
{
    this->dir = dir;
}

void nodoRB::setPai(nodoRB *pai)
{
    this->pai = pai;
}
