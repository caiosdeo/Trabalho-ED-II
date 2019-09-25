#include <fstream>
#include <stack>
#include <list>

using namespace std;

//SONDAGEM LINEAR

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
    //hash element array 
    HashNode **arr; 
    int capacity; 
    //current size 
    int size; 
    //dummy node 
    HashNode *dummy; 
  
    public: 
    HashMap();
    int hashCode(int key);
    void insertNode(int key, int value);
    int deleteNode(int key);
    int get(int key);
    int sizeofMap();
    bool isEmpty();
    void display();
}; 