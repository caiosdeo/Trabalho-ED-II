#include "funcoesHuffman.h"
#include<cmath>

int* tabelaFrequencias(string m, unsigned n){

    int* tabela = (int*)calloc(n, sizeof(int)); // aloca tabela de frequências
    // Loop para contagem de frequências de cada caracter da mensagem m
    for(int i = 0; i < m.size(); i++)
        tabela[m[i]-' ']++;

    return tabela;

}

string gerarMensagemCodificada(string m, vector<string> &codigos){

    string mensagemCodificada; // Declara mensagem codificada

    // Loop para codificar cada caractere da mensagem
    for(int i = 0; i < m.size(); i++)
        mensagemCodificada += codigos[m[i]-' '];

    return mensagemCodificada; // Retorna mensagem codificada em 0's e 1's

}

char gerarCodigoAscII(string s){

    int codigo = 0; // Inicializa somador do código ascii
    int t = s.size(); // Tamanho da string s

    // Converte binário para decimal nos bits de s
    for(int i = t - 1; i >= 0; i--)
        if(s[i] == '1')
            codigo += pow(2, t - 1 - i);

    return char(codigo + ' '); // Retorna código ascii

}

string compactarAscII(string mC){

    string aux; // String auxiliar
    string compactado; // Variável para string compactada
    int t = mC.size(); // Tamanho da mensagem
    int steps = t / 8; // Quantidade de passos de preenchimento de byte
    int resto = t % 8; // Quantidade de caracteres restante para codificação

    // Adiciona 8 bits à variável auxiliar e os codifica
    for(int i = 0; i < steps; i++){

        for(int j = 0; j < 7; j++)
            aux += mC[i+j];
        compactado += gerarCodigoAscII(aux);
        aux = '\0';

    }

    // Adiciona o restante dos bits à variável auxiliar
    for(int i = resto; i > 0; i--)
        aux += mC[t-1-i];

    compactado += gerarCodigoAscII(aux); // Codificando bits restantes

    return compactado; // Retorna string compactada
 
}