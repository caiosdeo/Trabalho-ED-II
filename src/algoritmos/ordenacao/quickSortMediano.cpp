#include "quickSortMediano.h"
#include "quickSortRecursivo.h"
#include <iostream>

using namespace std;

void gerarVetor(unsigned* v, unsigned inicio, unsigned k, unsigned* aux){
    
    for(unsigned i = 0; i < k; i++, inicio++ )
        aux[i] = v[inicio];

}

unsigned medianadek(unsigned* vetor, unsigned k, unsigned long long* trocas, unsigned long long *comparacoes){

    quickSortRecursivoIds(vetor, 0, k-1, comparacoes, trocas);

    unsigned mediana = k/2;

    return mediana;

}

void quickSortMediano(unsigned *vetor, unsigned inicio, unsigned fim, unsigned k, unsigned long long *trocas, unsigned long long *comparacoes) {


    if(inicio < fim){

        if (fim - inicio < k) {
            // ! Aqui não é pra chamar o quickSort comum?
            unsigned pivo = particaoIds(vetor, inicio, fim, comparacoes, trocas);
            if(pivo == 0 || pivo == fim)
                return;
            quickSortMediano(vetor, inicio, pivo - 1, k, trocas, comparacoes);
            quickSortMediano(vetor, pivo + 1, fim, k, trocas, comparacoes);

        }else {

            unsigned aux[k];

            gerarVetor(vetor, inicio, k, aux);

            unsigned mediana = medianadek(aux, k, trocas, comparacoes);

            unsigned copiaInicio = inicio;
            while(aux[mediana] != vetor[copiaInicio])
                copiaInicio++;

            mediana = copiaInicio;

            (*trocas)++;
            swap(&vetor[mediana], &vetor[fim]);

            unsigned pivo = particaoIds(vetor, inicio, fim, comparacoes, trocas);
            if(pivo == 0 || pivo == fim)
                return;
            quickSortMediano(vetor, inicio, pivo - 1, k, trocas, comparacoes);
            quickSortMediano(vetor, pivo + 1, fim, k, trocas, comparacoes);
        
        }


    }

    return;

}