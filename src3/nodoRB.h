#ifndef NODORB_H
#define NODORB_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class nodoRB
{
    public:
        nodoRB(int chave); //construtor

        int getChave(); //função que retorna variável chave
        bool getCor(); //função que retorna variável Cor
        nodoRB* getEsq(); //função que retorna ponteiro do filho a esquerda
        nodoRB* getDir(); //função que retorna ponteiro do filho a direita
        nodoRB* getPai(); //função que retorna ponteiro do pai

        void setCor(bool cor); //função para colocar cor
        void setEsq(nodoRB *esq); //função para colocar filho a esquerda
        void setDir(nodoRB *dir); //função para colocar filho a direita
        void setPai(nodoRB *pai); //função para colocar pai

    private:
        int chave; // variável para armazenar campo Id

        bool cor; //variável que define a cor do nodo
        nodoRB *esq, *dir, *pai; //ponteiros para os dois filhos, esquerda e direita, e pai

    // Tornando os atributos do nodo acessíveis para as funções da classe arvoreRB
    friend class arvoreRB;
};

#endif // NODORB_H
