#ifndef INFOJOGO_H_INCLUDED
#define INFOJOGO_H_INCLUDED
#include <fstream>

using namespace std;

//Definição da Classe InfoJogo
class InfoJogo{

    private:
        string categoria;
        int id;
        unsigned idJogo;

    public:
        int getId();
        string getCategoria();
        unsigned getIdJogo();
        void setId(int id);
        void setIdJogo(unsigned idJogo);
        void setCategoria(string categoria);

};

#endif //INFOJOGO_H_INCLUDED