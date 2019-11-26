#ifndef LZW_H_INCLUDED
#define LZW_H_INCLUDED

#include<vector>
#include<string>
#include<algorithm>

using namespace std;

/**
 * Algoritmo de compressao LZW que retorna um código
 *
 * @author caiosdeo
 * @param m string a ser comprimida
 * @return vector<int> codigo em int
 */
string comprimirLZW(string m);

/**
 * Retorna a string do codigo do LZW
 *
 * @author caiosdeo
 * @param c vector<int> codigo em int da compressao
 * @return string string do codigo 
 */
string gerarStringCodigoLZW(vector<int> *c);

#endif // LZW_H_INCLUDED