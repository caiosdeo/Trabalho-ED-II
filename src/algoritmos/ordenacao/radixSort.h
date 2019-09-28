/**
 * Função para pegar o maior elemento em um vetor
 * @author caiosdeo
 * @param v Vetor de inteiros
 * @param n tamanho do vetor
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return maior Maior elemento no vetor
 */
int maior(int* v, int n, int* numComparacoes, int* numTrocas);

/**
 * Função para para fazer a ordenação por contagem de um vetor por um digito exp
 * @author caiosdeo
 * @param v Vetor de inteiros
 * @param n tamanho do vetor
 * @param exp digito 
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return void
 */
void countSort(int* v, int n, int exp, int* numComparacoes, int* numTrocas);

/**
 * Função principal para o radix sort
 * @author caiosdeo
 * @param v Vetor de inteiros
 * @param n tamanho do vetor de inteiros
 * @param numComparacoes número de comparações
 * @param numTrocas número de trocas
 * @return void
 */
void radixSort(int *v, int n, int *numComparacoes, int *numTrocas);
