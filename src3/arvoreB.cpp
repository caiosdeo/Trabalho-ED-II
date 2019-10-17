#include "arvoreB.h"

// Construtor (Inicializando a árvore como vazia)
ArvoreB::ArvoreB(int d){ 

        raiz = nullptr;  
        this->d = d; 
    
    } 
  
// Função para percorrer a árvore
void ArvoreB::percorrerArvore(){ 

    if(this->raiz != nullptr) 
        this->raiz->percorrerSubarvore(); 

} 
  
// Função para procurar a chave k na árvore
NoB* ArvoreB::buscarChave(int k){  

    return (raiz == nullptr)? nullptr : this->raiz->buscarChave(k); 

} 
