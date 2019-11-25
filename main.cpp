#include <iostream>
#include <fstream>

using namespace std;

int main(){

    unsigned selecao = 1;

    while (selecao != 0){

        int clear = system("clear");

        cout << "MENU" << endl;
        cout << "----" << endl;
        cout << "[1] Fase 1" << endl;
        cout << "[2] Fase 2" << endl;
        cout << "[3] Fase 3" << endl;
        cout << "[4] Fase 4" << endl;
        cout << "[0] Encerrar" << endl;

        cin >> selecao;

        clear = system("clear");

        switch(selecao){

            case 1:{
                int fase = system("./src/a.out");
                break;
            }

            case 2:{
                int fase = system("./src2/a.out");
                break;
            }

            case 3:{
                int fase = system("./src3/a.out");
                break;
            }

            case 4:{
                int fase = system("./src4/a.out");
                break;
            }

            default:
                break;
        }

    }

    return 0;

}