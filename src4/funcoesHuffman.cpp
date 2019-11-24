#include "funcoesHuffman.h"
#include "noHuffman.h"
#include <cmath>
#include <bits/stdc++.h>

tuple<int*,vector<char>> tabelaFrequencias(string m, unsigned n){

    int* tabela = (int*)calloc(n, sizeof(int)); // aloca tabela de frequências
    int fT = 0; // Contador para número de caracteres válidos

    // Loop para contagem de frequências de cada caracter da mensagem m
    for(int i = 0; i < m.size(); i++)
        tabela[m[i]-' ']++;

    // Loop para contagem de caracteres válidos;
    for(int i = 0; i < n; i++)
        if(tabela[i] > 0)
            fT++;

    // Alocando memória para frequências e caracteres
    vector<char> caracteres;
    int* freqs = (int*)calloc(fT, sizeof(int));
    fT = 0;
    // Loop para inserir caracteres válidos
    for(int i = 0; i < n; i++){

        if(tabela[i] > 0){

            caracteres.push_back(' ' + i);
            freqs[fT] = tabela[i];
            fT++;

        }

    }

    return make_tuple(freqs, caracteres); // Retorna tupla com os caracteres e suas respectivas frequências

}

int posicaoCaractere(char c, vector<char> *infos){

    int i;

    for(i = 0; i < infos->size(); i++)
        if(c == infos->at(i))
            break;

    return i;

}

string gerarMensagemCodificada(string m, vector<string> *codigos, vector<char> *infos){

    string mensagemCodificada; // Declara mensagem codificada

    // Loop para codificar cada caractere da mensagem
    for(int i = 0; i < m.size(); i++)
        mensagemCodificada += codigos->at(posicaoCaractere(m[i], infos));

    return mensagemCodificada; // Retorna mensagem codificada em 0's e 1's

}

char gerarCodigoAscII(string s){

    int codigo = 0; // Inicializa somador do código ascii
    int t = s.size(); // Tamanho da string s

    // Converte binário para decimal nos bits de s
    for(int i = t - 1; i >= 0; i--)
        if(s[i] == '1')
            codigo += pow(2, t - 1 - i);

    return char(codigo + ' '); // Retorna código ascii

}

string compactarAscII(string mC){

    string aux; // String auxiliar
    string compactado; // Variável para string compactada
    int t = mC.size(); // Tamanho da mensagem
    int steps = t / 8; // Quantidade de passos de preenchimento de byte
    int resto = t % 8; // Quantidade de caracteres restante para codificação

    // Adiciona 8 bits à variável auxiliar e os codifica
    for(int i = 0; i < steps; i++){

        for(int j = 0; j < 7; j++)
            aux += mC[i+j];
        compactado += gerarCodigoAscII(aux);
        aux = '\0';

    }

    // Adiciona o restante dos bits à variável auxiliar
    for(int i = 0; i < resto; i++)
        aux += mC[t-1-i];

    compactado += gerarCodigoAscII(aux); // Codificando bits restantes

    return compactado; // Retorna string compactada
 
}

// Para comparação de dois nós da heap 
struct compara { 
  
    bool operator()(NoHuff* esq, NoHuff* dir) { 
        return (esq->getFrequencia() > dir->getFrequencia()); 
    } 

};

string comprimirHuffman(string str){

    NoHuff *esquerdo, *direito, *pai; 

    vector<char> infos;
    int* freq;
    
    tie(freq, infos) = tabelaFrequencias(str, 224); // 224 caracteres tabelas ascii
  
    // Cria heap minima  
    priority_queue<NoHuff*, vector<NoHuff*>, compara> minHeap; 
  
    // Insere todos os caracteres
    for (int i = 0; i < str.size(); ++i) 
        minHeap.push(new NoHuff(infos[i], freq[i])); 
  
    // Loop até o tamanho da heap ser 1 
    while (minHeap.size() != 1) { 
  
        // Extraindo os dois menos frequentes
        esquerdo = minHeap.top(); 
        minHeap.pop(); 
  
        direito = minHeap.top(); 
        minHeap.pop(); 
  
        // Cria um novo nó com frequência igual a soma dos dois nós anteriores
        // com info = '\0', valor para nós internos 
        pai = new NoHuff('\0', esquerdo->getFrequencia() + direito->getFrequencia()); 
  
        // Os nós extraídos se tornam filhos do novo nó.
        pai->setEsquerdo(esquerdo); 
        pai->setDireito(direito); 
  
        // Adiciona o nó na heap minima 
        minHeap.push(pai); 
    } 

    // Vetores auxiliares para armazenar info e seu respectivo codigo
    vector<string> codigos;

    // Gera o código para a árvore de Huffman criada
    gerarTabelaCodigos(minHeap.top(), "", &infos, &codigos);

    string mC = gerarMensagemCodificada(str, &codigos, &infos);
    // Desaloca estruturas
    delete[] freq;
    infos.clear();
    codigos.clear();
    // Retorna mensagem codificada
    return mC;

}

void gerarTabelaCodigos(NoHuff* raiz, string str, vector<char> *infos, vector<string> *codigos){ 

    // Se é raiz, não tem código
    if (!raiz) 
        return; 
  
    // Se é nó folha, adiciona a info e o codigo nos seus vetores
    if (raiz->getInfo() != '\0'){

        infos->push_back(raiz->getInfo());
        codigos->push_back(str);

    }

    // Chamada para filhos a esquerda e direita
    gerarTabelaCodigos(raiz->getEsquerdo(), str + "0", infos, codigos); 
    gerarTabelaCodigos(raiz->getDireito(), str + "1", infos, codigos); 

} 