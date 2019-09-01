#include "arquivo.h"
#include "review.h"

Review** leitura(fstream &entrada, fstream &dataset){

    int qtdConjuntos;
    int n;

    entrada >> qtdConjuntos;

    Review** conjuntos = new Review*[qtdConjuntos];

    for(int i = 0; i < qtdConjuntos; i++){
        
        entrada >> n;

        conjuntos[i] = new Review[n];

        conjuntos[i] = conjuntos[i]->leituraDados(dataset, n);

    }

    return conjuntos;
    
}
