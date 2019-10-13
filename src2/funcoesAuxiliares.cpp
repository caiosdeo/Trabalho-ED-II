#include "funcoesAuxiliares.h"

// Converte uma string em um inteiro sem sinal
unsigned converterStringUnsigned(char* str){

    unsigned valorString = 0;

    for(unsigned  i = 0; str[i] != '\0'; i++)
        valorString += str[i];

    return valorString;

}

char** leituraNomeUsuarios(fstream &dataset, unsigned n){

    // Conjunto de Nomes
    char** users = (char**)calloc(n, sizeof(char*));
    
    //Variaveis para ler o documento
    string user;
    unsigned tString;

    //Variavel auxiliar para controlar o tamanho do conjunto
    int i = 0;

    // Alterando a semente com o tempo
    srand(time(0));

    // Eliminando a primeira linha do arquivo
    getline(dataset, user,'\n');

    // Extração de dados até o tamanho do conjunto e o fim do arquivo
    while(dataset.good() && i < n){

        // Pegando as informações de cada registro
        getline(dataset, user, '\n');

        if(rand() % 3 == 0){ // Selecionando registros a partir do resto de uma divisão por 3

            //Atribuindo um nome de usuário
            tString = user.size();
            users[i] = (char*)malloc(sizeof(char) * tString);//(char*)calloc(tString, sizeof(char));
            for(int j = 0; j < tString; j++)
                users[i][j] = user[j];
            i++;

        }
        
    }

    // Retornando o conjunto de nomes
    return users;

}