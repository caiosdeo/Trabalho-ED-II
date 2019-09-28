#include <fstream>
#include <stack>
#include <list>

using namespace std;

class NoHash{ 

    private:
        int valor; 
        int chave; 

    public: 
        HashNode(int chave, int valor); 
        int getChave();
};