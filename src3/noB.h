#ifndef NOB_H_INCLUDED
#define NOB_H_INCLUDED

class NoB{

    int *chaves;  // Um vetor de chaves 
    int d;      // ordem (define o alcance do número de filhos)
    NoB **filhos; // Um vetor de ponteiros para filhos
    int n;     // Número atual de chaves
    bool folha; // Verdadeiro se nó é uma folha e falso caso contrário
public: 
    NoB(int d, bool folha);   // Construtor 
  
    // Uma função que "caminha" por todos os nós de uma subárvore
    void percorrerSubarvore(); 
  
    // Uma função que procura uma chave k em uma subárvore     
    NoB *buscarChave(int k);   // retorna nullptr se a chave não for encontrada
  
    // Tornando os atributos do nó acessíveis para as funções da classe ArvoreB
    friend class ArvoreB;

}; 

#endif // NOB_H_INCLUDED