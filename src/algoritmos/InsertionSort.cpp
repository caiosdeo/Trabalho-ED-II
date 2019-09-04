#include <iostream>
#include "review.h"
#include <fstream>

using namespace std;

void insertionSort(int *vet, Review *r, int sizev, int sizer, int *numComp, int *numReg)
{
    int i, ch, j;
    for(i = 1; i < sizev; i++)
    {
        ch = vet[i];
        j = i-1;
        while(j >= 0 && vet[j] > ch)
        {
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = ch;
    }

    for(i = 1; i < sizer; i++)
    {
        int id = r[i].getId();
        float rat = r[i].getRating();
        string use = r[i].getUser();
        j = i-1;
        while(j >= 0 && r[j].getId() > id)
        {
            r[j+1].setNewInfo(r[j].getUser(),r[j].getRating(),r[j].getId());
            j--;
            *numComp+=1;
        }
        r[j+1].setNewInfo(use,rat,id);
    }
}
