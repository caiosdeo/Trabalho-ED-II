#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED
#include <fstream>

using namespace std;


//Definição da Classe Arquivo
class Arquivo{

    public:
        void leitura(fstream &arquivo);
        int* leituraDados(fstream &arquivo, int n);


};

#endif //ARQUIVO_H_INCLUDED