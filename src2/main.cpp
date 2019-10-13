#include <iostream>
#include <fstream>
#include "InfoJogo.h"
#include "HashInfoJogo.h"
#include "funcoesAuxiliares.h"

using namespace std;

int main(){

    fstream dataset, saida;
    
    dataset.open("../../gamesInfoEspecial.csv", ios::in); // Arquivo de dados como leitura

    // Variaveis para leitura do arquivo de entrada
    unsigned n;

    // Verificação se os arquivos estão abertos para prosseguimento na execução do programa
    if(dataset.is_open()){

        // Lendo os N
        cout << "Qual o N?" << endl;
        cin >> n;

        // Colocando dados no conjunto
        HashInfoJogo tabelaInfoJogo = HashInfoJogo(n);
        leituraInfoJogos(dataset, n, &tabelaInfoJogo);                    


    }
    else
        cout << "Não foi possível abrir o arquivo de dados" << endl;

    //entrada.close();
    //dataset.close();

}