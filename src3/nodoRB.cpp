#include "nodoRB.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#define RUB 1 //define cor vermelha/rubro
#define PRET 0 //define cor preta/negro

using namespace std;

//Construtor
nodoRB::nodoRB(int chave, string user)
{
    //inicializamdo variaveis chave(id), user e cor
    this->chave = chave;
    this->user = user;
    this->cor = RUB;
    //inicializando vairaveis esq, dir e pai como vazio
    this->esq = NULL;
    this->dir = NULL;
    this->pai = NULL;
}
//funcao que retorna variavel Id
int nodoRB::getId()
{
    return this->chave;
}
//funcao que retorna variavel User
string nodoRB::getUser()
{
    return this->user;
}
//funcao que retorna variavel Cor
bool nodoRB::getCor()
{
    return this->cor;
}
//funcao que retorna ponteiro do filho a esquerda
nodoRB* nodoRB::getEsq()
{
    return this->esq;
}
//funcao que retorna ponteiro do filho a direita
nodoRB* nodoRB::getDir()
{
    return this->dir;
}
//funcao que retorna ponteiro do pai
nodoRB* nodoRB::getPai()
{
    return this->pai;
}
//funcao para colocar cor
void nodoRB::setCor(bool cor)
{
    this->cor = cor;
}
//funcao para colocar filho a esquerda
void nodoRB::setEsq(nodoRB *esq)
{
    this->esq = esq;
}
//funcao para colocar filho a direita
void nodoRB::setDir(nodoRB *dir)
{
    this->dir = dir;
}
//funcao para colocar pai
void nodoRB::setPai(nodoRB *pai)
{
    this->pai = pai;
}
