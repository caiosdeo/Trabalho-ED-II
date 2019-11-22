#include <iostream>
#include <fstream>
#include "execucao.h"
#include "lzw.h"
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

int main(){

    //executar();

    //int clear = system("clear");

    string m = "bananabanabofana";

    vector<int> codigo = comprimirLZW(m);

    string msg = gerarCodigoLZW(codigo);

    cout << msg << endl; 

    return 0;

}