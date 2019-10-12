#ifndef AVALIACAO_H_INCLUDED
#define AVALIACAO_H_INCLUDED
#include <fstream>

using namespace std;


//Definição da Classe Avaliacao
class Avaliacao{

    private:
        char* user;
        float rating;
        int id;

    public:
        Avaliacao* leituraDados(fstream &arquivo, int n);
        int getId();
        char* getUser();
        float getRating();

};

#endif //AVALIACAO_H_INCLUDED