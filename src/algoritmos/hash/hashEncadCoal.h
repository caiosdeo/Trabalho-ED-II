#ifndef HASHENCADCOAL_H
#define HASHENCADCOAL_H
#include <list>

using namespace std;

///classe de hash coalescido (sem porao)
class hashEncadCoal
{
    private:
        int numeroChaves;
        list<int> *tabela;
        list<int> *proxColisao;

    public:
        hashEncadCoal(int numeroChaves);
        ~hashEncadCoal();
        int funcaoHash(int chave);
        void insereItem(int chave);
        void removeItem(int chave);
};


#endif // HASHENCADCOAL_H
