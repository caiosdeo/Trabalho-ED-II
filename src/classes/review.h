#ifndef REVIEW_H_INCLUDED
#define REVIEW_H_INCLUDED
#include <fstream>

using namespace std;


//Definição da Classe Review
class Review{

    private:
        char* user;
        float rating;
        int id;

    public:
        Review* leituraDados(fstream &arquivo, int n);
        int getId();
        char* getUser();
        float getRating();

};

#endif //REVIEW_H_INCLUDED