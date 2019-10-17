#include "noB.h"
#include<iostream>
using namespace std;

// Construtor
NoB::NoB(int d, bool folha){ 
    // Inicializando os atributos ordem, folha e número de chaves
    this->d = d; 
    this->folha = folha; 
    this->n = 0;
 
    this->chaves = new int[2*d-1]; // Aloca memória para o número máximo de chaves
    this->filhos = new NoB *[2*d]; // Aloca memória para o número máximo de filhos 

} 

// Percorre os nós da subárvore
void NoB::percorrerSubarvore(){  
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
 
// Função para inserir uma nova chave no nó.
// Essa função deve ser chamada quando o nó não está cheio
void NoB::inserirNaoCheio(int k){ 

    // Inicializa com o índice do elemento mais à direita
    int i = this->n-1; 
  
    // Se for um nó folha
    if(this->folha == true){ 
        // O loop seguinte faz duas coisas: 
        // a) Encontra a localização da nova chave a ser inserida
        // b) Move todas as chaves maiores que k uma posição à frente
        while(i >= 0 && this->chaves[i] > k){ 

            this->chaves[i+1] = this->chaves[i]; 
            i--; 

        } 
  
        // Insere a nova chave na posição encontrada 
        this->chaves[i+1] = k; 
        this->n++;

    } 
    else{ // Se o nó não é folha
        // Encontra o filho que irá receber a nova chave
        while (i >= 0 && this->chaves[i] > k) 
            i--; 
  
        // See if the found child is full 
        // Confere se o filho encontrado está cheio
        if(this->filhos[i+1]->n == 2*this->d-1){

            // Se o filho está cheeio
            this->dividirFilho(i+1, this->filhos[i+1]); 
  
            // After split, the middle key of C[i] goes up and 
            // Após dividir,  a chave do meio de filhos[i] sobe e
            // C[i] is splitted into two.  See which of the two 
            // filhos[i] é divido em dois. Confere qual dos dois irá receber a nova chave.
            if (this->chaves[i+1] < k) 
                i++; 

        }

        this->filhos[i+1]->inserirNaoCheio(k); 

    } 

} 
 
// Uma função para duvudur o filho y do nó.
// Essa função só deve ser cjamada quando o filho estiver cheio
void NoB::dividirFilho(int i, NoB *y){ 
    // Cria um novo nó para armazenar (d-1) chaves de y
    NoB *z = new NoB(y->d, y->folha); 
    z->n = this->d - 1; 
  
    // Copia as últimas (d-1) chaves de y para z
    for(int j = 0; j < this->d-1; j++) 
        z->chaves[j] = y->chaves[j+this->d]; 
   
    // Copia o último d filho de y para z
    if(y->folha == false){ 
        for(int j = 0; j < this->d; j++) 
            z->filhos[j] = y->filhos[j+this->d]; 
    } 
  
    // Reduz o número de chaves em y 
    y->n = this->d - 1; 
 
    // Como o nó irá receber um novo filho, cria-se um espaço para o novo filho
    for(int j = this->n; j >= i+1; j--) 
        this->filhos[j+1] = this->filhos[j]; 
  
    // Agrega o novo filho ao nó
    this->filhos[i+1] = z; 
  
    // Uma chave de y irá mover para o nó. 
    // Encontrando a localização da nova chave e movendo todas as chaves maiores um espaço à frente
    for(int j = this->n-1; j >= i; j--) 
        this->chaves[j+1] = this->chaves[j]; 
  
    // Copia a chave do meio de y para o nó
    this->chaves[i] = y->chaves[this->d-1]; 
  
    // Incrementa o contador de chaves no nó
    this->n++;

}