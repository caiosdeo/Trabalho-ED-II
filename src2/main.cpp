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

                // TODO: Colocar o processamento aqui
                char** users = leituraNomeUsuarios(dataset, n);
                unsigned t = maiorValorString(users, n);
                HashEncadUsuarios tabelaUsuarios = HashEncadUsuarios(t);
                tabelaUsuarios.exibirFrequencias(x);

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

                // TODO: Colocar o processamento aqui

                // Colocando dados no conjunto
                HashInfoJogo tabelaInfoJogo = HashInfoJogo(n);
                leituraInfoJogos(dataset, n, &tabelaInfoJogo);                    

                // Pegando as categorias
                vector<string> categorias = pegarCategorias(&tabelaInfoJogo, n);

                // ! Imprime todas categorias. Ajustar para sua execução
                unsigned t = maiorValorStringVector(categorias, n);
                HashEncadCategorias tabelaCategorias = HashEncadCategorias(t);
                tabelaCategorias.exibirFrequencias(x);

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