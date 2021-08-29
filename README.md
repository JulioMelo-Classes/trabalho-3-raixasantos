# Projeto 3: Snaze

Uma simulação do jogo clássico __Snake arcade video game__ com uma diferença: a cobra está presa dentro de um labirinto.

# Como compilar?

## Usando CMake...
A compilação e execução do trabalho será feita usando CMake, para executá-lo faremos:

  

```

cd trabalho-3-raixasantos (ou o nome da pasta em que o projeto se encontra)

mkdir build && cd build

cmake ..

cmake --build .

```

  

# Como executar o projeto?

A compilação gera um executável com o nome __snaze__ dentro da pasta build, __no windows__ esse executável fica na pasta Debug. Logo após a compilação, para executar o programa gerado use os comandos:
  

No linux:

```

./snaze

```

No windows:

```

.\Debug\snaze.exe

```

  

## Como executar o conjunto dos testes planejados?

Para executar com os arquivos de teste é necessário adicionar o local do arquivo após o modo de jogo que pode ser o __PACMAN__ ou o __CLASSIC__, exemplo com o maze1.txt:

  

No linux:

```

./snaze PACMAN ../data/maze1.txt


```

No windows:

```

.\Debug\snaze.exe PACMAN ../data/maze1.txt

```

# Testes  

