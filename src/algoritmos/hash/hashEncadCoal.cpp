#include "hashEncadCoal.h"
#include "NoHash.h"

using namespace std;

hashEncadCoal::hashEncadCoal(int numeroChaves)
{
    this->numeroChaves = numeroChaves;

    this->inicio = NULL;
    this->inicio->setColisao(NULL);

    this->ultimo = NULL;
    this->ultimo->setColisao(NULL);

    this->numItens = 0;
}

hashEncadCoal::~hashEncadCoal()
{
    NoHash *p = this->inicio;
    while(p != NULL)
    {
       NoHash *q = p->getProx();
       delete p;
       p = q;
    }
}

int hashEncadCoal::funcaoHash(int chave)
{
    return (chave % this->numeroChaves);
}

NoHash* hashEncadCoal::getPosicao(int ind, NoHash *crash)
{
    NoHash *p = this->inicio, *r = p->getProx();
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

void hashEncadCoal::insereItem(int chave)
{
    NoHash *p = new NoHash();
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
        int indice = funcaoHash(chave);
        NoHash *crash = NULL;
        NoHash *aux = getPosicao(indice, crash); /// procura por proxima posicao dada pelo indice, se possivel
        if(crash == NULL) // caso nao houver colisao
        {
            p->setIndice(indice); //insere o indice
            NoHash *q = aux->getProx();
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
            if(crash->getColisao() == NULL) // se nao aconteceu antes
            {
                aux = this->ultimo;
                if(aux->getIndice() != this->numeroChaves-1) //verifica se ultima posicao da tabela esta vazia
                {
                    p->setProx(NULL);
                    p->getIndice(this->numeroChaves-1);
                    aux->setProx(p);
                    this->ultimo = p;
                }
                else
                {
                    NoHash *q = aux->getPrev();
                    for(int i = this->numeroChaves-1; i > 0; i++, aux = q, q = q->getPrev()) //procura proxima posicao livre a partir do final
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
                NoHash *aux = crash->getColisao(), *q;
                while(aux != NULL) //procura pela ultima colisao
                    aux = aux->getColisao();
                crash = aux;
                q = aux->getPrev();
                for(int i = this->numeroChaves; i > 0; i++, aux = q, q = q->getPrev()) // busca posicao livre a partir da ultima colisao
                {
                    if(q->getIndice() < i && i < aux->getIndice())
                    {
                            p->setIndice(i);
                            p->setPrev(q);
                            p->setProx(aux);
                    }
                }
            }
            crash->setColisao(p); ///insere posicao da colisao
        }
    }
}



void hashEncadCoal::removeItem(int chave)
{
    int indice = funcaoHash(chave);
    for(NoHash *p = this->inicial; p != NULL; p = p->getProx())
    {
        NoHash *q = p->getColisao();
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
    for(NoHash *atual = this->inicio, *prox = atual->getProx(); prox != NULL; atual = prox, prox = prox->getProx())
    {
        if(indice == prox->getIndice())
        {
            NoHash *aux = prox->getProx();
            atual->setProx(aux);
            aux->setPrev(atual);

            delete prox;
        }
    }
}
