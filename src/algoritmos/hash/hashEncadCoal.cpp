#include "hashEncadCoal.h"
#include <list>

using namespace std;

hashEncadCoal::hashEncadCoal(int numeroChaves)
{
    this->numeroChaves = numeroChaves;
    this->tabela = new list<int>[this->numeroChaves];
    this->proxColisao = new list<int>[this->numeroChaves];
}

hashEncadCoal::~hashEncadCoal()
{
    delete this->tabela;
    delete this->proxColisao;
}

int hashEncadCoal::funcaoHash(int chave)
{
    return (chave % this->numeroChaves);
}

void hashEncadCoal::insereItem(int chave)
{
    int indice = funcaoHash(chave);
    /// verifica se posicao esta vazia
    if(tabela[indice])
    {
        tabela[indice].push_back(chave); ///insere chave na posicao
    }
    else ///se nao
    {
        int i = indice;
        ///se proxima colisao nao for -1
        if(proxColisao[i])
        {
            while(proxColisao[i] ) ///enquanto houver colisoes regitradas
                    i = proxColisao[i];     ///busca pela proxima posicao de colisao vazia
            int j;
            for(j = i; j > tabela[indice].begin(); j--) ///busca posicao vazia a partir da ultima colisao
            {
                if(tabela[j])
                {
                    tabela[j].push_back(chave); ///insere valor na posicao encontrada
                    proxColisao[i].push_back(j);///insere o endereco da ultima colisao
                    break;
                }
            }
        }
        else
        {
            list<int>::iterator j;
            for(j = tabela[i].end(); j != tabela[i].begin(); j--) ///procura pela proxima posicao vazia a partir do final
            {
                if(*j )
                {
                    tabela[j].push_back(chave); ///insere chave na nova posicao
                    proxColisao[i].push_back(j);///insere o endereco da colisao
                }
            }
            tabela[j].push_back(chave); ///insere chave na nova posicao
            proxColisao[i].push_back(j);///insere o endereco da colisao
        }
    }
    // --> Como verificar se posicao tal esta preenchido ou nao?
}

void hashEncadCoal::removeItem(int chave)
{
    int indice = funcaoHash(chave);

    list<int>::iterator i;
    for(i = tabela[indice].begin(); i != tabela[indice].end(); i++)
        if(*i == chave)
            break;

    if(i != tabela[indice].end())
        tabela[indice].erase(i);
}