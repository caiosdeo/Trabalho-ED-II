#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED
#include "noB.h"
class ArvoreB{ 

    NoB *raiz; // Ponteiro para a raiz
    int d;  // ordem

    public: 
    // Construtor (Inicializando a árvore como vazia)
    ArvoreB(int d);
    // Função para percorrer a árvore
    void percorrerArvore();
    // Função para procurar a chave k na árvore
    NoB* buscarChave(int k);

}; 

#endif // ARVOREB_H_INCLUDED