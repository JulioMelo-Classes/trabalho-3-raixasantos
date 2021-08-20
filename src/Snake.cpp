#include "Snake.h"

Snake::Snake(){
    life = 5;
    bodySize = 0;
}

void Snake::set_start_position(int x, int y){
    snakePosStart = make_pair(x, y);
    snakePos.insert({'<', {snakePosStart.first, snakePosStart.second}}); // verificar qual direção desenhar a cabeça
}

pair<int, int> Snake::get_position(){
    // return make_pair(snakePos[0].second.first, snakePos[0].second.second); // depois de second, não tá conseguindo acessar 
    return make_pair(snakePosStart.first, snakePosStart.second);
}