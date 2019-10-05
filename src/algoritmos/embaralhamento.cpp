#include "embaralhamento.h"
#include "ordenacao.h"

void embaralharIds(unsigned *v, unsigned n){

    for(unsigned i = 0; i < n/2; i+=2)
        swap(v, i, n-i);

    for(unsigned i = 0; i < n - 1; i+=2)
        swap(v, i, i+1);

}

void embaralharEstruturas(Review *r, unsigned n){

    for(unsigned i = 0; i < n/2; i+=2)
        swapEstruturas(r, i, n-i);

    for(unsigned i = 0; i < n - 1; i+=2)
        swapEstruturas(r, i, i+1);

}