# Projeto 3: Snaze

  

Uma simulação do jogo clássico __Snake arcade video game__ com uma diferença: a cobra está presa dentro de um labirinto.

  

# Como compilar?

  

## Usando CMake...

A compilação e execução do trabalho será feita usando CMake, para executá-lo faremos:

  

  

```

  
  

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

  

Para executar com os arquivos de teste é necessário adicionar:

- local do arquivo;

- o modo de jogo que pode ser o __PACMAN__ ou o __CLASSIC__, exemplo com o maze1.txt;

- para funcionalidade 'loop': __-LOOP__ (Deve ser colocado após nome do arquivo);

- para funcionalidade 'random': __-RANDOM__ (Deve ser colocado após nome do arquivo).

  

  

No linux:

  

```

  

./snaze PACMAN ../data/maze1.txt -LOOP

  
  

```

  

No windows:

  

```

  

.\Debug\snaze.exe PACMAN ../data/maze1.txt -RANDOM

  

```

  

# Testes

> Cada mapa realiza um ou mais teste em relação as funcionalidade do snaze.

## maze 1

O mapa realiza o teste de backtracking da comida.

## maze 2

O mapa realiza o teste de passagem de fases.

## maze 3

O mapa realiza o teste de vitoria rápida.

## maze 4
 O mapa realiza o teste de colisão com a parede.

  

Desenvolvido por Danilo Aciole e Raíssa Santos.