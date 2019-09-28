#include <fstream>
#include <stack>
#include <list>

using namespace std;

class HashNode 
{ 
    public: 
    int value; 
    int key; 
    HashNode(int key, int value); 
    int getKey();
};

class HashMap 
{ 
    private:
    HashNode **hashTable; 
    int capacity;
    int size; 
    HashNode *aux; 
    int numColisoes;
  
    public: 
        HashMap(int capacity);
        int hashCode(int key);
        void insertNode(int key, int value);
        int deleteNode(int key);
        int sizeofMap();
        bool estaVazia();
        bool estaCheia();
        void display();
        int getNumColisoes();

}; 