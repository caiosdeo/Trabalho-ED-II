#include<iostream>
#include<fstream>

/**
 * Valor correspondente de string em unsigned
 *
 * @author eliascassis
 * @param string str string
 * @return valorString correspondente unsigned da soma dos caracteres da string.
 */
unsigned converterStringUnsigned(char* str);

/**
 * Atribuição de dados a cada conjunto, retornando-o em um vetor.
 *
 * @author eliascassis
 * @param dataset Arquivo com os dados
 * @param n Tamanho do conjunto
 * @return users Vetor com nomes de usuários
 */
char** leituraNomeUsuarios(fstream &dataset, unsigned n);