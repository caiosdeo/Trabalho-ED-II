#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include "../classes/review.h"
#include <fstream>

using namespace std;

class InsertionSort
{
    public:
        InsertionSort(){};
        ~InsertionSort(){};
        void insertionSort(int *vet, Review *r, int sizev, int sizer, int *numComp, int *numReg);

};

#endif // INSERTIONSORT_H
