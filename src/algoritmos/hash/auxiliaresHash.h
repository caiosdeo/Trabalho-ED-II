#include "../../classes/review.h"

/**
 * Valor correspondente de string em unsigned
 *
 * @author eliascassis
 * @param string str string
 * @return valorString correspondente unsigned da soma dos caracteres da string.
 */
unsigned converterStringUnsigned(string str);
 
/**
 * Função para gerar um conjunto de chaves para hashing 
 * a partir de um conjunto de reviews
 *
 * @author eliascassis
 * @param review Conjunto de reviews
 * @param n Tamanho do conjunto de reviews
 * @return chaves Conjunto de unsigneds com as chaves
 */
unsigned* gerarConjuntoChaves(Review* review, unsigned n);
