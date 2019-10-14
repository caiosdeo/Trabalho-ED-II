#include <iostream>
#include <fstream>
#include <vector>
#include "InfoJogo.h"
#include "HashInfoJogo.h"
#include "hashEncadCategorias.h"
#include "hashEncadeadoUsuarios.h"
#include "funcoesAuxiliares.h"

using namespace std;

int menu(){

    int selecao;

    cout << "Fase 2" << endl;
    cout << "----" << endl;
    cout << "[1] Usuários Frequentes" << endl;
    cout << "[2] Categorias Frequentes" << endl;
    cout << "[0] Voltar" << endl;

    cin >> selecao;

    int clear = system("clear");

    return selecao;
}

void executar(int selecao){

    fstream dataset;

    int n; // Variável para definir tamanho do conjunto de dados
    int x; // Variável para pegar os x mais frequentes

    if(selecao){

        cout << "Qual o tamanho do conjunto? " << endl;
        cin >> n;

        // ? Esse texto para x frequentes está realmente bom?
        cout << "Quais X's mais frequentes deseja exibir?" << endl;
        cin >> x;

        int clear = system("clear");

    }

    switch(selecao){

        // * Usuários frequentes
        case 1:{

            // Verificando se o arquivo está aberto
            dataset.open("../processadosFase2_1.txt", ios::in); // Arquivo de dados como leitura

            if(dataset.is_open()){

                char** users = leituraNomeUsuarios(dataset, n); // Retorna vetor de usuários do arquivo
                unsigned t = maiorValorString(users, n); // Retorna o maior valor de string associado aos nomes de usuários
                HashEncadUsuarios tabelaUsuarios = HashEncadUsuarios(t); // Aloca tabela hash de usuários
                // Insere usuários na tabela hash
                for(int i = 0; i < n; i++)
                    tabelaUsuarios.insereItem(users[i]);
                tabelaUsuarios.exibirFrequencias(x); // Exibe as X maiores frequências de usuário

                cin.get();
                cout << endl << "Pressione ENTER para voltar ao menu" << endl;
                cin.get();

            }
            else
                cout << "Não foi possível abrir o arquivo de dados" << endl;
            
            break;
        }

        // * Categorias Frequentes
        case 2:{

            // Verificando se o arquivo está aberto
            dataset.open("../processadosFase2_2.csv", ios::in); // Arquivo de dados como leitura

            if(dataset.is_open()){

                // Colocando dados no conjunto
                HashInfoJogo tabelaInfoJogo = HashInfoJogo(n);
                leituraInfoJogos(dataset, n, &tabelaInfoJogo);                    

                // Pegando as categorias
                vector<string> categorias = pegarCategorias(&tabelaInfoJogo, n);

                unsigned t = maiorValorStringVector(categorias, n); // Retorna o maior valor de string associado aos nomes de usuários
                HashEncadCategorias tabelaCategorias = HashEncadCategorias(t); // Aloca tabela hash de categorias
                // Insere categorias na tabela hash
                for(int i = 0; i < n; i++)
                    tabelaCategorias.insereItem(categorias[i]);
                tabelaCategorias.exibirFrequencias(x); // Exibe as X maiores frequências de categoria

                cin.get();
                cout << endl << "Pressione ENTER para voltar ao menu" << endl;
                cin.get();

            }
            else
                cout << "Não foi possível abrir o arquivo de dados" << endl;

            break;
        }
    
        default:
            break;
    }

}

int main(){

    int selecao = 1;

    while(selecao != 0){

        selecao = menu();

        executar(selecao);

        int clear = system("clear");

    }

}