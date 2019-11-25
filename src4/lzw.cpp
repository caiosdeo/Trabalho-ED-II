#include "lzw.h"
#include <vector>
#include <sstream>
#include <iterator>
#include<string>
#include<algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<int> comprimirLZW(string m){

    unordered_map<string, int> dicionario; 

    // Mapeando o dicionario de caracteres
    for (int i = 0; i < 256; i++) { 
        string c = ""; 
        c += char(i); 
        dicionario[c] = i; 
    } 
  
    // Inicializando com caracter vazio
    string p = "", c = ""; 

    // Atribuindo primeiro caracter da string
    p += m[0]; 
    
    int codigo = 256; 
    vector<int> codigoSaida; 
    
    // Até o final da string de entrada
    for (int i = 0; i < m.length(); i++) { 
    
        if (i != m.length() - 1) // Se não for último caracter
            c += m[i + 1]; // c recebe o próximo caracter da string
    
        // Se "p + c" já está presente na dicionario
        if (dicionario.find(p + c) != dicionario.end())
            p = p + c; 
        
        // Caso contrário
        else { 

            codigoSaida.push_back(dicionario[p]); // Código de saída para p
            // Adiciona "p + c" no dicionario
            dicionario[p + c] = codigo; 
            codigo++; 
            p = c; 
        } 

        c = ""; 
    }

    codigoSaida.push_back(dicionario[p]); 
    return codigoSaida;

}

string gerarStringCodigoLZW(vector<int> c){

    stringstream smsg;

    copy(c.begin(),c.end(),ostream_iterator<int>(smsg,""));

    string msg = smsg.str();
    
    msg = msg.substr(0,msg.length());

    return msg;

}
