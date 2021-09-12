#include "Snake.h"

Snake::Snake(){
    life = 5;
    food = 0;
    Body cab;
    cab.character = '*';
    cab.posX = -1;
    cab.posY = -1;
    snakeBody.push_back(cab);
}

void Snake::set_head_direction(int x, int y, vector<string> & maze){
    if(maze[x-1][y] != '#' && maze[x+1][y] != '.')
        snakeBody[0].character = 'V';    
    else if(maze[x+1][y] != '#' && maze[x+1][y] != '.')
        snakeBody[0].character = 'A';
    else if(maze[x][y+1] != '#' && maze[x+1][y] != '.')
        snakeBody[0].character = '<';
    else
        snakeBody[0].character = '>';
    
}

void Snake::set_head_position(int x, int y, vector<string> & maze){
    snakeBody[0].posX = x;
    snakeBody[0].posY = y;

    set_head_direction(x, y, maze);    
}

pair<int, int> Snake::get_head_position(){
    return make_pair(snakeBody[0].posX, snakeBody[0].posY);
}

char Snake::get_head_direction(){
    return snakeBody[0].character;
}

void Snake::set_next_direction(pair<char, pair<int, int>> next){
    lastPosition = make_pair(snakeBody[0].posX,
                            snakeBody[0].posY);
    snakeBody[0].character = next.first;
    if(make_pair(snakeBody[0].posX, snakeBody[0].posY) != next.second){
        move_body();
        snakeBody[0].posX = (next.second).first;
        snakeBody[0].posY = (next.second).second;
    }
}

void Snake::move_body(){
    if(snakeBody.size() > 1){
        for (int i = snakeBody.size() - 1; i > 0; i--){
            snakeBody[i].posX = snakeBody[i - 1].posX;
            snakeBody[i].posY = snakeBody[i - 1].posY;
        }
    }
}

void Snake::add_tail(){
    Body tail;
    tail.character = 'o';
    tail.posX = lastPosition.first;
    tail.posY = lastPosition.second;
    snakeBody.push_back(tail);
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

int Snake::get_lives(){
    return life;
}

void Snake::food_eaten(){ 
    food++; 
}

int Snake::get_foodEaten(){
    return food;
}

void Snake::reset(int state){
    if(state == 4) // WAITING_USER
        life = 5;
    bodySize = 1;
    snakeBody.clear();
    Body cab;
    cab.character = 'V';
    cab.posX = -1;
    cab.posY = -1;
    snakeBody.push_back(cab);
    food = 0;
}

void Snake::hit_wall(){
    if(life > 0){
        this->life-- ;
    }
}

bool Snake::isHere(pair<int, int> position, int mode){
    for(int i = 0; i < snakeBody.size(); i++){
        if(snakeBody[i].posX == position.first && snakeBody[i].posY == position.second){
            if(i == 0){
                if(mode == 0) // modo que conta com cabeça
                    return true;
                else
                    return false;
            }
            else
                return true;
        }
    }
    return false;
}