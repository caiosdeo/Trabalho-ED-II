#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED
#include "noB.h"


class BTree{ 
    NoB *raiz; // Ponteiro para a raiz
    int d;  // ordem
public: 
    // Construtor (Inicializando a árvore como vazia)
    BTree(int d){ 

        raiz = nullptr;  
        this->d = d; 
    
    } 
  
    // Função para atravessar a árvore
    void atravessarArvore(){ 

        if(this->raiz != nullptr) 
            this->raiz->atravessarSubarvore(); 

    } 
  
    // Função para procurar a chave k na árvore
    NoB* search(int k){  

        return (raiz == nullptr)? nullptr : this->raiz->search(k); 

    } 

}; 

#endif // ARVOREB_H_INCLUDED