#include <stdio.h>
#include "hashEncadCoal.h"

using namespace std;

hashEncadCoal::hashEncadCoal(unsigned numeroChaves)
{
    this->numeroChaves = numeroChaves;

    this->tabela = new unsigned[numeroChaves];
    this->colisoes = new unsigned[numeroChaves];

    for(int i = 0; i < numeroChaves; i++){
        this->tabela[i] = -1;
        this->colisoes[i] = -1; 
    }
    

}

hashEncadCoal::~hashEncadCoal(){

    delete [] tabela;
    delete [] colisoes;

}

unsigned hashEncadCoal::funcaoHash(unsigned chave)
{
    return (chave % this->numeroChaves);
}

unsigned hashEncadCoal::getIndiceColisao(unsigned indice){

    // Mantendo propriedade de encadeamento
    // Procurando a entre colisoes a colisão vazia

    int proxColisao = this->colisoes[indice];

    for(; this->colisoes[proxColisao] == -1; proxColisao = this->colisoes[proxColisao]);

    return proxColisao;
}

void hashEncadCoal::insereItem(unsigned chave, unsigned *countColisoes)
{
    
    unsigned indice = funcaoHash(chave);

    if(this->tabela[indice] == -1) // -1 identifica posição vazia
        this->tabela[indice] = chave;

    else{

        (*countColisoes)++;

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
