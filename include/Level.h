#ifndef Level_h
#define Level_h

#include "Snake.h"

#include <iostream>
#include <vector>
#include <list>
#include <random>

using namespace std;

class Level{
    private:
        int columns; //<! número de colunas
        int rows; //<! número de linhas
        int foodAmount; //<! número de comidas no mapa
        pair<int, int> foodLocation;//<! coordenadas atuais da comida First = x, Second = y
        pair<int, int> snakePosStart; //<! coordenadas do ponto em que a cobra vai começar First = x Second = y

    public:
        //<! Construtor
        Level();

        /**
        * @brief determina a posição inicial que a cobra vai ser desenhada
        * @param x linha que a cobra inicia
        * @param y coluna que a cobra inicia
        **/
        void set_start_position(int x, int y);

        /**
        * @brief retorna a posição de inicio da cobra nesse nível
        * @return o pair contendo as coordenadas x e y
        **/
        pair<int, int> get_start_position();

        /**
        * @brief acessar o valor de colunas
        * @return o valor referente a quantidade de colunas
        **/
        int get_columns();

        /**
        * @brief acessar o valor de linhas
        * @return o valor referente a quantidade de linhas
        **/
        int get_rows();

        /**
        * @brief acessar o valor de comidas
        * @return o valor referente a quantidade de comidas
        **/
        int get_foodsToEat();

        /**
        * @brief acessar a posição da comida
        * @return as coordenadas referentes a posição da comida
        **/    
        pair<int, int> get_foodLocation();

        /**
        * @brief processa as informações sobre o mapa passadas no arquivo
        * @param line linha do arquivo a ser processada
        * @return True, se não houve nenhuma informação inválida. Caso contrário, false
        **/
        bool verify_map_settings(string line_);

        /**
        * @brief atualiza a posição da comida no mapa
        * @param maze vector que armazena o mapa
        **/
        void set_food_location(vector<string> & maze, Snake & snake);
};

#endif