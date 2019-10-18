#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED
#include "noB.h"
class ArvoreB{ 

    NoB *raiz; // Ponteiro para a raiz
    int d;  // ordem

    public: 
    // Construtor (Inicializando a árvore B como vazia)
    ArvoreB(int d);
    // Função para percorrer a árvore B
    void percorrerArvore();
    // Função para procurar a chave k na árvore B
    NoB* buscarChave(int k, unsigned *numAcessos, unsigned *numComparacoes);
    // Função para inserir uma chave na árvore B
    void inserirChave(int k, unsigned *numAcessos, unsigned *numComparacoes);
    // Remove a chave k da árvore B 
    void removerChave(int k); 

}; 

#endif // ARVOREB_H_INCLUDED