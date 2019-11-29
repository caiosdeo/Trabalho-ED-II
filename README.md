# Trabalho-ED-II

Repositório destinado ao trabalho de Estrutura de Dados II 2019.3.

<h3>Grupo:</h3>

>[André Casarim](https://github.com/AndreCasarim)

>[Bernardo Yoshidome](https://github.com/Developer-Hannya)

>[Caio Oliveira](https://github.com/caiosdeo)

>[Elias Assis](https://github.com/eliascassis)

>[Paula Rinco](https://github.com/PaulaRRP)

<h3>Estrutura do Repositório</h3>

>[database](https://github.com/caiosdeo/Trabalho-ED-II/tree/master/database)

Diretório destinado aos arquivos usados para entrada do programa.

>[processamento](https://github.com/caiosdeo/Trabalho-ED-II/tree/master/processamento)

Neste repositório encontra-se scripts para tratamento dos dados gerados pela execução do programa. 
Assim como, scripts para pegar os dados tratados e gerar uma tabela em LaTeX dos mesmos.

>[src](https://github.com/caiosdeo/Trabalho-ED-II/tree/master/src)

Módulo 1, referente a primeira fase da primeira parte do trabalho. Onde testamos algoritmos de ordenação e tratamento de colisões de hash.

>[src2](https://github.com/caiosdeo/Trabalho-ED-II/tree/master/src2)

Módulo 2, referente a segunda fase da primeira parte do trabalho. Onde fizemos um programa para retornar categorias e usuários mais frequentes em um conjunto de dados.

>[src3](https://github.com/caiosdeo/Trabalho-ED-II/tree/master/src3)

Módulo 3, referente a primeira fase da segunda parte do trabalho. Onde testamos duas árvores em cenários de inserção e busca pelas mesmas.

>[src4](https://github.com/caiosdeo/Trabalho-ED-II/tree/master/src4)

Módulo 4, referente a segunda fase da segunda parte do trabalho. Onde testamos dois algoritmos de compressão diferentes, Huffman e LZW.

<h3>Compilação dos arquivos</h3>

Para que o projeto funcione como um todo, é necessária a compilação separada dos módulos.
    
Devido a organização feita na pasta *src*, é necessário que o comando para compilar seja:

    g++ -Ofast */*.cpp */*/*.cpp

Já para as pastas *src2*, *src3*, *src4* é necessário o seguinte comando: 
  
	g++ -Ofast *.cpp
    
Para executar o programa por completo temos que compilar um arquivo fora das pastas mencionadas.
A compilação é feita por: 
    
    g++ -Ofast *.cpp

<h3>Execução</h3>

Finalmente, para execução do programa é necessário estar na pasta raiz do repositório e entrar com o comando:

	./a.out