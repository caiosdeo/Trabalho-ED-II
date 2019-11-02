#ifndef ARVORERB_H
#define ARVORERB_H
#include "nodoRB.h"
#include <iostream>


class arvoreRB //classe
{
    public:
        arvoreRB(); // Construtor (Inicializando a árvore RB como vazia)
        ~arvoreRB(); //destrutor
        void insereChave(int chave, unsigned *numTrocas, unsigned *numComp); //função de inserção da informação de campo Id
        void removeChave(int chave, unsigned *numTrocas, unsigned *numComp); //funções de remoção de chave (Id)
        bool recolorir(nodoRB *x); // função para verificar casos de recolorição

    private:
        nodoRB *raiz; //ponteiro para raiz
        nodoRB* libera(nodoRB *aux); //função que deleta nó recursivamente
        void rotacaoEsq(nodoRB *pai, nodoRB *avo); //função de rotação à esquerda
        void rotacaoDir(nodoRB *pai, nodoRB *avo); //função de rotação à direita
        void balancearInsercao(nodoRB *x); //função de balanceamento para inserção
        void auxBalancear(nodoRB *x, nodoRB *auxPai); //função auxiliar de balanceamento para inserção
        void auxRecolorir(nodoRB *x); //função auxiliar para recolorir

};

#endif // ARVORERB_H
