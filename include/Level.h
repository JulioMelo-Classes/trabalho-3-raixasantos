#ifndef Level_h
#define Level_h
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Level{
    private:
        int columns; //<! número de colunas
        int rows; //<! número de linhas
        int foodAmount; //<! número de comidas no mapa
        int foodLocation_x, foodLocation_y; //<! coordenadas atuais da comida

    public:
        /**
        * @brief processa as informações sobre o mapa passadas no arquivo
        * @param line linha do arquivo a ser processada
        * @return True, se não houve nenhuma informação inválida. Caso contrário, false
        **/
        bool verify_map_settings(string line);

        /**
        * @brief atualiza a posição da comida no mapa
        * @param maze vector que armazena o mapa
        **/
        void set_food_location(vector<string> & maze);
};

#endif