#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>
#include <list>

#include "Snake.h"

using namespace std;

class Player{
    private:
        Snake snake;
        vector<pair<int,int>> path;
        vector<pair<int,int>> visited;

    public:
        /**
        * @brief encontra um caminho para a cobra chegar até a comida
        * @return true, se encontrou um caminho. false, cc 
        **/
        bool find_solution();

        /**
        * @brief atualiza a direção em que a cobra deve seguir
        * @return retorna a direção para a cobra seguir
        **/
        pair<int, int> next_move();

        void Feed();
};

#endif