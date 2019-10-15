#include "funcoesAuxiliares.h"
#include "InfoJogo.h"
#include "HashInfoJogo.h"
#include<string>
#include<cstring>
#include<sstream>
#include<vector>

// Converte uma string em um inteiro 
int converterStringInteiro(string str){

    int valorString = 0;
    // Somatório do valor ascii dos caracteres da string
    for(int  i = 0; str[i] != '\0'; i++)
        valorString += str[i];

    return valorString;

}

char** leituraNomeUsuarios(fstream &dataset, unsigned n){

    // Conjunto de Nomes
    char** users = (char**)calloc(n, sizeof(char*));
    
    //Variaveis para ler o documento
    string user;
    unsigned tString;

    //Variável auxiliar para controlar o tamanho do conjunto
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
            users[i] = (char*)malloc(sizeof(char) * tString);
            for(int j = 0; j < tString; j++)
                users[i][j] = user[j];
            i++;

        }
        
    }

    // Retornando o conjunto de nomes
    return users;

}

// Confere se determinada string é um número
bool eNumero(const string& s){
    return( strspn( s.c_str(), "0123456789" ) == s.size() );
}

void leituraInfoJogos(fstream &dataset, int n, HashInfoJogo* tabelaInfoJogo){

    // Conjunto de Avaliacoes
    InfoJogo info;

    //Variaveis para ler o documento
    string id, categoria, idJogo;
    unsigned tString;

    //Variavel auxiliar para controlar o tamanho do conjunto
    int i = 0;

    // Alterando a semente com o tempo
    srand(time(0));

    // Eliminando a primeira linha do arquivo
    getline(dataset, id, ',');
    getline(dataset, categoria, ',');
    getline(dataset, idJogo, '\n');

    // Extração de dados até o tamanho do conjunto e o fim do arquivo
    while(dataset.good() && i < n){

        // Pegando as informações de cada registro
        getline(dataset, id, ',');
        getline(dataset, categoria, ',');
        getline(dataset, idJogo, '\n');

        if(rand() % 3 == 0 && eNumero(idJogo) && eNumero(id)){ // Selecionando registros a partir do resto de uma divisão por 3

            info.setCategoria(categoria);
            info.setId(stoi(id));
            info.setIdJogo(stoul(idJogo));

            tabelaInfoJogo->inserirHash(info);

            i++;

        }
    }
}

// Separa categorias do vetor de categorias
vector<string> separar(const string &s, char delimitador) {
    
    vector<string> resultado;
    stringstream ss(s);
    string item;

    // Separa todas as strings em um vetor de strings
    while (getline (ss, item, delimitador)) {
        resultado.push_back (item);
    }

    return resultado;

}

// Retorna o vetor de categorias
vector<string> pegarCategorias(HashInfoJogo* tabelaInfoJogo, int n){

    //Variaveis para ler o documento
    vector<string> categorias, aux;

    InfoJogo* tabelaHash = tabelaInfoJogo->getTabelaHash();

    // Armazenando todas as string em um vetor
    for(int i = 0; i < n; i++){
        
        aux = separar(tabelaHash[i].getCategoria(), '|');
        categorias.insert(categorias.end(), aux.begin(), aux.end());    
    
    }

    return categorias;

}

// Retorna o maior inteiro relacionado ao vetor de strings
int maiorValorStringVector(vector<string> categorias, unsigned n){

    int maior = converterStringInteiro(categorias[0]); // Converte primeira posição para inteiro
    int aux;

    // Laço de comparações
    for(int i = 1; i < categorias.size(); i++){

        aux = converterStringInteiro(categorias[i]); // Converte string i para inteiro
        // Compara se string i é maior que o atual maior
        if(aux > maior)
            maior = aux; // Atualiza maior

    }

    // Retorna maior valor de string
    return maior;

}

// Retorna o maior inteiro relacionado ao vetor de strings
int maiorValorString(char** objeto, unsigned n){

    int maior = converterStringInteiro(objeto[0]); // Converte primeira posição para inteiro
    int aux;

    // Laço de comparações
    for(int i = 1; i < n; i++){

        aux = converterStringInteiro(objeto[i]); // Converte string i para inteiro
        // Compara se string i é maior que o atual maior
        if(aux > maior) 
            maior = aux; // Atualiza maior

    }

    // Retorna maior valor de string
    return maior;

}

// Funções para Heap Sort
// Função de swap para vetor de strings
void swap(string *i, string *j){

    string aux;

    aux = *i;
    *i = *j;
    *j = aux;

}

// Função de swap para listas de string
void swapFreq(list<string> *i, list<string> *j){

    list<string> aux;

    aux = *i;
    *i = *j;
    *j = aux;

}

// Constrói uma heap de mínimo
void heapify(list<string> *freq, unsigned tam, unsigned indice){
    
    unsigned menor = indice; // Pai
    unsigned esq = 2*indice + 1; // Filho da esquerda
    unsigned dir = 2*indice + 2; // Filho da direita

    // Atualiza menor valor se necessário
    if (esq < tam && freq[esq].size() < freq[menor].size()) {
        menor = esq;
    }

    // Atualiza menor valor se necessário
    if (dir < tam && freq[dir].size() < freq[menor].size()) {
        menor = dir;
    }

    // Confere se o menor não é o pai 
    if (menor != indice) {
        // Troca pai com o menor filho
        swapFreq(&freq[indice], &freq[menor]);
        heapify(freq, tam, menor); // Chama heapify
    }

}

// Heap Sort
void heapSort(list<string> *freq, unsigned tam){
    // Constrói a heap de mínimo
    for (int i = tam / 2 -1; i >= 0; i--)
        heapify(freq, tam, i);

    // Extrai, um por um, os elementos da heap
    for (int i = tam-1; i >= 0; i--){

        // Move o atual para o fim
        swapFreq(&freq[0], &freq[i]);

        // Chama o min Heapfy para a heap reduzida
        heapify(freq, i, 0); 
    }

}