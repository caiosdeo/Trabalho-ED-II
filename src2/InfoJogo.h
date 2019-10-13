#ifndef INFOJOGO_H_INCLUDED
#define INFOJOGO_H_INCLUDED
#include <fstream>

using namespace std;

//Definição da Classe InfoJogo
class InfoJogo{

    private:
        char* categoria;
        unsigned id;
        unsigned idJogo;

    public:
        unsigned getId();
        char* getCategoria();
        unsigned getIdJogo();
        void setId(unsigned id);
        void setIdJogo(unsigned idJogo);
        void setCategoria(char* categoria);
        HashInfoJogo* leituraDados(fstream &dataset, int n);

};

#endif //INFOJOGO_H_INCLUDED