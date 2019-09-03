#include "review.h"

Review* Review::leituraDados(fstream &arquivo, int n){

    Review* r = new Review[n];
    
    int id;
    string user;
    float rating;

    int i = 0;

    srand(time(NULL));

	while(arquivo && i < n){

        arquivo >> user >> rating >> id;

        if(rand() % 2 == 1){

            r[i].user = user;
            r[i].rating = rating;
            r[i].id = id;

            i++;

        }
        

	}

}

int Review::getId(){

    return this->getId();

}