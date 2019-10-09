#include "quickSortMediano.h"
#include "quickSortRecursivo.h"
#include <iostream>

using namespace std;

void gerarVetor(unsigned* v, unsigned inicio, unsigned k, unsigned* aux){
    
    for(unsigned i = 0; i < k; i++, inicio++ )
        aux[i] = v[inicio];

}

unsigned medianadek(unsigned* vetor, unsigned k, unsigned* trocas, unsigned *comparacoes){

    quickSortRecursivoIds(vetor, 0, k-1, comparacoes, trocas);

    unsigned mediana = k/2;

    return mediana;

}

void quickSortMediano(unsigned *vetor, unsigned inicio, unsigned fim, unsigned k, unsigned *trocas, unsigned *comparacoes) {


    if(inicio < fim){

        if (fim - inicio < k) {

            unsigned pivo = particaoIds(vetor, inicio, fim, comparacoes, trocas);
            if(pivo != 0)
                quickSortMediano(vetor, inicio, pivo - 1, k, trocas, comparacoes);
            if(pivo != fim)
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
            swap(vetor, mediana, fim);

            unsigned pivo = particaoIds(vetor, inicio, fim, comparacoes, trocas);
            
            if(pivo != 0)
                quickSortMediano(vetor, inicio, pivo - 1, k, trocas, comparacoes);
            if(pivo != fim)
                quickSortMediano(vetor, pivo + 1, fim, k, trocas, comparacoes);
        
        }


    }

}