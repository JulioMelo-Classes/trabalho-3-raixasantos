#ifndef Snake_h
#define Snake_h
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Snake{
    private:
        int life; //<! número de vidas
        int bodySize; //<! tamanho da cobra(sem contar com a cabeça) e/ou quantidade de "comidas pegas"
        int posStart_x, posStart_y; //<! coordenadas do ponto em que a cobra vai começar

    public:
        //! Construtor
        Snake(); // life = 5, bodySize = 0
};

#endif