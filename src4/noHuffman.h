#ifndef NOHUFF_H_INCLUDED
#define NOHUFF_H_INCLUDED

class NoHuff{

    private:
        char info; // Informação do nó
        int freq; // Frequência da informação
        NoHuff* esquerdo; // Filho à esquerda
        NoHuff* direito; // Filho à direita

    public:
        NoHuff(char info, int freq, NoHuff* direito, NoHuff* esquerdo); // Construtor
        // Gets
        char getInfo(); 
        int getFrequencia();
        NoHuff* getEsquerdo();
        NoHuff* getDireito(); 
        // Sets
        void setEsquerdo(NoHuff* no);
        void setDireito(NoHuff* no);
        void setInfo(char info);   
        void setFreq(int freq);

}; 

#endif // NOHUFF_H_INCLUDED