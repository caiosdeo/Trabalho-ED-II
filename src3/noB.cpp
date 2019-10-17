#include "noB.h"
#include<iostream>
using namespace std;

// Construtor
NoB::NoB(int d, bool folha) 
{ 
    // Inicializando os atributos ordem, folha e número de chaves
    this->d = d; 
    this->folha = folha; 
    this->n = 0;
 
    this->chaves = new int[2*d-1]; // Aloca memória para o número máximo de chaves
    this->filhos = new NoB *[2*d]; // Aloca memória para o número máximo de filhos 

} 

// Percorre os nós da subárvore
void NoB::percorrerSubarvore() {  
    // Existem n chaves e n + 1 fihos; percorre por n chaves e pelos primeiros n filhos
    int i; 
    for (i = 0; i < this->n; i++){ 
        
        // Se o nó não é folha, antes de imprimir a chaves[i] percorra a subárvore enraizada
        // com o filhos[i]
        if (this->folha == false) 
            this->filhos[i]->percorrerSubarvore(); 
        cout << " " << this->chaves[i]; 

    } 
  
    // Imprime a subárvore enraizada com o último filho 
    if (this->folha == false) 
        this->filhos[i]->percorrerSubarvore(); 

} 

// Function to search key k in subtree rooted with this node 
NoB *NoB::buscarChave(int k, unsigned *numAcessos, unsigned *numComparacoes){ 

    // Incrementa o número de acessos
    (*numAcessos)++;
    // Encontra a primeira chave maior ou igual a k
    int i = 0; 
    while(i < this->n && k > this->chaves[i]) 
        i++; 
    (*numComparacoes)+= i; // Incrementa número de comparações
    // Se a chave encontrada for igual a k, returna esse nó
    (*numComparacoes)++;
    if (this->chaves[i] == k) 
        return this; 
  
    // Se a chave não é encontrada aqui e o nó atual é folha
    if (this->folha == true) 
        return nullptr; 

    // Vai para o filho apropriado
    return this->filhos[i]->buscarChave(k, numAcessos, numComparacoes); 
    
} 