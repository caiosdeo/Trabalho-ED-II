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
    noHashCoal *del = this->inicio;//ponteiro para deletar a partir do primeiro No
    while(p != NULL)
    {
       noHashCoal *aux = del->getProx(); //ponteiro auxiliar para proximo a deletar
       delete del;
       del = aux; //deletar recebe auxilio
    }
}

//funcao hash
unsigned hashEncadCoal::funcaoHash(unsigned chave)
{
    return (chave % this->numeroChaves);
}

//funcao de busca posicao de acordo com indice
noHashCoal* hashEncadCoal::getPosicao(unsigned ind, noHashCoal *crash)
{
    noHashCoal *atual, *prox;// ponteiros atual e proximo
    for(atual = this->inicio, prox = p->getProx(); prox != NULL; atual = prox, prox = prox->getProx())
    {
        if(atual->getIndice() == ind) //verifica se houve colisao
        {
            crash = atual; //caso de colisao recebe posicao atual
            return NULL;
        }
        if(p->getIndice() < ind && ind < prox->getIndice()) //verifica se indice esta entre atual e proximo
            return atual; //retorna atual
    }
    return atual; //returna ultimo
}

//funcao de insercao de itens (chaves) usando metodo coalescido encadiado e funcao hash
void hashEncadCoal::insereItem(unsigned chave, unsigned long *countColisoes)
{
    noHashCoal *novoNo = new noHashCoal();//ponteiro para novo No
    novoNo->setInfo(chave);
    novoNo->setColisao(NULL);
    // verifica se primeira posicao esta vazia
    if(this->inicio == NULL)
    {
        novoNo->setIndice(0);
        novoNo->setProx(NULL);
        novoNo->setPrev(NULL);
        this->inicio = novoNo;
        this->ultimo = novoNo;
    }
    else
    {
        unsigned indice = funcaoHash(chave);
        noHashCoal *crash = NULL; //ponteiro para caso de colisao
        noHashCoal *aux = getPosicao(indice, crash); //ponteiro de auxilio (aux) para procura da proxima posicao, se estiver disponivel
        if(crash == NULL) // caso nao houver colisao
        {
            novoNo->setIndice(indice); //insere o indice no novo No
            noHashCoal *prox = aux->getProx(); //ponteiro para proximo elemento do auxiliar
            aux->setProx(novoNo);//armazena novo No como proximo do auxiliar
            novoNo->setPrev(aux);//armazena auxiliar como anterior do novo No
            novoNo->setProx(prox);//armazena proximo elemento como proximo de novo No
            if(prox != NULL) //se proximo existir
                prox->setPrev(novoNo); // armazena novo No como anterior de proximo
            if(aux == this->ultimo) //se auxiliar for ultimo No
            {
                this->ultimo = novoNo; //ultimo recebe novo No
            }
        }
        else
        {
            (*countColisoes)++; //acrescenta contador de colisoes

            if(crash->getColisao() == NULL) //se nao aconteceu colisao antes
            {
                aux = this->ultimo; // ponteiro auxiliar recebe ultimo No
                if(aux->getIndice() != this->numeroChaves-1) //verifica se ultima posicao da tabela esta vazia
                {
                    novoNo->setProx(NULL); //nao ha mais elementos como proximos
                    novoNo->setIndice(this->numeroChaves-1); //armazena indice da ultima posicao
                    aux->setProx(novoNo); //armazena novo No como proximo de auxiliar
                    this->ultimo = novoNo; //ultimo recebe novo No
                }
                else
                {
                    noHashCoal *ant = aux->getPrev(); //no para anterior do auxiliar
                    for(unsigned i = this->numeroChaves-1; i > 0; i++, aux = q, q = q->getPrev()) //procura proxima posicao livre a partir do ultimo
                    {
                        if(q->getIndice() < i && i < aux->getIndice())//verifica se ha espaco entre os indices do auxiliar e seu anterior
                        {
                            novoNo->setIndice(i); //armazena indice i
                            novoNo->setPrev(ant); // armazena ant como anterior de novo No
                            novoNo->setProx(aux); // armazena auxiliar como proximo de  novo No
                            break;
                        }
                    }
                }
            }
            else
            {
                aux = crash->getColisao();//auxiliar recebe colisao
                noHashCoal *ant; //ponteiro para posicao anterior ao auxiliar
                while(aux->getColisao() != NULL) //procura pela ultima colisao
                    aux = aux->getColisao();
                crash = aux;
                ant = aux->getPrev();
                for(unsigned i = this->numeroChaves; i > 0; i++, aux = prox, prox = prox->getPrev()) // busca posicao livre a partir da ultima colisao
                {
                    if(ant->getIndice() < i && i < aux->getIndice())//se indice i esta entre o auxiliar e seu anterior
                    {
                            novoNo->setIndice(i);
                            novoNo->setPrev(ant);
                            novoNo->setProx(aux);
                            break;
                    }
                }
            }
            crash->setColisao(novoNo); //insere novo No como colidido
        }
    }
}

//funcao de remocao de item
void hashEncadCoal::removeItem(unsigned chave)
{
    unsigned indice = funcaoHash(chave);
    noHashCoal *atual;
    for(atual = this->inicio; atual != NULL; atual = atual->getProx())
    {
        noHashCoal *colidido = atual, *colidiu = colidido->getColisao();
        while(colidiu != NULL)
        {
            if(colidiu->getIndice() == indice) //se proximo for o item a ser deletado
            {
                colidido->setColisao(colidiu->getColisao());
                atual = colidiu;
                break;
            }
            colidido = colidiu;
            colidiu = colidiu->getColisao();
        }
        if(atual->getIndice() == indice)
        {
            noHashCoal *ant = atual->getPrev(), *prox = atual->getProx();
            ant->setProx(prox);
            prox->setPrev(ant);
            delete atual;
            break;
        }
    }
}
