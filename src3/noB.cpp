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
NoB *NoB::buscarChave(int k, unsigned long long *numTrocas, unsigned long long *numComparacoes){ 

    // Incrementa o número de acessos
    (*numTrocas)++;
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
    return this->filhos[i]->buscarChave(k, numTrocas, numComparacoes); 
    
} 
 
// Função para inserir uma nova chave no nó.
// Essa função deve ser chamada quando o nó não está cheio
void NoB::inserirNaoCheio(int k, unsigned long long *numTrocas, unsigned long long *numComparacoes){ 

    // Inicializa com o índice do elemento mais à direita
    int i = this->n-1; 
  
    // Se for um nó folha
    if(this->folha == true){ 
        // O loop seguinte faz duas coisas: 
        // a) Encontra a localização da nova chave a ser inserida
        // b) Move todas as chaves maiores que k uma posição à frente
        while(i >= 0 && this->chaves[i] > k){ 

            this->chaves[i+1] = this->chaves[i];
            (*numTrocas)++;
            (*numComparacoes)++; 
            i--; 

        } 
  
        // Insere a nova chave na posição encontrada 
        this->chaves[i+1] = k; 
        (*numTrocas)++;
        this->n++;

    } 
    else{ // Se o nó não é folha
        // Encontra o filho que irá receber a nova chave
        while(i >= 0 && this->chaves[i] > k){

            (*numComparacoes)++; 
            i--;

        } 

        // Confere se o filho encontrado está cheio
        if(this->filhos[i+1]->n == 2*this->d-1){

            // Se o filho está cheeio
            this->dividirFilho(i+1, this->filhos[i+1], numTrocas, numComparacoes); 
   
            // Após dividir,  a chave do meio de filhos[i] sobe e
            // C[i] is splitted into two.  See which of the two 
            // filhos[i] é divido em dois. Confere qual dos dois irá receber a nova chave.
            (*numComparacoes)++;
            if(this->chaves[i+1] < k) 
                i++; 

        }

        this->filhos[i+1]->inserirNaoCheio(k, numTrocas, numComparacoes); 

    } 

} 
 
// Uma função para duvidir o filho y do nó.
// Essa função só deve ser chamada quando o filho estiver cheio
void NoB::dividirFilho(int i, NoB *y, unsigned long long *numTrocas, unsigned long long *numComparacoes){ 
    // Cria um novo nó para armazenar (d-1) chaves de y
    NoB *z = new NoB(y->d, y->folha); 
    z->n = this->d - 1; 
  
    // Copia as últimas (d-1) chaves de y para z
    for(int j = 0; j < this->d-1; j++){

        z->chaves[j] = y->chaves[j+this->d];
        (*numTrocas)++;

    } 
   
    // Copia o último d filho de y para z
    if(y->folha == false){ 

        for(int j = 0; j < this->d; j++){

            z->filhos[j] = y->filhos[j+this->d];
            (*numTrocas)++;
            
        }

    } 
  
    // Reduz o número de chaves em y 
    y->n = this->d - 1; 
 
    // Como o nó irá receber um novo filho, cria-se um espaço para o novo filho
    for(int j = this->n; j >= i+1; j--){

        this->filhos[j+1] = this->filhos[j];
        (*numTrocas)++;

    }
  
    // Agrega o novo filho ao nó
    this->filhos[i+1] = z; 
    (*numTrocas)++;
  
    // Uma chave de y irá mover para o nó. 
    // Encontrando a localização da nova chave e movendo todas as chaves maiores um espaço à frente
    for(int j = this->n-1; j >= i; j--){

        this->chaves[j+1] = this->chaves[j];
        (*numTrocas)++; 

    }
  
    // Copia a chave do meio de y para o nó
    this->chaves[i] = y->chaves[this->d-1]; 
    (*numTrocas)++; 
  
    // Incrementa o contador de chaves no nó
    this->n++;

}

