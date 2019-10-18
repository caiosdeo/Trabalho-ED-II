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
        NoB *buscarChave(int k, unsigned *numAcessos, unsigned *numComparacoes);   // retorna nullptr se a chave não for encontrada

        // Insere uma chave em um  nó não-cheio
        void inserirNaoCheio(int k, unsigned *numAcessos, unsigned *numComparacoes); 

        // Divide o filho y do nó. i é o índice de y no vetor de filhos do nó
        // y deve estar cheio quando essa função for chamada
        void dividirFilho(int i, NoB *y); 

        // Função para retornar o índice da primeira chave que é maior ou igual a k
        int encontrarChave(int k);

    private:
        void removerChave(int k); // Remove a chave do nó
        void removerDeFolha(int id); // Remove a chave na posição id de um nó-folha
        void removerDeNaoFolha(int id); // Remove a chave na posição id de um nó não-folha.
        int getPredecessor(int id); // Retorna o predecessor da chave de posição id
        int getSucessor(int id); // Retorna o sucessor da chave de posição id
        // Função para preencher o filho da posição id se esse filho não estiver cheio
        void preencher(int id); 
        void pegarEmprestadoAnterior(int id); // Pega chave emprestada do filho na posição id - 1
        void pegarEmprestadoProximo(int id); // Pega chave emprestada do filho na posição id + 1
        void intercalar(int id); // Intercala o filho id de um nó com o filho id + 1 
  
    // Tornando os atributos do nó acessíveis para as funções da classe ArvoreB
    friend class ArvoreB;

}; 

#endif // NOB_H_INCLUDED