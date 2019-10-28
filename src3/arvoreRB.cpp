#include "arvoreRB.h"
#include "nodoRB.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#define RUB 1
#define PRET 0

using namespace std;

arvoreRB::arvoreRB()
{
    this->raiz = NULL;
}

nodoRB* arvoreRB::libera(nodoRB *aux)
{
    if(aux != NULL)
    {
        aux->setEsq(libera(aux->getEsq()));
        aux->setDir(libera(aux->getDir()));
        delete aux;
        aux = NULL;
    }
    return NULL;
}

arvoreRB::~arvoreRB()
{
    this->raiz = libera(this->raiz);
}

void arvoreRB::insereChave(int chave, string user)
{
    nodoRB *novo = new nodoRB(chave, user); //aloca novo nodo

    //se árvore vazia
    if(this->raiz == NULL)
        this->raiz = novo;
    //se não estiver vazia
    else
    {
        nodoRB *aux = this->raiz;
        while(aux != NULL)
        {
            if(chave < aux->getChave())
            {
                if(aux->getEsq() == NULL)
                {
                    aux->setEsq(novo);
                    novo->setPai(aux);
                    break;
                }
                aux = aux->getEsq();
            }
            else
            {
                if(aux->getDir() == NULL)
                {
                    aux->setDir(novo);
                    novo->setPai(aux);
                    break;
                }
                aux = aux->getDir();
            }
        }
    }
    //funções para verificar e fazer tanto balanceamento quanto recolorização
}


void arvoreRB::removeChave(int chave){
    //Busca o nó a ser removido
    nodoRB *v = busca(chave, this->raiz);
    // acha o nó que que substitui o nó deletado em uma BST 
    nodoRB *u = substituto(v); 
    // Verdadeiro quando u e v são pretos
    bool uvPreto = ((u == NULL || u->getCor() == PRET) && (v->getCor() == PRET)); 
    nodoRB *pai = v->getPai(); 
  
    if (u == NULL) { 
      // u é NULL então v é folha
      if (v == raiz) { 
        // v é raiz, torna a raiz nula
        raiz = NULL; 
      } else { 
        if (uvPreto) { 
          // u e v são pretos, se v é folha, conserta a dupla preta em v
          fixDoubleBlack(v); 
        }else { 
          // u ou v são vermelhos
          if (v->getIrmao() != NULL) 
            // sibling is not null, make it red" 
            v->getIrmao()->setCor = RUB; 
        } 
        // deleta v da arvore
        if (v == v->getPai()->getEsq()) { 
          pai->setEsq(NULL); 
        } else { 
          pai->setDir(NULL); 
        } 
      } 
      free(v); 
      return; 
    } else if (v->getEsq() == NULL || v->getDir() == NULL) { 
      // v tem um filho
      if (v == raiz) { 
        // v é raiz, passa o valor de u pra v, e exclui u 
        v->setChave(u->getChave()); 
        v->setUser(u->getUser());
        v->setEsq(NULL);
        v->setDir(NULL); 
        free(u); 
      } else { 
        // separa v da arvore e move u pra cima 
        if (v == v->getPai()->getEsq()) { 
          pai->setEsq(u); 
        } else { 
          pai->setDir(u); 
        } 
        free(v); 
        u->setPai(pai); 
        if (uvPreto) { 
          // u e v são pretos, conserta a dupla preta em u
          fixDoubleBlack(u); 
        } else { 
          // u ou v são vermelhos, u passa a ser preto
          u->setCor(PRET); 
        } 
      } 
      return; 
    } 
  
    // v tem dois filhos, troca os valores com o sucessor e chama a função recursivamente
    int auxChave;
    string auxUser; 
    auxChave = u->getChave();
    auxUser = u->getUser();
    u->setChave(v->getChave()); 
    u->setUser(v->getUser()); 
    v->setChave(auxChave); 
    v->setUser(auxUser); 
    removeChave(u->getChave()); 
}


//Rotação a esquerda
void arvoreRB::rotEsquerda(nodoRB *no) { 
    // novo pai vai ser o filho da direita do nó
    nodoRB *noPai = no->getDir(); 
  
    // atualiza a raiz se o nó atual for raiz 
    if (no == raiz) 
      raiz = noPai; 
  
    if (noPai->getPai() != NULL) { 
      if (noPai == noPai->getPai()->getEsq()) { 
        noPai->getPai()->setEsq(noPai); 
      } else { 
        noPai->getPai()->setDir(noPai); 
      } 
    } 
    noPai->setPai(noPai->getPai()); 
    noPai->getPai()->setPai(noPai); 
  
    // conecta o no com o novo elemento esquerdo do pai
    no->setDir(noPai->getEsq()); 
    // conecta o novo elemento esquerdo do pai com o nó
    // se ele não for nulo
    if (noPai->getEsq() != NULL) 
      noPai->getEsq()->setPai(no); 
  
    // liga o novo pai ao nó
    noPai->setEsq(no); 
  }

