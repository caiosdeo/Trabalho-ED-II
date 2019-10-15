#include <stdio.h>
#include "hashEncadCoal.h"

using namespace std;

/**
 * Construtor
 *
 * @author caiosdeo
 * @param numeroChaves quantidade de chaves que a tabela irá suportar
 */
hashEncadCoal::hashEncadCoal(unsigned numeroChaves){
    this->numeroChaves = numeroChaves;

    this->tabela = new unsigned[numeroChaves];
    this->colisoes = new unsigned[numeroChaves];


    // Inicializando os vetores com -1 para indicar posição vazia
    for(int i = 0; i < numeroChaves; i++){
        this->tabela[i] = -1;
        this->colisoes[i] = -1; 
    }

}

/**
 * Destrutor da Hash
 *
 * @author caiosdeo
 */
hashEncadCoal::~hashEncadCoal(){

    delete [] tabela;
    delete [] colisoes;

}

/**
 * Função para retornar o indice da chave na tabela hash
 *
 * @author caiosdeo
 * @param chave chave para inserção na tabela
 * @return indice posição na tabela hash
 */
unsigned hashEncadCoal::funcaoHash(unsigned chave){
    return (chave % this->numeroChaves);
}

/**
 * Função para retornar o indice do elemento que tem que apontar para o que colidiu
 *
 * @author caiosdeo
 * @param indice indice da colisao
 * @return proxColisao posição na tabela hash do elemento que deve apontar para o colidido
 */
unsigned hashEncadCoal::getIndiceColisao(unsigned indice){

    // Mantendo propriedade de encadeamento
    // Procurando a entre colisoes a colisão vazia

    int proxColisao = this->colisoes[indice];

    for(; this->colisoes[proxColisao] == -1; proxColisao = this->colisoes[proxColisao]);

    return proxColisao;
}


/**
 * Função de inserção de uma chave na tabela hash
 *
 * @author caiosdeo
 * @param chave chave para que deseja inserir na tabela
 * @param countColisoes contador de colisoes externo
 */
void hashEncadCoal::insereItem(unsigned chave, unsigned *countColisoes){
    
    // Retornando indice para a tabela
    unsigned indice = funcaoHash(chave);

    if(this->tabela[indice] == -1) // -1 identifica posição vazia
        this->tabela[indice] = chave;

    else{ // Caso ocorra a colisão

        (*countColisoes)++; // Contando a colisão

        if(this->colisoes[indice] == -1){ // Primeira colisão

            //Procurando posição vazia de trás para frente
            for(int i = this->numeroChaves; i >= 0; i--) 
                
                if(this->tabela[i] == -1){ 

                    this->tabela[i] = chave;
                    
                    this->colisoes[indice] = i;
                
                }

        }else{ // Já houve uma colisão

            //Procurando posição vazia de trás para frente
            for(int i = this->numeroChaves; i >= 0; i--) 
                if(this->tabela[i] == -1){ 

                    this->tabela[i] = chave;

                    unsigned indiceColisao = this->getIndiceColisao(indice);

                    this->colisoes[indiceColisao] = i;
           
                }

        }

    }

}
