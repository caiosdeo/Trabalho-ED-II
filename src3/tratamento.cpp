#include <iostream>
#include <fstream>
#include <chrono>
#include "tratamento.h"
#include "review.h"

// Imprime saída 
void imprimirSaida(fstream &saida, unsigned estrutura, int estado, unsigned n, float numComparacoes, float numCopias, float tempoProcessamento){

    saida << estrutura << "," << estado << "," << n << "," << numComparacoes << "," << numCopias << "," << tempoProcessamento << endl;

}

// Embaralha estruturas de review
void embaralharEstruturas(Review *r, unsigned n){

    for(unsigned i = 0; i < n/2; i+=2)
        swapEstruturas(r, i, n-i);

    for(unsigned i = 0; i < n - 1; i+=2)
        swapEstruturas(r, i, i+1);

}

// Retorna vetor com os ids das reviews
unsigned* gerarVetorIds(Review* conjunto, unsigned n){

    //Vetor unsigned           
    unsigned* ids = (unsigned*)calloc(n, sizeof(unsigned));

    for(int i = 0; i < n; i++)
        ids[i] = conjunto[i].getId();

    // Retornando o conjunto de ids
    return ids;

}

// Swap para estruturas
void swapEstruturas(Review* a, unsigned i, unsigned j){

    Review aux;

    aux = a[i];
    a[i] = a[j];
    a[j] = aux;

}

// Converte uma string em um inteiro 
int converterStringInteiro(string str){

    int valorString = 0;
    // Somatório do valor ascii dos caracteres da string
    for(int  i = 0; str[i] != '\0'; i++)
        valorString += str[i];

    return valorString;

}