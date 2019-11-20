#include "arvoreRB.h"
#include "nodoRB.h"
#include <iostream>
#define VER 1 // define para cor vermelha
#define PRET 0 // define para cor preta

using namespace std;
// Construtor (Inicializando a árvore RB como vazia)
ArvoreRB::ArvoreRB()
{
    this->raiz = nullptr;
}

// função de inserção da informação de campo Id
void ArvoreRB::insereChave(int chave, unsigned long long *numTrocas, unsigned long long *numComp)
{
    NodoRB *novo = new NodoRB(chave); // aloca novo nó
    (*numTrocas)++; // incrementa número de acessos 
    //se árvore vazia
    if(this->raiz == nullptr)
        {
            novo->setCor(PRET); // propriedade: raiz sempre preta
            this->raiz = novo; // raiz recebe novo nó
        }
    // se árvore não estiver vazia
    else
    {
        NodoRB *aux = this->raiz;// nó auxiliar para busca de posição
        while(aux != nullptr) // enquanto aux for diferente de nullptr
        {
            (*numComp)++; // incrementa número de comparações
            // se chave for menor que valor da chave de aux
            if(chave < aux->getChave())
            {
                // se filho a esquerda for nullptr
                if(aux->getEsq() == nullptr)
                {
                    aux->setEsq(novo); // seta novo como filho a esquerda
                    novo->setPai(aux); // seta auxiliar como pai
                    break; // para while
                }
                aux = aux->getEsq(); // atualiza auxiliar
            }
            else // se não for menor
            {
                // se filho a direita for nullptr
                if(aux->getDir() == nullptr)
                {
                    aux->setDir(novo); // seta novo como filho a direita
                    novo->setPai(aux); // seta auxiliar como pai
                    break; // para while
                }
                aux = aux->getDir(); // atualiza auxiliar
            }
        }
    }
    //funções para verificar e fazer tanto balanceamento quanto recolorização
    balancearInsercao(novo);
}
// função para chamada das funções de verificação dos casos de recolorir e balancear
void ArvoreRB::balancearInsercao(NodoRB *x)
{
    // caso x não é raiz
    if(x != this->raiz)
    {
        NodoRB *auxPai = x->getPai(); // nó auxiliar para pai
        // se pai diferente de nullptr e sua cor diferente de preto
        if(auxPai != nullptr && auxPai->getCor() != PRET)
        {
            // se nenhum dos casos de recolorir ocorrer
            if(!recolorir(x))
            {
                auxBalancear(x, auxPai); // função auxiliar de balanceamento
            }
        }
    }
}
// função de verificação para caso recolorir
bool ArvoreRB::recolorir(NodoRB *x)
{
    NodoRB *auxPai = x->getPai(); // nó para pai
    if(this->raiz->getCor() == VER) this->raiz->setCor(PRET);
    NodoRB *avo = auxPai->getPai(), *tio; // nós para avo e tio
    // caso pai não seja nó a esquerda do avo
    if(avo->getEsq() != auxPai)
        tio = avo->getEsq(); // tio é o nó a esquerda
    // se não
    else
        tio = avo->getDir(); // tio é o nó a direita
    if(tio != nullptr && tio->getCor() != PRET) // se tio não for nullptr (nullptr considerado cor preta) e nem preto
    {
        auxRecolorir(x); // função de recolorir auxiliar
        return true;
    }
    return false;
}
// função de recolorir auxiliar
void ArvoreRB::auxRecolorir(NodoRB *x)
{
    NodoRB *auxPai = x->getPai(), *auxAvo, *auxTio; //nós auxiliares para pai, avo e tio
    // caso pai não seja nullptr
    if(auxPai != nullptr)
    {
        auxPai->setCor(PRET); // seta cor do pai como preta
        auxAvo = auxPai->getPai();
        // se avo não é nullptr
        if(auxAvo != nullptr)
        {
            auxAvo->setCor(VER); // seta cor do avo como vermelha
            // se filho a esquerda do avo não for pai
            if(auxAvo->getEsq() != auxPai)
                auxTio = auxAvo->getEsq(); // tio a esquerda
            else
                auxTio = auxAvo->getDir(); // tio a direita
            // se tio diferente de nullptr
            if(auxTio != nullptr)
                auxTio->setCor(PRET); // seta cor do tio como preto
            auxRecolorir(auxAvo); // chama função recolorir auxiliar passando avo como referência
        }
    }
}
// função balancear auxliar
void ArvoreRB::auxBalancear(NodoRB *x, NodoRB *auxPai)
{
    NodoRB *auxAvo = auxPai->getPai(); // nó para avo
    // caso Direita-Direita
    if(auxAvo->getDir() == auxPai && auxPai->getDir() == x)
    {
        rotacaoEsq(auxPai, auxAvo);
        auxPai->setCor(PRET);
        auxAvo->setCor(VER);
    }
    // caso Esquerda-Esquerda
    if(auxAvo->getEsq() == auxPai && auxPai->getEsq() == x)
    {
        rotacaoDir(auxPai, auxAvo);
        auxPai->setCor(PRET);
        auxAvo->setCor(VER);
    }
    // caso Esquerda-Direita
    if(auxAvo->getEsq() == auxPai && auxPai->getDir() == x)
    {
        rotacaoEsq(x, auxPai);
        rotacaoDir(x, auxAvo);
        x->setCor(PRET);
        x->getDir()->setCor(VER);
    }
    // caso Direita-Esquerda
    if(auxAvo->getDir() == auxPai && auxPai->getEsq() == x)
    {
        rotacaoDir(x, auxPai);
        rotacaoEsq(x, auxAvo);
        x->setCor(PRET);
        auxAvo->setCor(VER);
    }
}
//Função de rotação à esquerda
void ArvoreRB::rotacaoEsq(NodoRB *x, NodoRB *pai)
{
    NodoRB *auxAvo = pai->getPai(); // nó para avo
    // se avo diferente de nullptr
    if(auxAvo != nullptr)
    {
        // se pai está a esquerda do avo
        if(auxAvo->getEsq() == pai)
            auxAvo->setEsq(x); // seta x a esquerda do avo
        else
            auxAvo->setDir(x); // seta x a direita do avo
    }
    x->setPai(auxAvo);
    pai->setPai(x);
    pai->setDir(x->getEsq());
    x->setEsq(pai);
    // se pai era a raiz
    if(pai == this->raiz)
        this->raiz = x; // raiz agora é x
}
//Função de rotação à direita
void ArvoreRB::rotacaoDir(NodoRB *x, NodoRB *pai)
{
    NodoRB *auxAvo = pai->getPai(); // nó para avo
    //se avo diferente de nullptr
    if(auxAvo != nullptr)
    {
        // se pai está a esquerda do avo
        if(auxAvo->getEsq() == pai)
            auxAvo->setEsq(x); // seta x a esquerda do avo
        else
            auxAvo->setDir(x); // seta x a direita do avo
    }
    x->setPai(auxAvo); // seta avo como pai de x
    pai->setPai(x); // seta x como pai de pai
    pai->setEsq(x->getDir()); // seta direita de x a esquerda de pai
    x->setDir(pai); // seta pai a direita de x
    // se pai era raiz
    if(pai == this->raiz)
        this->raiz = x; // raiz agora é x
}
// função de busca para chave X
NodoRB* ArvoreRB::busca(int chave, NodoRB *no, unsigned long long *numTrocas, unsigned long long *numComparacoes){
    if(no->getChave() == chave){
        (*numComparacoes)++;
        return no;
    }else if(no->getChave() < chave && no != nullptr){
        (*numComparacoes)++;
        return busca(chave, no->getDir(), numTrocas, numComparacoes);
    }else if(no->getChave() > chave && no != nullptr){
        (*numComparacoes)++;
        return busca(chave, no->getEsq(), numTrocas, numComparacoes);
    }else{
        return no;
    }
}

NodoRB* ArvoreRB::getRaiz(){
    return this->raiz;
}
