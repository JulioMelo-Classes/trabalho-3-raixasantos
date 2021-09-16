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

# Avaliação CP2

## FindSolution.pacman

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo pacman.

**Avaiação**

ok

## FindSolution.snake

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo snake.

**Avaliação**

15% não leva em conta o corpo da cobra no algorítmo

## Random start

Deveria ser implementado na execução do programa um comando que permita que a posição inicial seja sorteada aleatoriamente. A posição inicial precisa ser válida e não deve causar a cobrinha/pacman iniciar em uma posição encurralada.

**Avaliação**

ok

## Level Loop

Deveria se implementado na execução do programa um comando que permite que os níveis fiquem se repetindo infinitamente, com a transição de mapas indo do primeiro nível até o último nível e voltando para o primeiro, de forma que seja mantida a contagem de pontos bem como a contagem de nível.

**Avaliação**

ok

## Organização / Compilação automatizada / Casos de Teste

Para a entrega final a organização do código em scr/data/include e compilação automatizada de alguma forma deve ser feita.

**Avaliação**

ok

## Documentação do código / Readme / Documentação de Casos de Teste

**Avaliação**

ok