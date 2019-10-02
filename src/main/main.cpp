#include <iostream>
#include <fstream>
#include "menu.h"

using namespace std;

int main(){

    int selecao = 1;

    while (selecao != 0){

        int clear = system("clear");
        selecao = menu();

        selecionar(selecao);

    }

    return 0;

}