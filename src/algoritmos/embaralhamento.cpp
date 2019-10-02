#include "embaralhamento.h"
#include "ordenacao.h"

void embaralharIds(int *v, int n){

    for(int i = 0; i < n/2; i+=2)
        swap(v, i, n-i);

    for(int i = 0; i < n - 1; i+=2)
        swap(v, i, i+1);

}

void embaralharEstruturas(Review *r, int n){

    for(int i = 0; i < n/2; i+=2)
        swapEstruturas(r, i, n-i);

    for(int i = 0; i < n - 1; i+=2)
        swapEstruturas(r, i, i+1);

}