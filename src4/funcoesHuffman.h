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
tuple<int*,char*> tabelaFrequencias(string m, unsigned n);

/**
 * Método para construir a árvore de Huffman
 * @author eliascassis
 * @param huffHeap vetor com nós de Huffman
 * @param tam número de nós de Huffman 
 * @return raiz da árvore de huffman
 */
NoHuff* huffTree(NoHuff** huffHeap, unsigned tam);

/**
 * Método para codificar mensagem em binário
 * @author eliascassis
 * @param m string a ser codificada
 * @param codigos vetor com códigos gerados (binário)
 * @return mensagem codificada em binário
 */
string gerarMensagemCodificada(string m, vector<string> &codigos);

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

#endif //FUNCOESHUFFMAN_H_INCLUDED