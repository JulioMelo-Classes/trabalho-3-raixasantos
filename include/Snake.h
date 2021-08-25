#ifndef Snake_h
#define Snake_h
#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

struct Body{
    char character;
    int posX;
    int posY;
};

class Snake{
    private:
        int life; //<! número de vidas
        int bodySize; //<! número de comidas pegas pela cobra + a cabeça
        vector<Body> snakeBody; //<! vector contendo as partes do corpo da cobra
        int currentDirection; //<! direção atual da cobra
        int nextDirection; //<! próxima direção da cobra

    public:
        //! Construtor
        Snake();

    public:
        /**
        * @brief atualiza a posição da cabeça da cobra
        * @param x linha que a cobra inicia
        * @param y coluna que a cobra inicia
        **/
        void set_head_position(int x, int y);

        /**
        * @brief atualiza a próxima direção da cobra
        * @param x próxima direção da cobra
        **/
        void set_next_direction(int direction);
        
        /**
        * @brief retorna a atual direção da cobra
        **/
        int get_head_direction();

        // a posição do novo body vai ser add/sub de acordo com a direção
        void add_body();  

        /**
        * @brief movimenta a cabeça junto do rabo da cobra
        **/
        void move_body();

        /**
        * @brief retorna a posição da cabeça da cobra
        * @return o pair contendo as coordenadas x e y
        **/
        pair<int, int> get_head_position(); 

        /**
        * @brief desenha a cabeça junto do rabo da cobra, caso sejam as coordenadas pertencentes a cobra
        * @param x linha a verificar se pertence a cobra
        * @param y coluna a verificar se pertence a cobra
        * @return True, se as coordenadas pertencerem e a parte da cobra for exibida. Caso contrário, false
        **/
        bool draw_snake(int x, int y);
};

#endif