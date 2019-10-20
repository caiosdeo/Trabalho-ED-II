#include "arvoreB.h"
#include <iostream>
using namespace std;

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
NoB* ArvoreB::buscarChave(int k, unsigned *numTrocas, unsigned *numComparacoes){  

    return (raiz == nullptr) ? nullptr : this->raiz->buscarChave(k, numTrocas, numComparacoes); 

} 

// Função principal para inserir uma nova chave na árvore B
void ArvoreB::inserirChave(int k, unsigned *numTrocas, unsigned *numComparacoes){ 

    // If a árvore estiver vazia
    if(this->raiz == nullptr){ 

        // Aloca memória para a raiz
        this->raiz = new NoB(this->d, true); 
        this->raiz->chaves[0] = k;  // Insere a chave
        (*numTrocas)++;
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
            s->dividirFilho(0, this->raiz, numTrocas, numComparacoes); 
 
            // Nova raiz tem dois filhos agora
            // Escolhendo qual dos dois filhos terá uma nova chave
            int i = 0; 

            (*numComparacoes) += i;
            if(s->chaves[0] < k) 
                i++; 

            s->filhos[i]->inserirNaoCheio(k, numTrocas, numComparacoes); 

            // Muda a raiz
            this->raiz = s; 

        } 
        else  // Se a raiz não estiver cheia, chama inserir não cheio para a raiz
            this->raiz->inserirNaoCheio(k, numTrocas, numComparacoes); 

    }

}

// Função para remover uma chave da árvore
void ArvoreB::removerChave(int k, unsigned *numTrocas, unsigned *numComparacoes){ 

    if(!this->raiz){ 

        cout << "A árvore B esa vazia!\n"; 
        return; 

    } 
  
    // Chama a função de remover para a raiz 
    this->raiz->removerChave(k, numTrocas, numComparacoes); 

    // Se a raiz tiver 0 chaves, o primeiro filho se torna a nova raiz se a raiz tiver um filho
    // Caso contrário, seta raiz para nullprt
    if(this->raiz->n == 0){ 

        NoB *tmp = this->raiz; 
        if(this->raiz->folha) 
            this->raiz = nullptr; 

        else
            this->raiz = this->raiz->filhos[0]; 
  
        // Deleta a raiz antiga
        delete tmp; 

    } 

    return; 

} 