#ifndef SnakeGame_h
#define SnakeGame_h

#include "Player.h"
#include "Level.h"
#include "Snake.h"

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class SnakeGame{
    public:
        /**
        * @brief descreve os possíveis estados do jogo, fique à vontade para adicionar outros se necessário
        **/
        enum GameStates{
            RUNNING, //<! quando o jogo está executando o estado é RUNNING
            GAME_OVER, //<! quando o jogo deve terminar o estado é GAME_OVER
            WAITING_USER, //<! quando o jogo deve esperar por uma entrada do usuário o estado é WAITING_USER
            WAITING_PLAYER //<! quando o jogo deve esperar pela IA (realmente necessário?)
        };
        
        /**
        * @brief descreve os possíveis modos do jogo
        **/
        enum GameModes{
            PACMAN, //<! modo de jogo em que a cobra não possui rabo
            CLASSIC //<! modo de jogo em que a cobra possui rabo
        };
    
    private:
        //<! atributos adicione outros se quiser
        vector<vector<string>> mazes; //<! vector contendo os labirintos dos níveis
        vector<string> maze; //<! vector contendo o labirinto atual, pode ser interpretado como uma matriz
        vector<Level> levels; //<! vector contendo os níveis
        int frameCount; //<! contador de frames, usado apenas como exemplo
        string choice; //<! usado na função process_actions para guardar a escolha do usuário
        GameStates state; //<! guarda o estado do jogo
        GameModes mode; //<! guarda o modo de jogo
        string GameMapsFile; //<! guarda o nome do arquivo que contem os mapas
        int levelsCount; //<! total de níveis do jogo
        int currentLevel;//<! determina qual o labirinto atual
        bool start; //<! determina se é a primeira vez que o nível está rodando

    public:
        /**
        * @brief construtor padrão, fique à vontade para adicionar parâmetros se desejar
        **/
        SnakeGame(int argc, char *argv[]);

        /**
        * @brief chamado no main, este loop executa o jogo indefinidamente até que o usuário escolha terminar!
        */
        void loop();

    private:
        /**
        * @brief processa as entradas da linha de comando
        **/
        void process_command_line(int argc, char *argv[]);

        /**
        * @brief realiza a inicialização geral do jogo, fique à vontade para adicionar parâmetros se achar que deve
        **/
        void initialize_game();

        /**
        * @brief atualiza o estado do jogo, basicamente movendo os objetos, sorteando novas posições de comida
        **/
        void update();

        /**
        * @brief processa as entradas do jogador
        **/
        void process_actions();

        /**
        * @brief testa o estado do jogo e desenha a tela correspondente
        **/
        void render();

        /**
        * @brief é chamada quando o jogo termina a fim de destruir/resetar elementos do estado do jogo
        **/
        void game_over();
};

#endif //SnakeGame_h