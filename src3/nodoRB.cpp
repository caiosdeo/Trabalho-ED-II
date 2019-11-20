#include "nodoRB.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define VER 1 //define cor vermelha/rubro
#define PRET 0 //define cor preta/negro

using namespace std;

//Construtor
NodoRB::NodoRB(int chave)
{
    //inicializamdo variaveis chave(id) e cor
    this->chave = chave;
    this->cor = VER;
    //inicializando vairaveis esq, dir e pai como vazio
    this->esq = NULL;
    this->dir = NULL;
    this->pai = NULL;
}
//funcao que retorna variavel Id
int NodoRB::getChave()
{
    return this->chave;
}
//funcao que retorna variavel Cor
bool NodoRB::getCor()
{
    return this->cor;
}
//funcao que retorna ponteiro do filho a esquerda
NodoRB* NodoRB::getEsq()
{
    return this->esq;
}
//funcao que retorna ponteiro do filho a direita
NodoRB* NodoRB::getDir()
{
    return this->dir;
}
//funcao que retorna ponteiro do pai
NodoRB* NodoRB::getPai()
{
    return this->pai;
}
//funcao para colocar cor
void NodoRB::setCor(bool cor)
{
    this->cor = cor;
}
//funcao para colocar filho a esquerda
void NodoRB::setEsq(NodoRB *esq)
{
    this->esq = esq;
}
//funcao para colocar filho a direita
void NodoRB::setDir(NodoRB *dir)
{
    this->dir = dir;
}
//funcao para colocar pai
void NodoRB::setPai(NodoRB *pai)
{
    this->pai = pai;
}
