#include "arquivo.h"
#include "review.h"

void Arquivo::leitura(fstream &arquivo){


}

int* Arquivo::leituraDados(fstream &arquivo, int n){

    int* id = new int[n];
    string user;
    float rating;

    int i = 0;

    srand(time(NULL));

	while(arquivo && i < n){

        arquivo >> user >> rating >> id[i];

        if(rand() % 2 == 1){

            i++;

        }
        

	}

    return id;

}
