#include "funcoesHuffman.h"
#include<cmath>

#include<iostream>
using namespace std;

// Funções para construir a árvore de Huffman
// Função de swap para vetor de nós de Huffman
void swap(NoHuff** huffHeap, int i, int j){

    NoHuff* aux;

    aux = huffHeap[i];
    huffHeap[i] = huffHeap[j];
    huffHeap[j] = aux;

}

// Constrói uma heap de mínimo
void heapify(NoHuff** huffHeap, unsigned tam, unsigned indice){
    
    unsigned menor = indice; // Pai
    unsigned esq = 2*indice + 1; // Filho da esquerda
    unsigned dir = 2*indice + 2; // Filho da direita

    // Atualiza menor valor se necessário
    if(esq < tam && huffHeap[esq]->getFrequencia() < huffHeap[menor]->getFrequencia()){
        menor = esq;
    }

    // Atualiza menor valor se necessário
    if(dir < tam && huffHeap[dir]->getFrequencia() < huffHeap[menor]->getFrequencia()){
        menor = dir;
    }

    // Confere se o menor não é o pai 
    if (menor != indice) {
        // Troca pai com o menor filho
        swap(huffHeap, indice, menor);
        heapify(huffHeap, tam, menor); // Chama heapify
    }

}

// Constrói a árvore de Huffman
NoHuff* huffTree(NoHuff** huffHeap, unsigned tam){

    // Auxiliares para os filhos à direita e à esquerda
    NoHuff* auxDir;
    NoHuff* auxEsq;

    while(tam > 1){

        // Constrói a heap de mínimo (menor da esquerda)
        for (int i = tam / 2 -1; i >= 0; i--)
            heapify(huffHeap, tam, i);

        auxEsq = huffHeap[0]; // retira menor frequência
        swap(huffHeap, 0, tam-1); // Desconsidera menor frequência retirada
        tam--;

        // Constrói a heap de mínimo (menor da direita)
        for (int i = tam / 2 -1; i >= 0; i--)
            heapify(huffHeap, tam, i);

        auxDir = huffHeap[0]; // retira menor frequência
        swap(huffHeap, 0, tam-1); // Desconsidera menor frequência retirada
        int novaFreq = auxDir->getFrequencia() + auxEsq->getFrequencia(); // Somando frequências dos filhos
        NoHuff* pai = new NoHuff(novaFreq, auxDir, auxEsq); // Alocando pai

        huffHeap[tam-1] = pai; // Colocando pai na huffHeap

    }

    return huffHeap[0]; // Retorna a raiz da árvore de Huffman

}

int* tabelaFrequencias(string m, unsigned n){

    int* tabela = (int*)calloc(n, sizeof(int)); // aloca tabela de frequências
    // Loop para contagem de frequências de cada caracter da mensagem m
    for(int i = 0; i < m.size(); i++)
        tabela[m[i]-' ']++;

    return tabela;

}

tuple<NoHuff**, int> gerarHuffHeap(int* tabelaFrequencias, unsigned n){

    // Calcula o tamanho do vetor de nós de huffman
    int t = 0;
    for(int i = 0; i < n; i++)
        if(tabelaFrequencias[i] > 0)
            t++;

    NoHuff** huffHeap = (NoHuff**)malloc(t*sizeof(NoHuff*)); // Aloca vetor de nós de huffman
    t = 0; // Reinicializa t com zero

    // Loop para inicializar vetor de nós de huffman
    for(int i = 0; i < n; i++){
        // Caractere existe na mensagem
        if(tabelaFrequencias[i] > 0){

            // Inicializa nó de huffman com o caractere válido da mensagem e sua respectiva frequência
            NoHuff* aux = new NoHuff(' ' + i, tabelaFrequencias[i]);
            huffHeap[t] = aux; // Insere nó no vetor
            t++; // Incrementa posição do vetor

        }

    }

    return make_tuple(huffHeap, t); // Retorna o vetor de nós de Huffman

}

string gerarMensagemCodificada(string m, string* codigos){

    string mensagemCodificada; // Declara mensagem codificada

    // Loop para codificar cada caractere da mensagem
    for(int i = 0; i < m.size(); i++)
        mensagemCodificada += codigos[m[i]-' '];

    return mensagemCodificada; // Retorna mensagem codificada em 0's e 1's

}

int gerarCodigoAscII(string s){

    int codigo = 0; // Inicializa somador do código ascii
    int t = s.size(); // Tamanho da string s

    // Converte binário para decimal nos bits de s
    for(int i = t - 1; i >= 0; i--)
        if(s[i] == '1')
            codigo += pow(2, i - t);

    return codigo; // Retorna código ascii

}

string compactarAscII(string mC){

    string aux; // String auxiliar
    string compactado; // Variável para string compactada
    int t = mC.size(); // Tamanho da mensagem

    // Loop para compactação da mensagem
    for(int i = 0, j = 0; i < t; i++, j = 0){

        // Pega 8 bits na string 
        for(; j < 7 || j + i < t; j++)
            aux += mC[i];

        // Gerando código para cada byte da string e concatenando na mensagem compactada
        compactado += gerarCodigoAscII(aux);
        aux = '\0';

        // Encerra compactação
        if(j+i == t)
            break;

    }

    return compactado; // Retorna string compactada
 
}

void gerarCodigo(NoHuff* raiz, string codigo, string* codigos){

    if(raiz != nullptr){

        // Buscando código pela esquerda
        if(raiz->getEsquerdo() != nullptr){

            codigo += '0';
            raiz = raiz->getEsquerdo();
            gerarCodigo(raiz, codigo, codigos);

        }
        // Buscando código pela direita
        if(raiz->getDireito() != nullptr){

            codigo += '1';
            raiz = raiz->getDireito();
            gerarCodigo(raiz, codigo, codigos);

        }
        // Se filho esquerdo e filho direito forem nulos, então é folha
        if(raiz->getEsquerdo() == nullptr && raiz->getDireito() == nullptr){
            cout << codigo << endl;
            codigos[raiz->getInfo()-' '] = codigo; // Se folha, recebe código final
            raiz = nullptr; // Encerra codificação

        }

    }

    return;

}

string compactarMensagemHuffman(string m, unsigned n){
    cout << m << endl;
    string mensagemCodificada; // Declara variável que conterá a mensagem codificada
    int* tab = tabelaFrequencias(m, n); // Calcula tabela de frequência dos caracteres
    NoHuff** huff;
    int t;
    tie(huff, t) = gerarHuffHeap(tab, n); // Gerar vetor de nós de huffman
    NoHuff* raiz = huffTree(huff, t); // Constrói árvore de Huffman retornando a raiz
    string* codigos = (string*)malloc(n*sizeof(string)); // Aloca vetor para armazenar códigos
    string auxCodigo; // Declara string auxiliar
    gerarCodigo(raiz, auxCodigo, codigos); // Gera vetor com códigos de cada caractere
    //exit(1);
    mensagemCodificada = gerarMensagemCodificada(m, codigos); // Codifica a mensagem
    return compactarAscII(mensagemCodificada); // Retorna mensagem compactada

}