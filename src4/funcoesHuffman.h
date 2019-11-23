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
int* tabelaFrequencias(string m, unsigned n);

/**
 * Método para construir vetor que conterá os nós de Huffman
 * @author eliascassis
 * @param m tabelaFrequências tabela de frequência dos caracteres de uma mensagem
 * @param n tamanho da tabela de frequências
 * @return uma tupla contendo o vetor de nós de huffman e seu respectivo tamanho
 */
tuple<NoHuff**, int> gerarHuffHeap(int* tabelaFrequencias, unsigned n);

/**
 * Método para construir a árvore de Huffman
 * @author eliascassis
 * @param huffHeap vetor com nós de Huffman
 * @param tam número de nós de Huffman 
 * @return raiz da árvore de huffman
 */
NoHuff* huffTree(NoHuff** huffHeap, unsigned tam);

/**
 * Método para representar o caractere em binário
 * @author eliascassis
 * @param raiz raiz da árvore de huffman
 * @param codigo string auxiliar para montagem do código
 * @param codigos vetor a ser preenchido com os códigos gerados
 * @return código binário correspondente ao caractere na árvore de huffman
 */
void gerarCodigo(NoHuff* raiz, string codigo, vector<string> &codigos);

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

/**
 * Método para compactar uma string
 * @author eliascassis
 * @param m mensagem original
 * @param n número de caracteres do alfabeto
 * @return mensagem compactada
 */
string compactarMensagemHuffman(string m, unsigned n);

#endif //FUNCOESHUFFMAN_H_INCLUDED