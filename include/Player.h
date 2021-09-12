#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#include "Snake.h"

using namespace std;

class Player{
    public:
        enum Direction{ // 0: left, 1: right, 2: keep
            LEFT, 
            RIGHT, 
            KEEP
        };

    private:
        vector<pair<char, pair<int, int>>> path;
        vector<pair<char , pair<int, int>>> passou;
        Direction nextDirection;

        bool isSafe(vector<string> & maze, Snake & snake, pair<int, int> position);
    public:
        /**
        * @brief encontra um caminho para a cobra chegar até a comida
        * @return true, se encontrou um caminho. false, cc 
        **/
        bool find_solution(vector<string> & maze, Snake & snake, char character, pair<int, int> pos, pair<int, int> food);

        /**
        * @brief atualiza a direção em que a cobra deve seguir
        * @return retorna a direção para a cobra seguir
        **/
        pair<char, pair<int, int>> next_move(Snake & snake, vector<string> & maze, pair<int, int> food);

        /**
        * @brief Verifica se houve "colisão" com a fruta
        * @return true se "colidiu". false se não
        **/
        bool food_colision(pair<int, int> food, pair<int, int> head);

        /**
        * @brief Verifica se houve "colisão" com alguma parede
        * @return true se "colidiu". false cc
        **/
        bool wall_colision(vector<string> & maze, pair<int, int> head);

        /**
        * @brief Limpa os valores de todos os vetores
        **/
        void clear(vector<string> & maze);
};

#endif