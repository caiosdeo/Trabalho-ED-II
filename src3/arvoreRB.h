#ifndef ARVORERB_H
#define ARVORERB_H
#include "nodoRB.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>


class arvoreRB
{
    public:
        arvoreRB();
        ~arvoreRB();
        void insereChave(int chave, string user);
        void removeChave(int chave);

    private:
        nodoRB *raiz;
};

#endif // ARVORERB_H
