#ifndef Snake_h
#define Snake_h
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <random>

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
        * @param maze vector que armazena o mapa
        **/
        void set_head_position(int x, int y, vector<string> & maze);

        /**
        * @brief atualiza a posição da cabeça da cobra de forma aleatória
        * @param maze vector que armazena o mapa
        */ 
        void set_head_position_random(vector<string> & maze, int state);

        /**
        * @brief atualiza a direção da cabeça da cobra no inicio da partida
        * @param x linha que a cobra inicia
        * @param y coluna que a cobra inicia
        * @param maze vector que armazena o mapa
        **/
        void set_head_direction(int x, int y, vector<string> & maze);

        /**
        * @brief atualiza a próxima direção da cobra
        * @param next próxima direção da cobra: o caractere que representa a direção e a posição no mapa
        **/
        void set_next_direction(pair<char, pair<int, int>> next);
        
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
        * @param state especifica se deve ser reiniciar também a vida da cobra
        **/
        void reset(int state);

        /**
        * @brief diminui a quantidade de vidas da cobra, uma vez que ela bateu na parede
        **/
        void hit_wall();

        /**
        * @brief verifica se há alguma parte da cobra naquele espaço
        * @param position par de inteiros que representam a posição para ser verificada
        * @param mode especifica se deve ser verificada também a posição da cabeça da cobra
        * @return true, se as coordenadas pertencerem a cobra. Caso contrário, false
        **/
        bool isHere(pair<int, int> position, int mode);
};

#endif