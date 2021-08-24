#include "Snake.h"

Snake::Snake(){
    life = 5;
    body cab;
    cab.character = '^';
    cab.posX = -1;
    cab.posY = -1;
    snakeBody.push_back(cab);
}

void Snake::add_body(){
    body tail;
    tail.character = 'o';
    tail.posX = (snakeBody.end()-1).posX;
    tail.posY = (snakeBody.end()-1).posY;
    snakeBody.push_back(tail);
}