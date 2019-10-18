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
        nodoRB(int id, string user);
        ~nodoRB(){};

        int getId();
        string getUser();
        bool getCor();
        nodoRB* getEsq();
        nodoRB* getDir();
        nodoRB* getPai();

        void setId(int id);
        void setUser(string user);
        void setCor(bool cor);
        void setEsq(nodoRB *esq);
        void setDir(nodoRB *dir);
        void setPai(nodoRB *pai);

    private:
        int id;
        string user;
        bool cor;
        nodoRB *esq, *dir, *pai;
};

#endif // NODORB_H
