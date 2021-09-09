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
        int food; //<! número de comidas já comidas
        int bodySize; //<! número de comidas pegas pela cobra + a cabeça
        vector<Body> snakeBody; //<! vector contendo as partes do corpo da cobra
        int currentDirection; //<! direção atual da cobra
        int nextDirection; //<! próxima direção da cobra
        pair<int, int> lastPosition; //<! coordenadas da posição anterior

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
        void set_next_direction(pair<char, pair<int, int>> next);

        void move();
        
        /**
        * @brief retorna a atual direção da cobra
        **/
        char get_head_direction();

        // a posição do novo body vai ser add/sub de acordo com a direção
        void add_tail();  

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
        * @brief retorna a posição da cabeça da cobra
        * @return o pair contendo as coordenadas x e y
        **/
        int get_lives();

        /**
        * @brief desenha a cabeça junto do rabo da cobra, caso sejam as coordenadas pertencentes a cobra
        * @param x linha a verificar se pertence a cobra
        * @param y coluna a verificar se pertence a cobra
        * @return true, se as coordenadas pertencerem e a parte da cobra for exibida. Caso contrário, false
        **/
        bool draw_snake(int x, int y);

        /**
        * @brief aumenta o tamanho da cobra, uma vez que ele comeu a comida
        **/
        void food_eaten();

        /**
        * @brief retorna a quantidade de comidas já comidas em um determinado nível
        * @return o inteiro contendo a quantidade de comidas já comidas
        **/
        int get_foodEaten();

        /**
        * @brief chamada quando o jogo termina a fim de destruir/resetar elementos da cobra
        **/
        void reset(int state);
};

#endif