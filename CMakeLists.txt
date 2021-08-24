cmake_minimum_required(VERSION 3.0.0)
project(snaze VERSION 0.1.0)

### Executável
# Diretório contendo os .h
include_directories( include )

# Cria um executável com nome "snaze", adiciona neste executável os arquivos .cpp
add_executable(snaze src/Snaze.cpp
                     src/SnakeGame.cpp
                     src/Level.cpp
                     src/Snake.cpp
                     src/Player.cpp)
