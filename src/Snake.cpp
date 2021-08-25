#include "Snake.h"

Snake::Snake(){
    life = 5;
    bodySize = 1;
    currentDirection = 2; // 2: up
    Body cab;
    cab.character = 'v';
    cab.posX = -1;
    cab.posY = -1;
    snakeBody.push_back(cab);
}

void Snake::set_head_position(int x, int y){
    snakeBody[0].posX = x;
    snakeBody[0].posY = y;
}

void Snake::set_next_direction(int direction){
    // 0: left, 1: right, 2: up, 3: down
    currentDirection = direction;
    if(direction == 0){
        snakeBody[0].character = '>';
        snakeBody[0].posY--;
    }
    else if(direction == 1){
        snakeBody[0].character = '<';
        snakeBody[0].posY++;
    }
    else if(direction == 2){
        snakeBody[0].character = 'v';
        snakeBody[0].posX--;
    }
    else if(direction == 3){
        snakeBody[0].character = '^';
        snakeBody[0].posX++;
    }
}
int Snake::get_head_direction(){
    return currentDirection;
}

void Snake::move_body(){

}

pair<int, int> Snake::get_head_position(){
    return make_pair(snakeBody[0].posX, snakeBody[0].posY);
}

bool Snake::draw_snake(int x, int y){
    for(int i = 0; i < snakeBody.size(); i++){
        if(snakeBody[i].posX == x && snakeBody[i].posY == y){
            cout << snakeBody[i].character;
            return true;
        }
    }
    return false;
}