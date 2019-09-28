#ifndef NOHASH_H
#define NOHASH_H


class NoHash
{
    public:
        NoHash(){};
        ~NoHash(){};
        int getInfo(){return this->chave;};
        int getIndice(){return this->indice;};
        NoHash* getProx() {return this->next;};
        HashPoint* getColisao() {return this->proxColisao;};
        void setProx(HashPoint *p){this->next = p;};
        void setInfoIndice(int chave, int indice){this->chave = chave; this->indice = indice;};
        void setColisao(NoHash *p){this->colisao = p;};

    private:
        int chave;
        NoHash *next;
        NoHash *colisao;
};

#endif // NOHASH_H
