#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include "HashInfoJogo.h"

using namespace std;

/**
 * Valor correspondente de string em unsigned
 *
 * @author eliascassis
 * @param string str string
 * @return valorString correspondente unsigned da soma dos caracteres da string.
 */
unsigned converterStringUnsigned(string str);

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
 * @return r Vetor com dados
 */
void leituraInfoJogos(fstream &dataset, int n, HashInfoJogo* tabelaAvaliacao);

/**
 * Valor correspondente de string em unsigned
 *
 * @author eliascassis
 * @param string str string
 * @param n unsigned tamanho do conjunto de strings
 * @return maior correspondente unsigned da soma dos caracteres da string.
 */
 unsigned maiorValorString(char** users, unsigned n);

// TODO: documentar aqui melhor depois!!!
void heapSort(list<string>  *freq, string* users, unsigned tam);