//rotação a direita
void arvoreRB::rotDireita(nodoRB *no) {
    // novo pai vai ser o filho esquerdo do nó
    nodoRB *noPai = no->getEsq(); 
  
    // atualiza a raiz se o no atual é raiz
    if (no == raiz) 
      raiz = noPai; 
  
    if (noPai->getPai() != NULL) { 
      if (noPai == noPai->getPai()->getEsq()) { 
        noPai->getPai()->setEsq(noPai); 
      } else { 
        noPai->getPai()->setDir(noPai); 
      } 
    } 
    noPai->setPai(noPai->getPai()); 
    noPai->getPai()->setPai(noPai);
  
    // connecta o nó com o novo elemento direito do pai
    no->setEsq(noPai->getDir()); 
    // conecta o novo elemento direito do pai com o nó
    // se ele não for nulo
    if (noPai->getDir() != NULL) 
      noPai->getDir()->setPai(no); 
  
    // coneca novo pai com x
    noPai->setDir(no); 
}

void arvoreRB::fixDoubleBlack(nodoRB *no){
    if (no == raiz) 
      // Reached root 
      return; 
  
    nodoRB *irmao = no->getIrmao();
    nodoRB *pai = no->getPai(); 
    if (irmao == NULL) { 
      // Sem irmão, dupla preta empurrada pra cima
      fixDoubleBlack(pai); 
    }else if (irmao->getCor() == RUB){ // Irmao vermelho 
        pai->setCor(RUB); 
        irmao->setCor(PRET); 
        //se o irmão for o da esquerda
        if (irmao == irmao->getPai()->getEsq()) {  
            rotDireita(pai); 
        }else { 
            rotEsquerda(pai); 
        } 
        fixDoubleBlack(no); 
    }else if ((irmao->getEsq() != NULL && irmao->getEsq()->getCor() == RUB) || 
              (irmao->getDir() != NULL && irmao->getDir()->getCor() == RUB)) { // Irmão preto 
        // pelo menos um filho vermelho
        if (irmao->getEsq() != NULL && irmao->getEsq()->getCor() == RUB) { 
            if (irmao == irmao->getPai()->getEsq()) { 
                // left left 
                irmao->getEsq()->setCor(irmao->getCor()); 
                irmao->setCor(pai->getCor()); 
                rotDireita(pai); 
            }else { 
                // right left 
                irmao->getEsq()->setCor(pai->getCor()); 
                rotDireita(irmao); 
                rotEsquerda(pai); 
            } 
        }else { 
            if (irmao == irmao->getPai()->getEsq()) { 
            // left right 
            irmao->getDir()->setCor(pai->getCor()); 
            rotEsquerda(irmao); 
            rotDireita(pai); 
            } else { 
            // right right 
            irmao->getDir()->setCor(irmao->getCor()); 
            irmao->setCor(pai->getCor()); 
            rotEsquerda(pai); 
            } 
        } 
        pai->setCor(PRET); 
    }else { 
        // 2 filhos pretos
        irmao->setCor(RUB); 
        if (pai->getCor() == PRET) 
            fixDoubleBlack(pai); 
        else
            pai->setCor(PRET); 
    } 
}

nodoRB* arvoreRB::busca(int chave, nodoRB *no){
    nodoRB *aux = no;
    if(no->getChave() == chave){
        return aux;
    }else if(no->getChave() > chave){
        aux = no->getDir();
    }else {
        aux = no->getEsq();
    }
    return busca(chave, aux);
}


nodoRB* arvoreRB::substituto(nodoRB *no){
    // quando o nó tem dois filhos
    if (no->getEsq() != NULL && no->getDir() != NULL) {
        nodoRB *aux = no;
        while (aux->getEsq() != NULL) 
            aux = aux->getEsq();

        return aux; 
     // quando o nó é folha 
    }else if (no->getEsq() == NULL && no->getDir() == NULL) {
        return NULL; 
    // quando o nó tem apenas um filho
    }else{
        if (no->getEsq() != NULL) 
            return no->getEsq(); 
        else
            return no->getDir(); 
    }
    
}