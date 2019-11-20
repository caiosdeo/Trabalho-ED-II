#include "noHuffman.h"
#include<tuple>
using namespace std;

/**
 * Método para construir a tabela de frequência dos caracteres de uma mensagem m
 * @author eliascassis
 * @param m mensagem
 * @param n número de caracteres do alfabeto
 */
int* tabelaFrequencias(string m, unsigned n);

/**
 * Método para construir vetor que conterá os nós de Huffman
 * @author eliascassis
 * @param m tabelaFrequências tabela de frequência dos caracteres de uma mensagem
 * @param n tamanho da tabela de frequências
 */
tuple<NoHuff*, int> gerarHuffHeap(int* tabelaFrequencias, unsigned n);