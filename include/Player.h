#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>
#include <list>

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
        vector<pair<int,int> > visited;
        Direction nextDirection;

        bool isSafe(vector<string> & maze, pair<int, int> position);
    public:
        /**
        * @brief encontra um caminho para a cobra chegar até a comida
        * @return true, se encontrou um caminho. false, cc 
        **/
        bool find_solution(vector<string> & maze, Snake & snake, pair<int, int> food);

        /**
        * @brief atualiza a direção em que a cobra deve seguir
        * @return retorna a direção para a cobra seguir
        **/
        pair<char, pair<int, int>> next_move(Snake & snake);

        /**
        * @brief Verifica se houve "colisão" com a fruta
        * @return true se "colidiu". false se não
        **/
        bool food_colision(pair<int, int> food, pair<int, int> head);

        void clear();
};

#endif