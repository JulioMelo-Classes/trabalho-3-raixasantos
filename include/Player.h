#ifndef Player_h
#define Player_h

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#include "Snake.h"

using namespace std;

class Player{
    private:
        vector<pair<char, pair<int, int>>> path;
        vector<pair<char , pair<int, int>>> passou;

        bool isSafe(vector<string> & maze, Snake & snake, pair<int, int> position);
    public:
        /**
        * @brief encontra um caminho para a cobra chegar até a comida
        * @param maze vector que armazena o mapa
        * @param snake o objeto para realizar verificações
        * @param character char que representa direção atual da cobra
        * @param pos par que representa a posição atual da cobra
        * @param food par que representa a posição da comida
        * @return true, se encontrou um caminho. false, cc 
        **/
        bool find_solution(vector<string> & maze, Snake & snake, char character, pair<int, int> pos, pair<int, int> food);

        /**
        * @brief atualiza a direção em que a cobra deve seguir
        * @param snake o objeto para realizar verificações
        * @param maze vector que armazena o mapa
        * @param food par que representa a posição da comida
        * @return retorna a direção para a cobra seguir
        **/
        pair<char, pair<int, int>> next_move(Snake & snake, vector<string> & maze, pair<int, int> food);

        /**
        * @brief Verifica se houve "colisão" com a fruta
        * @param food par que representa a posição da comida
        * @param head par que representa a posição da cabeça da cobra
        * @return true se "colidiu" com a comida. false se não
        **/
        bool food_colision(pair<int, int> food, pair<int, int> head);

        /**
        * @brief Verifica se houve "colisão" com alguma parede
        * @param maze vector que armazena o mapa
        * @param head par que representa a posição da cabeça da cobra
        * @return true se "colidiu" com a parede. false cc
        **/
        bool wall_colision(vector<string> & maze, pair<int, int> head);

        /**
        * @brief Limpa os valores de todos os vetores
        * @param maze vector que armazena o mapa
        **/
        void clear(vector<string> & maze);
};

#endif