#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include <vector>
#include "HashInfoJogo.h"

using namespace std;

/**
 * Valor correspondente de string em unsigned
 *
 * @author eliascassis
 * @param string str string
 * @return valorString correspondente unsigned da soma dos caracteres da string.
 */
int converterStringUnsigned(string str);

/**
 * Atribuição de dados a cada conjunto, retornando-o em um vetor.
 *
 * @author eliascassis
 * @param dataset Arquivo com os dados
 * @param n Tamanho do conjunto
 * @return users Vetor com nomes de usuários
 */
char** leituraNomeUsuarios(fstream &dataset, unsigned n);

/**
 * Atribuição de dados a cada conjunto, retornando-o em um vetor.
 *
 * @author caiosdeo
 * @param dataset Arquivo com os dados
 * @param n Tamanho do conjunto
 * @param tabelaInfoJogo tabela hash de info jogo
 */
void leituraInfoJogos(fstream &dataset, int n, HashInfoJogo* tabelaInfoJogo);

/**
 * Separar substrings de um string delimitadas por um caracter
 *
 * @author caiosdeo
 * @param s string
 * @param delimitador separador das substrings
 */
vector<string> separar(const string &s, char delimitador);

/**
 * Armazena todas categorias em um vetor.
 *
 * @author caiosdeo
 * @param tabelaInfoJogo tabela hash de info jogo
 * @param n Tamanho do conjunto
 */
vector<string> pegarCategorias(HashInfoJogo* tabelaInfoJogo, int n);

/**
 * Valor correspondente de string em unsigned
 *
 * @author eliascassis
 * @param string str string
 * @param n unsigned tamanho do conjunto de strings
 * @return maior correspondente unsigned da soma dos caracteres da string.
 */
 int maiorValorString(char** users, unsigned n);

 /**
 * Valor correspondente de string em unsigned
 *
 * @author eliascassis
 * @param categorias vector<string> de categorias
 * @param n unsigned tamanho do conjunto de strings
 * @return maior correspondente unsigned da soma dos caracteres da string.
 */
 int maiorValorStringVector(vector<string> categorias, unsigned n);

/**
 * Valor correspondente de string em unsigned
 *
 * @author eliascassis
 * @param freq lista de string com as ocorrências
 * @param objeto vetor de strings dos objetos 
 * @param tam tamanho do conjunto de objetos
 * @return maior correspondente unsigned da soma dos caracteres da string.
 */
void heapSort(list<string> *freq, unsigned tam);
