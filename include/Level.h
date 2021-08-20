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
        pair<int, int> foodLocation;//<! coordenadas atuais da comida First = x, Second = y

    public:
        /**
        * @brief acessar o valor de linhas
        * @return o valor referente a quantidade de linhas
        **/
        int get_rows();

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
        void set_food_location(vector<string> & maze);
};

#endif