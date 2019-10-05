#ifndef NOHASHCOAL_H
#define NOHASHCOAL_H

class noHashCoal
{
    public:
        noHashCoal(){};
        ~noHashCoal(){};

        unsigned getInfo(){return this->chave;};
        unsigned getIndice(){return this->indice;};
        noHashCoal* getProx(){return this->next;};
        noHashCoal* getPrev(){return this->prev;};
        noHashCoal* getColisao() {return this->colisao;};

        void setProx(noHashCoal *p){this->next = p;};
        void setPrev(noHashCoal *p){this->prev = p;};
        void setInfo(unsigned chave){this->chave = chave;};
        void setIndice(unsigned indice){this->indice = indice;};
        void setColisao(noHashCoal *p){this->colisao = p;};

    private:
        unsigned chave; //unsignedeiro contendo a informacao
        unsigned indice; //unsignedeiro que armazena o indice
        noHashCoal *next; //ponteiro para proxima posicao
        noHashCoal *prev; //ponteiro para posicao anterior
        noHashCoal *colisao; //posicao do elemento que colidiu
};

#endif // NOHASHCOAL_H
