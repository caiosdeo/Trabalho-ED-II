#include "funcoesHuffman.h"
#include "noHuffman.h"
#include <cmath>
#include <bits/stdc++.h>
#include<stdlib.h>

tuple<int*,char*, int> tabelaFrequencias(string m, int n){

    int* tabela = (int*)calloc(n,sizeof(int)); // aloca tabela de frequências
    int fT = 0; // Contador para número de caracteres válidos

    // Loop para contagem de frequências de cada caracter da mensagem m
    for(int i = 0; i < m.size(); i++)
        tabela[m[i]-' ']++;

    // Loop para contagem de caracteres válidos;
    for(int i = 0; i < n; i++)
        if(tabela[i] > 0)
            fT++;

    // Alocando memória para frequências e caracteres
    char *caracteres = (char*)malloc(fT*sizeof(char));
    int* freqs = (int*)calloc(fT, sizeof(int));
    fT = 0;
    // Loop para inserir caracteres válidos
    for(int i = 0; i < n; i++){

        if(tabela[i] > 0){

            caracteres[fT] = ' ' + i;
            freqs[fT] = tabela[i];
            fT++;

        }

    }

    return make_tuple(freqs, caracteres, fT); // Retorna tupla com os caracteres e suas respectivas frequências

}

int posicaoCaractere(char c, char *infos, int t){

    int i;

    // Encontra a posição do caractere no vetor de caracteres
    for(i = 0; i < t; i++)
        if(c == infos[i])
            break;

    return (i < t) ? i : i - 1;

}

string gerarMensagemCodificada(string m, char **codigos, char *infos, int t){

    string mensagemCodificada = ""; // Declara mensagem codificada
    int tAux; // Tamanho auxiliar para vetor de caracteres

    // Loop para codificar cada caractere da mensagem
    for(int i = 0; i < m.size(); i++){

        tAux = strlen(codigos[posicaoCaractere(m[i],infos,t)]);
        for(int j = 0; j < tAux; j++)
            mensagemCodificada += codigos[posicaoCaractere(m[i],infos,t)][j]; 

    }

    free(codigos); // Desaloca codigos

    mensagemCodificada += '\0'; 
    cout << mensagemCodificada << endl;
    cout << endl;

    return mensagemCodificada; // Retorna mensagem codificada em 0's e 1's

}

char gerarCodigoAscII(string s){

    int codigo = 0; // Inicializa somador do código ascii
    int t = s.size(); // Tamanho da string s

    // Converte binário para decimal nos bits de s
    for(int i = t - 1; i >= 0; i--)
        if(s[i] == '1')
            codigo += pow(2, t - 1 - i);

    return char(codigo + ' ' + 1); // Retorna código ascii

}

string compactarAscII(string mC){

    string aux = ""; // String auxiliar
    string compactado = ""; // Variável para string compactada
    int t = mC.size(); // Tamanho da mensagem
    int steps = t / 8; // Quantidade de passos de preenchimento de byte
    int resto = t % 8; // Quantidade de caracteres restante para codificação

    // Adiciona 8 bits à variável auxiliar e os codifica
    for(int i = 0; i < steps; i++){

        for(int j = 0; j < 7; j++)
            aux += mC[i+j];

        compactado += gerarCodigoAscII(aux);
        aux = "";

    }

    // Adiciona o restante dos bits à variável auxiliar
    for(int i = 0; i < resto; i++)
        aux += mC[t-1-i];

    compactado += gerarCodigoAscII(aux); // Codificando bits restantes
    compactado += '\0';
    cout << compactado << endl;
    exit(1);
    return compactado += '\0'; // Retorna string compactada
 
}

// Para comparação de dois nós da heap 
struct compara { 
  
    bool operator()(NoHuff* esq, NoHuff* dir) { 
        return (esq->getFrequencia() > dir->getFrequencia()); 
    } 

};

string comprimirHuffman(string str){
    cout << str << endl;
    cout << endl;
    str += '\0';
    NoHuff *esquerdo, *direito, *pai; 

    char *infos;
    int *freq;
    int fT;
    
    tie(freq, infos, fT) = tabelaFrequencias(str, 223); // 223 caracteres tabelas ascii

    // Cria heap minima  
    priority_queue<NoHuff*, vector<NoHuff*>, compara> minHeap; 
  
    // Insere todos os caracteres
    for (int i = 0; i < fT; i++) 
        minHeap.push(new NoHuff(infos[i], freq[i], nullptr, nullptr)); 
  
    // Loop até o tamanho da heap ser 1 
    while (minHeap.size() != 1) { 
  
        // Extraindo os dois menos frequentes
        esquerdo = minHeap.top(); 
        minHeap.pop(); 
  
        direito = minHeap.top(); 
        minHeap.pop(); 
  
        // Cria um novo nó com frequência igual a soma dos dois nós anteriores
        // com info = 0, valor para nós internos 
        pai = new NoHuff(0, esquerdo->getFrequencia() + direito->getFrequencia(), nullptr, nullptr); 
  
        // Os nós extraídos se tornam filhos do novo nó.
        pai->setEsquerdo(esquerdo); 
        pai->setDireito(direito); 
  
        // Adiciona o nó na heap minima 
        minHeap.push(pai); 
    } 

    // Vetor auxiliares para armazenar código de respectiva info
    char** codigos = (char**)malloc(fT*sizeof(char*));

    // Gera o código para a árvore de Huffman criada
    gerarTabelaCodigos(minHeap.top(), "", infos, codigos, fT);

    string mC = gerarMensagemCodificada(str, codigos, infos, fT);

    // Retorna mensagem compactada
    return compactarAscII(mC);

}

void gerarTabelaCodigos(NoHuff* raiz, string str, char *infos, char **codigos, int t){ 

    // Se nulo, interrompe a codificação
    if(!raiz)
        return;

    // Se folha, armazena codificação
    if(raiz->getInfo() != 0){

        int posicao = posicaoCaractere(raiz->getInfo(), infos, t);
        str += '\0';
        int tStr = str.size();
        codigos[posicao] = (char*)malloc(tStr*sizeof(char));
        for(int i = 0; i < tStr; i++)
            codigos[posicao][i] = str[i];

    }

    // Se não-folha, continua busca por folha à esquerda e à direita
    gerarTabelaCodigos(raiz->getEsquerdo(), str + '0', infos, codigos, t);
    gerarTabelaCodigos(raiz->getDireito(), str + '1', infos, codigos, t); 

} 