// Retorna o índice da primeira chave maior ou igual a k
int NoB::encontrarChave(int k, unsigned long long *numTrocas, unsigned long long *numComparacoes){ 

    int id = 0; 
    while(id < this->n && this->chaves[id] < k) 
        ++id; 

    return id; 
     
} 
  
// Função para remover chave k do nó
void NoB::removerChave(int k, unsigned long long *numTrocas, unsigned long long *numComparacoes){ 

    int id = this->encontrarChave(k, numTrocas, numComparacoes); 
  
    // Confere se a chave a ser removida está presente no nó 
    (*numComparacoes)++;
    if(id < this->n && this->chaves[id] == k){ 
  
        // Se o nó é uma folha - chama removerDeFolha 
        // Caso contrário, chama removerDeNaoFolha
        if(this->folha) 
            this->removerDeFolha(id, numTrocas, numComparacoes); 

        else
            this->removerDeNaoFolha(id, numTrocas, numComparacoes); 

    } 
    else{ 
  
        // Se é um nó folha, então a chave não está presente na árvore B
        if(this->folha){ 

            cout << "A chave "<< k <<" não existe na árvore.\n"; 
            return; 

        } 
 
        // A chave a ser removida está presente na subárvore enraizada pelo nó
        // A bandeira indica se a chave está presente na subárvore que tem como raiz o último filho do nó 
        bool bandeira = ((id == this->n) ? true : false); 

        // Se o filho em que a chave deveria estar possui menos que d - 1 filhos, preenchemos esse filho
        if(this->filhos[id]->n < this->d) 
            this->preencher(id, numTrocas, numComparacoes); 
  
        // Se o último filho foi intercalado, ele deve ter sido intercalado com o filho anterior
        // Se foi, chamamos a função recursivamente no filho anterior
        // Se não foi, chamamos a função para o filho que deveria ter sido intercalado
        if (bandeira && id > this->n) 
            this->filhos[id-1]->removerChave(k, numTrocas, numComparacoes); 
        else
            this->filhos[id]->removerChave(k, numTrocas, numComparacoes); 

    } 

    return; 

} 
  
// Remove chave id de uma folha
void NoB::removerDeFolha(int id, unsigned long long *numTrocas, unsigned long long *numComparacoes){ 

    // Move todas as chaves uma posição após id 
    (*numTrocas) += this->n - id;
    for(int i = id + 1; i < this->n; ++i) 
        this->chaves[i-1] = this->chaves[i]; 
  
    // Decrementa o número de chaves
    this->n--; 
  
    return; 

} 
  
// Remove chave id de nó não-folha
void NoB::removerDeNaoFolha(int id, unsigned long long *numTrocas, unsigned long long *numComparacoes){ 
  
    int k = this->chaves[id];
    (*numTrocas)++; 

    // Se o filho predecessor tem pelo menos d chaves
    // Encontramos o predecessor na subárvore enraizada por filho[id]
    // Substituímos k pelo predecessor e deletamos o predecessor recursivamente em filho[id]
    if(this->filhos[id]->n >= this->d){ 

        int predecessor = this->getPredecessor(id, numTrocas, numComparacoes); 
        this->chaves[id] = predecessor; 
        (*numTrocas)++; 
        this->filhos[id]->removerChave(predecessor, numTrocas, numComparacoes); 

    } 

    // Se o filho filhos[id] tem pelo menos d chaves, examina-se filhos[id+1]
    // Se filhos[id+1] tem pelo menos d chaves, encontramos o sucessor na subárvore de filhos[id+1]
    // Substituímos a chave pelo sucessor
    // Deletamos recursivamente o sucessor em filhos[id+1]
    else if (this->filhos[id+1]->n >= this->d){ 

        int sucessor = getSucessor(id, numTrocas, numComparacoes); 
        this->chaves[id] = sucessor; 
        (*numTrocas)++; 
        this->filhos[id+1]->removerChave(sucessor, numTrocas, numComparacoes); 

    } 

    // Se ambos os filhos presentes na posição id e id + 1 tiverem d chaves
    // Intercalamos a chave e todas as chaves do filho id + 1 no filho id
    // Agora, o filho id contém 2d - 1 chaves
    // Deletamos o filho id + 1 e recursivamente deletamos k do filho id
    else{ 

        intercalar(id, numTrocas, numComparacoes); 
        this->filhos[id]->removerChave(k, numTrocas, numComparacoes); 

    } 

    return; 
    
} 

