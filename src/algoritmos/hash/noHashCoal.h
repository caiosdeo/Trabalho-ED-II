#ifndef NOHASHCOAL_H
#define NOHASHCOAL_H

class noHashCoal
{
    public:
        noHashCoal(){};
        ~noHashCoal(){};

        int getInfo(){return this->chave;};
        int getIndice(){return this->indice;};
        noHashCoal* getProx(){return this->next;};
        noHashCoal* getPrev(){return this->prev;};
        noHashCoal* getColisao() {return this->colisao;};

        void setProx(noHashCoal *p){this->next = p;};
        void setPrev(noHashCoal *p){this->prev = p;};
        void setInfo(int chave){this->chave = chave;};
        void setIndice(int indice){this->indice = indice;};
        void setColisao(noHashCoal *p){this->colisao = p;};

    private:
        int chave; //inteiro contendo a informacao
        int indice; //inteiro que armazena o indice
        noHashCoal *next; //ponteiro para proxima posicao
        noHashCoal *prev; //ponteiro para posicao anterior
        noHashCoal *colisao; //posicao do elemento que colidiu
};

#endif // NOHASHCOAL_H
