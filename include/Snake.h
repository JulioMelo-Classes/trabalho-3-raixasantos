#ifndef Snake_h
#define Snake_h
#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

class Snake{
    private:
        int life; //<! número de vidas
        pair<int, int> snakePosStart; //<! coordenadas do ponto em que a cobra vai começar First = x Second = y
        int bodySize; //<! tamanho da cobra(sem contar com a cabeça) e/ou quantidade de "comidas pegas"
        map<char, pair<int, int>> snakePos; //<! coordenadas do corpo da cobra First = x Second = y
        
    public:
        //! Construtor
        Snake(); // life = 5, bodySize = 0

        /**
        * @brief determina a posição inicial que a cobra vai ser desenhada
        * @param x linha que a cobra inicia
        * @param y coluna que a cobra inicia
        **/
        void set_start_position(int x, int y);

        /**
        * @brief retorna a posição atual da cobra
        * @return o pair contendo as coordenadas x e y
        **/
        pair<int, int> get_position();
};

#endif