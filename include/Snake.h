#ifndef Snake_h
#define Snake_h
#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

struct body{
    char character;
    int posX;
    int posY;
};

class Snake{
    private:
        int life; //<! número de vidas
        map<char, pair<int, int>> snakePos; //<! coordenadas do corpo da cobra First = x Second = y
        vector<body> snakeBody; //<! vector contendo as partes do corpo da cobra

    public:
        //! Construtor
        Snake(); // life = 5, bodySize = 0
        
        void add_body();
};

#endif