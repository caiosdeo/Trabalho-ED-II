#include "../../classes/review.h"

/**
 * Valor correspondente de string em inteiro
 *
 * @author eliascassis
 * @param string str string
 * @return valorString correspondente inteiro da soma dos caracteres da string.
 */
int converterStringInteiro(string str);
 
/**
 * Função para gerar um conjunto de chaves para hashing 
 * a partir de um conjunto de reviews
 *
 * @author eliascassis
 * @param review Conjunto de reviews
 * @param n Tamanho do conjunto de reviews
 * @return chaves Conjunto de inteiros com as chaves
 */
int* gerarConjuntoChaves(Review* review, int n);
