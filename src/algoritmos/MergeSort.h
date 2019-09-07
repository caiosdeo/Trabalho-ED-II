#ifndef MERGESORT_H
#define MERGESORT_H
#include "review.h"
#include <fstream>

using namespace std;

class MergeSort
{
    public:
        MergeSort(){};
        ~MergeSort(){};
        void mergeSort(int *vet, Review *r, int esqV, int dirV, int esqR, int dirR, int *numComp, int *numReg);

    private:
        void mergeV(int *vet, int esq, int med, int dir);
        void mergeR(Review *r, int esq, int med, int dir, int *numComp, int *numReg);
};

#endif // MERGESORT_H
