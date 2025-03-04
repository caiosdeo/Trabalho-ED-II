#ifndef FUNCOESHUFFMAN_H_INCLUDED
#define FUNCOESHUFFMAN_H_INCLUDED

#include "noHuffman.h"
#include<tuple>
#include<vector>
using namespace std;

/**
 * Método para construir a tabela de frequência dos caracteres de uma mensagem m
 * @author eliascassis
 * @param m mensagem
 * @param n número de caracteres do alfabeto
 * @return tabela de frequências
 */
tuple<int*,char*, int> tabelaFrequencias(string m, int n);

/**
 * Método para codificar mensagem em binário
 * @author eliascassis
 * @param m string a ser codificada
 * @param codigos vetor com códigos gerados (binário)
 * @param infos vetor de caracteres da mensagem
 * @param t tamanho dos vetores
 * @return mensagem codificada em binário
 */
string gerarMensagemCodificada(string m, char **codigos, char *infos, int t);

/**
 * Método para converter binário em inteiro
 * @author eliascassis
 * @param s bits do caractere a serem codificados
 * @return código ascii
 */
char gerarCodigoAscII(string s);

/**
 * Método para compactar uma string
 * @author eliascassis
 * @param mC string com mensagem codificada em binário
 * @return mensagem compactada
 */
string compactarAscII(string mC);

/**
 * Função que constrói árvore de Huffman e retorna o código
 * @author caiosdeo
 * @param str string a ser codificada em binário
 * @return mensagem comprimida, codificada
 */
string comprimirHuffman(string str);

/**
 * Função recursiva que preenche os vetores: infos e codigos da arvore de Huffman
 * @author caiosdeo
 * @param raiz no a ser buscado
 * @param str codigo em binario
 * @param infos vetor de char a ser preenchido com as infos
 * @param codigos vetor de string a ser preenchido com os codigos em binarios de cada info
 * @param t tamanho dos vetores
 */
void gerarTabelaCodigos(NoHuff* raiz, string str, char *infos, char **codigos, int t);

#endif //FUNCOESHUFFMAN_H_INCLUDED