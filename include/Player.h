#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>
#include <list>

#include "Snake.h"

using namespace std;

class Player{
    public:
        enum Direction{ // 0: left, 1: right, 2: up, 3: down
            LEFT, 
            RIGHT, 
            UP, 
            DOWN 
        };

    private:
        vector<pair<int,int>> path;
        vector<pair<int,int>> visited;
        Direction nextDirection;

    public:
        /**
        * @brief encontra um caminho para a cobra chegar até a comida
        * @return true, se encontrou um caminho. false, cc 
        **/
        bool find_solution(vector<string> & maze, pair<int, int> head);

        /**
        * @brief atualiza a direção em que a cobra deve seguir
        * @return retorna a direção para a cobra seguir
        **/
        int next_move();
};

#endif