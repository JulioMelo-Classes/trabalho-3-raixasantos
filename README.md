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


## Avaliação CP1

### Snake/Pacman
O jogo deveria conter o modo snake/pacman. Em ambos os modos não é possível andar pra trás. No modo snake deve ser desenhado o corpo.

**Avaliação**

ok

### Render.ui
O jogo deveria desenhar a UI corretamente, mostrando ao menos as vidas, o nível e o score.

**Avaliação**

Ok

### Render.mapa
O jogo deveria desenhar o mapa corretamente, com base no arquivo passado como argumento.

**Avaliação**

ok

### Render.snake
O jogo deveria desenhar a snake corretamente.

**Avaliação**

ok

### Logic.colisão e Logic.comida
O jogo deve se comportar corretamente quando ocorre uma colisão com comida e com paredes.

**Avaliação**

vou considerar 60% uma vez que não existem colisões com as paredes!

### Transição de mapas
O jogo deve ter transição de mapa uma vez que um mapa é terminado.

**Avaliação**

ok

### Interação com o usuário
O jogo deve perguntar ao usuário se quer continuar/reiniciar o nível/reiniciar o jogo a cada transição de mapa

**Avaliação**

ok

### Classe Level ou similar
O software deve encapsular as funcionalidades do nível em uma classe.

**Avaliação**

Ok

### Classe Player ou similar
O software deve encapsular as decisões do jogo em uma classe.

**Avaliação**

Ok

### Classe Snake ou similar
O software deve encapsular as funcionalidades relacionadas à snake em uma classe. 

**Avaliação**

OK

## Comentários gerais CP1
- Acho que a implementação está muito boa, a organização no gameloop pattern também está muito boa.
- Da forma como está vocês poderiam implementar a colisão com paredes para entregar o jogo completo para o CP2. No entanto, acho que o que valeria mais era tentar encontrar a solução pro problema de encontrar a comida no mapa realmente.