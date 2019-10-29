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

        int getChave(); //fun��o que retorna vari�vel chave
        string getUser(); //fun��o que retorna vari�vel User
        bool getCor(); //fun��o que retorna vari�vel Cor
        nodoRB* getEsq(); //fun��o que retorna ponteiro do filho a esquerda
        nodoRB* getDir(); //fun��o que retorna ponteiro do filho a direita
        nodoRB* getPai(); //fun��o que retorna ponteiro do pai
        nodoRB* getIrmao();

        void setChave(int chave);//função para colocar chave
        void setUser(string user);//função para colocar user
        void setCor(bool cor); //fun��o para colocar cor
        void setEsq(nodoRB *esq); //fun��o para colocar filho a esquerda
        void setDir(nodoRB *dir); //fun��o para colocar filho a direita
        void setPai(nodoRB *pai); //fun��o para colocar pai

    private:
        int chave; //{variavel para chave, ser� usada para compara��es e armazenar Id
        string user; //vairi�vel para User                                           } Vari�veis de informa��o

        bool cor; //vari�vel que define a cor do nodo
        nodoRB *esq, *dir, *pai; //ponteiros para os dois filhos, esquerda e direita, e pai

    // Tornando os atributos do nodo acess�veis para as fun��es da classe arvoreRB
    friend class arvoreRB;
};

#endif // NODORB_H
