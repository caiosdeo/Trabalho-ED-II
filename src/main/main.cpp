#include <iostream>
#include <fstream>
#include "menu.h"

using namespace std;

int main(){

    unsigned selecao = 1;

    while (selecao != 0){

        unsigned clear = system("clear");
        selecao = menu();

        selecionar(selecao);

    }

    return 0;

}