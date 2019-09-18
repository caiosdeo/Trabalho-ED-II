#include "QuickSortMediano.h"
#include <iostream>
#include "quickSortInsertion.h"
#include "InsertionSort.h"
#include "quickSortRecursivo.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void trocarId(int *vetor, int a, int b) {
    int h = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = h;
}

int particaoId(int *vetor, int inicio, int fim, int *trocas, int *comparacoes) {
    int meio = (inicio + fim) / 2;
    int idI = vetor[inicio], idM = vetor[meio], idF = vetor[fim];
    int mediana = 0;
    comparacoes++;
    if (idI < idM) {
        comparacoes++;
        if (idM < idF) {
            mediana = meio;
        }
        else {
            comparacoes++;
            if (idI < idF) {
                mediana = fim;
            }
            else {
                mediana = inicio;
            }
        }
    }
    else {
        comparacoes++;;
        if (idF < idM) {
            mediana = meio;
        }
        else {
            comparacoes++;
            if (idF < idI) {
                mediana = fim;
            }
            else {
                mediana = inicio;
            }
        }
    }
    trocas++;
    trocarId(vetor, mediana, fim);
    int pivo = vetor[fim];
    int i = inicio - 1;
    for (int j = 0; j < fim - 1; j++) {
        comparacoes++;
        if (vetor[j] <= pivo) {
            i++;
            trocas++;
            trocarId(vetor, i, j);
        }
    }
    trocas++;
    trocarId(vetor, i + 1, fim);
    return i + 1;
}

void quickSortMedianoId(int *vetor, int inicio, int fim, int *trocas, int *comparacoes) {
comparacoes++;
if (inicio < fim) {
        int q = particaoId(vetor, inicio, fim, trocas, comparacoes);
        quickSortMedianoId(vetor, inicio, q - 1, trocas, comparacoes);
        quickSortMedianoId(vetor, q+1, fim, trocas, comparacoes);
    }
}

void trocarReview(Review* r, int a, int b) {
    Review aux;
    r[a] = aux;
    r[a] = r[b];
    r[b] = aux;
}

int particaoReview(Review* r, int inicio, int fim, int *trocas, int *comparacoes) {
    int meio = r[(inicio + fim) / 2)].getId();
    int reviewI = r[inicio].getId(), reviewM = r[meio].getId(), reviewF = r[fim].getId();
    int mediana = 0;
    comparacoes++;
    if (reviewI < reviewM) {
        comparacoes++;
        if (reviewM < reviewF) {
            mediana = meio;
        }
        else {
            comparacoes++;
            if (reviewI < reviewF) {
                mediana = fim;
            }
            else {
                mediana = inicio;
            }
        }
    }
    else {
        comparacoes++;;
        if (reviewF < reviewM) {
            mediana = meio;
        }
        else {
            comparacoes++;
            if (reviewF < reviewI) {
                mediana = fim;
            }
            else {
                mediana = inicio;
            }
        }
    }
    trocas++;
    trocarReview(r, mediana, fim);
    int pivo = r[fim].getId();
    int i = inicio - 1;
    for (int j = 0; j < fim - 1; j++) {
        comparacoes++;
        if (r[j].getId() <= pivo) {
            i++;
            trocas++;
            trocarReview(r, i, j);
        }
    }
    trocas++;
    trocarReview(r, i + 1, fim);
    return i + 1;
}

void quickSortMedianoReview(Review* r, int inicio, int fim, int *trocas, int *comparacoes) {
    comparacoes++;
    if (inicio < fim) {
        int q = particaoReview(r, inicio, fim, trocas, comparacoes);
        quickSortMedianoReview(r, inicio, q - 1, trocas, comparacoes);
        quickSortMedianoReview(r, q+1, fim, trocas, comparacoes);
    }
}


