#include <stdio.h>
#include "hashEncadCoal.h"
#include "noHashCoal.h"

using namespace std;

hashEncadCoal::hashEncadCoal(unsigned numeroChaves)
{
    this->numeroChaves = numeroChaves;

    this->inicio = NULL;
    this->ultimo = NULL;

}

hashEncadCoal::~hashEncadCoal()
{
    noHashCoal *p = this->inicio;
    while(p != NULL)
    {
       noHashCoal *q = p->getProx();
       delete p;
       p = q;
    }
}

unsigned hashEncadCoal::funcaoHash(unsigned chave)
{
    return (chave % this->numeroChaves);
}

noHashCoal* hashEncadCoal::getPosicao(unsigned ind, noHashCoal *crash)
{
    noHashCoal *p = this->inicio, *r = p->getProx();
    for( ; r != NULL; p = r, r = r->getProx())
    {
        if(p->getIndice() == ind)
        {
            crash = p;
            return NULL;
        }
        if(p->getIndice() < ind && ind < r->getIndice())
            return p;
    }
    return p;
}

void hashEncadCoal::insereItem(unsigned chave, unsigned *countColisoes)
{
    noHashCoal *p = new noHashCoal();
    p->setInfo(chave);
    p->setColisao(NULL);
    /// verifica se primeira posicao esta vazia
    if(this->inicio == NULL)
    {
        p->setIndice(0);
        p->setProx(NULL);
        p->setPrev(NULL);
        this->inicio = p;
        this->ultimo = p;
    }
    else
    {
        unsigned indice = funcaoHash(chave);
        noHashCoal *crash = NULL;
        noHashCoal *aux = getPosicao(indice, crash); // procura por proxima posicao dada pelo indice, se possivel
        if(crash == NULL) // caso nao houver colisao
        {
            p->setIndice(indice); //insere o indice
            noHashCoal *q = aux->getProx();
            aux->setProx(p);
            p->setPrev(aux);
            p->setProx(q);
            if(q != NULL)
                q->setPrev(p);
            if(aux == this->ultimo)
            {
                this->ultimo = p;
            }
        }
        else
        {
            (*countColisoes)++;
            if(crash->getColisao() == NULL) // se nao aconteceu antes
            {
                aux = this->ultimo;
                if(aux->getIndice() != this->numeroChaves-1) //verifica se ultima posicao da tabela esta vazia
                {
                    p->setProx(NULL);
                    p->getIndice();
                    aux->setProx(p);
                    this->ultimo = p;
                }
                else
                {
                    noHashCoal *q = aux->getPrev();
                    for(unsigned i = this->numeroChaves-1; i > 0; i++, aux = q, q = q->getPrev()) //procura proxima posicao livre a partir do final
                    {
                        if(q->getIndice() < i && i < aux->getIndice())
                        {
                            p->setIndice(i);
                            p->setPrev(q);
                            p->setProx(aux);
                        }
                    }
                }
            }
            else
            {
                noHashCoal *aux = crash->getColisao(), *q;
                while(aux != NULL) //procura pela ultima colisao
                    aux = aux->getColisao();
                crash = aux;
                q = aux->getPrev();
                for(unsigned i = this->numeroChaves; i > 0; i++, aux = q, q = q->getPrev()) // busca posicao livre a partir da ultima colisao
                {
                    if(q->getIndice() < i && i < aux->getIndice())
                    {
                            p->setIndice(i);
                            p->setPrev(q);
                            p->setProx(aux);
                    }
                }
            }
            crash->setColisao(p); //insere posicao da colisao
        }
    }
}


void hashEncadCoal::removeItem(unsigned chave)
{
    unsigned indice = funcaoHash(chave);
    for(noHashCoal *p = this->inicio; p != NULL; p = p->getProx())
    {
        noHashCoal *q = p->getColisao();
        while(q != NULL)
        {
            if(q->getIndice() == indice)
            {
                p->setColisao(q->getColisao());

                q = NULL;
            }
            p = q;
            q = q->getColisao();
        }
    }
    for(noHashCoal *atual = this->inicio, *prox = atual->getProx(); prox != NULL; atual = prox, prox = prox->getProx())
    {
        if(indice == prox->getIndice())
        {
            noHashCoal *aux = prox->getProx();
            atual->setProx(aux);
            aux->setPrev(atual);

            delete prox;
        }
    }
}
