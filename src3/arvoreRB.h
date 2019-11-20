#ifndef ARVORERB_H
#define ARVORERB_H
#include "nodoRB.h"
#include <iostream>


class ArvoreRB //classe
{
    public:
        ArvoreRB(); // Construtor (Inicializando a árvore RB como vazia)
        NodoRB* getRaiz();
        void insereChave(int chave, unsigned long long *numTrocas, unsigned long long *numComp); //função de inserção da informação de campo Id
        void removeChave(int chave, unsigned long long *numTrocas, unsigned long long *numComp); //funções de remoção de chave (Id)
        bool recolorir(NodoRB *x); // função para verificar casos de recolorição
        NodoRB *busca(int chave, NodoRB *no, unsigned long long *numTrocas, unsigned long long *numComparacoes); //função de busca para chave X

    private:
        NodoRB *raiz; //ponteiro para raiz
        void rotacaoEsq(NodoRB *pai, NodoRB *avo); //função de rotação à esquerda
        void rotacaoDir(NodoRB *pai, NodoRB *avo); //função de rotação à direita
        void balancearInsercao(NodoRB *x); //função de balanceamento para inserção
        void auxBalancear(NodoRB *x, NodoRB *auxPai); //função auxiliar de balanceamento para inserção
        void auxRecolorir(NodoRB *x); //função auxiliar para recolorir

};

#endif // ARVORERB_H