// Uma função para pegar o predecessor de chaves[id]
int NoB::getPredecessor(int id, unsigned long long *numTrocas, unsigned long long *numComparacoes){

    // Continua movendo para o nó mais à direita até chegar em uma folha
    NoB *atual = this->filhos[id]; 

    while(!atual->folha){

        atual = atual->filhos[atual->n]; 
        (*numTrocas)++;

    }
  
    // Retorna a última chave da folha
    return atual->chaves[atual->n-1]; 

} 

// Uma função para pegar o predecessor de chaves[id] 
int NoB::getSucessor(int id, unsigned long long *numTrocas, unsigned long long *numComparacoes){ 

    // Continua movendo até o nó mais à esquerda de filhos[id+1] até chegar em uma folha
    NoB *atual = this->filhos[id+1]; 

    while(!atual->folha){

        atual = atual->filhos[0];
        (*numTrocas)++;
        
    } 
  
    // Retorna a primeira chave da folha
    return atual->chaves[0]; 

} 

// Uma função para preencher o filho[id] que tem menos de d-1 chaves
void NoB::preencher(int id, unsigned long long *numTrocas, unsigned long long *numComparacoes){ 
   
    // Se o filho antecessor filhos[id-1] tiver mais de d-1 chaves
    // Pegar uma chave emprestada desse filho
    if(id != 0 && this->filhos[id-1]->n >= this->d) 
        this->pegarEmprestadoAnterior(id, numTrocas, numComparacoes);
  
    // Se o filho sucessor filhos[id+1] tiver mais de d-1 chaves
    // Pegar uma chave emprestada desse filho
    else if(id != this->n && this->filhos[id+1]->n >= this->d) 
        this->pegarEmprestadoProximo(id, numTrocas, numComparacoes); 
  
    // Intercala filhos[id] com seu irmão
    // Se filhos[id] é o último filho, intercala com seu irmão antecessor
    // Caso contrário, intercala com seu irmão sucessor
    else{ 

        if(id != this->n) 
            this->intercalar(id, numTrocas, numComparacoes); 
        else
            this->intercalar(id-1, numTrocas, numComparacoes);

    } 

    return; 

} 
  
// Uma função para pegar emprestado a chave do filhos[id-1] e inserir no filhos[id]
void NoB::pegarEmprestadoAnterior(int id, unsigned long long *numTrocas, unsigned long long *numComparacoes){ 
  
    NoB *filho = this->filhos[id]; 
    NoB *irmao = this->filhos[id-1]; 
 
    // A última chave de filhos[id-1] sobe para o pai e a chaves[id-1] do pai
    // é inserida como primeira chave em filhos[id]
    // O irmão perde uma chave e o filho ganha uma chave
    // Move todas as chaves de filhos[id] um passo à frente
    for (int i = filho->n-1; i >= 0; --i) 
        filho->chaves[i+1] = filho->chaves[i];
    (*numTrocas) += filho->n - 1; 

    // Se filhos[id] não pe uma folha, move todos os filhos um passo à frente
    if(!filho->folha){

        for(int i = filho->n; i >= 0; --i) 
            filho->filhos[i+1] = filho->filhos[i];
        (*numTrocas) += filho->n; 

    } 

    // Setando a primeira chave do filho igual à chaves[id-1] do nó nó atual
    filho->chaves[0] = this->chaves[id-1]; 
    (*numTrocas)++; 

    // Movendo o último filho do irmão como primeiro filho de filhos[id] do nó atual
    if(!filho->folha) 
        filho->filhos[0] = irmao->filhos[irmao->n];
    (*numTrocas)++;  

    // Movendo a chave do irmão para o pai
    // Isso reduz o número de chaves no irmão
    this->chaves[id-1] = irmao->chaves[irmao->n-1];
    (*numTrocas)++;  
  
    filho->n++; 
    irmao->n--; 
  
    return; 

} 
  
