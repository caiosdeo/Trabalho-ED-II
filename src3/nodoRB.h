#ifndef NODORB_H
#define NODORB_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class nodoRB
{
    public:
        nodoRB(int chave, string user); //construtor

        int getChave(); //função que retorna variável chave
        string getUser(); //função que retorna variável User
        bool getCor(); //função que retorna variável Cor
        nodoRB* getEsq(); //função que retorna ponteiro do filho a esquerda
        nodoRB* getDir(); //função que retorna ponteiro do filho a direita
        nodoRB* getPai(); //função que retorna ponteiro do pai

        void setCor(bool cor); //função para colocar cor
        void setEsq(nodoRB *esq); //função para colocar filho a esquerda
        void setDir(nodoRB *dir); //função para colocar filho a direita
        void setPai(nodoRB *pai); //função para colocar pai

    private:
        int chave; //{variavel para chave, será usada para comparações e armazenar Id
        string user; //vairiável para User                                           } Variáveis de informação

        bool cor; //variável que define a cor do nodo
        nodoRB *esq, *dir, *pai; //ponteiros para os dois filhos, esquerda e direita, e pai

    // Tornando os atributos do nodo acessíveis para as funções da classe arvoreRB
    friend class arvoreRB;
};

#endif // NODORB_H
