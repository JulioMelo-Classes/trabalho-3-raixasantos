#include "Player.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool Player::find_solution(){
    return true;
}

pair<int, int> Player::next_move(){
    return make_pair(0,0);
}
void Player::Feed(){
    body tail;
    tail.posX = (snake.snakeBody.end()-1).posX;
    tail.posY = (snakeBody.end()-1).posY;
    snakeBody.push_back(tail);
}