// Uma função para pegar emprestado a chave do filhos[id+1] e inserir no filhos[id] 
void NoB::pegarEmprestadoProximo(int id, unsigned long long *numTrocas, unsigned long long *numComparacoes){ 
  
    NoB *filho = this->filhos[id]; 
    NoB *irmao = this->filhos[id+1]; 

    // chaves[id] é inserida como última chave em filhos[id]
    filho->chaves[(filho->n)] = this->chaves[id]; 
    (*numTrocas)++; 
 
    // Primeiro filho do irmão é inserido como último filho em filhos[id]
    if(!(filho->folha)) 
        filho->filhos[(filho->n)+1] = irmao->filhos[0]; 
    (*numTrocas)++; 

    // A primeira chave do irmão é inserida em chaves[id]
    this->chaves[id] = irmao->chaves[0]; 
    (*numTrocas)++; 

    // Movendo todas as chaves do irmão uma posição para trás 
    for(int i = 1; i < irmao->n; ++i) 
        irmao->chaves[i-1] = irmao->chaves[i]; 
    (*numTrocas) += irmao->n;

  
    // Movendo tods os filhos do irmão uma posição para trás 
    if(!irmao->folha){ 

        for(int i = 1; i <= irmao->n; ++i) 
            irmao->filhos[i-1] = irmao->filhos[i]; 
        (*numTrocas) += irmao->n;

    } 
 
    // Incrementando e decrementando o contador de chaves de filhos[id] e filhos[id+1]
    filho->n++; 
    irmao->n--; 
  
    return; 

} 
  
// Função para intercalar filhos[id] com filhos[id+1] 
// filhos[id+1] é desalocado depois da intercalação
void NoB::intercalar(int id, unsigned long long *numTrocas, unsigned long long *numComparacoes){ 

    NoB *filho = this->filhos[id]; 
    NoB *irmao = this->filhos[id+1]; 

    // Puxando a chave do nó atual e inserindo  na posição (d-1) de filhos[id]
    filho->chaves[this->d-1] = chaves[id]; 
    (*numTrocas)++; 

    // Copiando as chaves de filhos[id+1] para filhos[id] no final
    for(int i = 0; i < irmao->n; ++i) 
        filho->chaves[i+this->d] = irmao->chaves[i]; 
    (*numTrocas) += irmao->n;
  
    // Copiando os ponteiros de filho de filhos[id+1] para filhos[id] 
    if(!filho->folha){ 

        for(int i = 0; i <= irmao->n; ++i) 
            filho->filhos[i+this->d] = irmao->filhos[i];
        (*numTrocas) += irmao->n + 1;

    } 

    // Movendo todas as chaves depois de id no nó atual uma posição atrás
    // antes de preencher a lacuna criada pela movimentação de chaves[id] para filhos[id]
    for(int i = id+1; i < this->n; ++i) 
        this->chaves[i-1] = this->chaves[i];
    (*numTrocas) += this->n - id; 

    // Movendo os ponteiros de filhos depois de id+1 do nó atual uma posição atrás
    for(int i = id + 2;  i <= this->n; ++i) 
        this->filhos[i-1] = this->filhos[i]; 
    (*numTrocas) += this->n - id - 1; 
  
    // Atualizando o contador de filhos dos nós
    filho->n += irmao->n+1; 
    this->n--; 

    // Desalocando memória ocupada pelo irmão 
    delete(irmao); 
    return; 

} 