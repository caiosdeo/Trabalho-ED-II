#ifndef HEAPSORT_H
#define HEAPSORT_H

class HeapSort
{
    public:
        void heapify(int *id, int tam, int indice, int *trocas, int *comparacoes);
        void trocarId(int a, int b);
        void heapSort(int *id, int tam, int *trocas, int *comparacoes);


    protected:

    private:
};

#endif // HEAPSORT_H
