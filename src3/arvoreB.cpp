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
NoB* ArvoreB::buscarChave(int k, unsigned *numAcessos, unsigned *numComparacoes){  

    return (raiz == nullptr) ? nullptr : this->raiz->buscarChave(k, numAcessos, numComparacoes); 

} 

// Função principal para inserir uma nova chave na árvore B
void ArvoreB::inserirChave(int k){ 

    // If a árvore estiver vazia
    if(this->raiz == nullptr){ 

        // Aloca memória para a raiz
        this->raiz = new NoB(this->d, true); 
        this->raiz->chaves[0] = k;  // Insere a chave
        this->raiz->n = 1;  // Atualiza o número de chaves na raiz.
    } 
    else { // Se a árvore não estiver vazia
        // Se a raiz está cheia, então a árvore cresce em altura.
        if (this->raiz->n == 2*this->d-1) 
        { 
            // Aloca memória para nova raiz
            NoB *s = new NoB(this->d, false); 
  
            // Tornando antiga raiz filha da nova raiz 
            s->filhos[0] = this->raiz; 

            // Divide a antiga raiz e move uma chave para a nova raiz
            s->dividirFilho(0, this->raiz); 
  
            // New root has two children now.  Decide which of the 
            // two children is going to have new key 
            // Nova raiz tem dois filhos agora
            // Escolhendo qual dos dois filhos terá uma nova chave
            int i = 0; 
            if (s->chaves[0] < k) 
                i++; 
            s->filhos[i]->inserirNaoCheio(k); 
  
            // Muda a raiz
            this->raiz = s; 

        } 
        else  // Se a raiz não estiver cheia, chama inserir não cheio para a raiz
            this->raiz->inserirNaoCheio(k); 
            
    }

}
