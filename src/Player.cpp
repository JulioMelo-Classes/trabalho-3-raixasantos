#include "Player.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool Player::isSafe(vector<string> & maze, pair<int, int> position){
    if(maze[position.first][position.second] == ' ' || maze[position.first][position.second] == '*'){
        if(0 < position.first < maze.size() && 0 < position.second < maze[1].size() ){
            return true;
        }
    }
    return false;
}

bool Player::find_solution(vector<string> & maze, Snake & snake, pair<int, int> food){
    int x = snake.get_head_position().first,
        y = snake.get_head_position().second;
    
    cout << "Entrei na condição" << endl;
    switch (snake.get_head_direction()){
        case 'V':
            cout << "Olhando para cima" << endl;
            if(maze[x-1][y] == ' ')// keep
            {
                path.push_back(make_pair('V', make_pair(x-1,y)));
            }
            else if(isSafe(maze, make_pair(x,y-1)))// left
            {
                path.push_back(make_pair('>', make_pair(x,y)));
            }
            else if(isSafe(maze, make_pair(x,y+1)))// right
            {
                path.push_back(make_pair('<', make_pair(x,y)));
            }
            break;
        case '>':
            if(isSafe(maze, make_pair(x,y-1)))// keep
            {
                path.push_back(make_pair('>', make_pair(x,y-1)));
            }
            else if(isSafe(maze, make_pair(x+1,y)))// left
            {
                path.push_back(make_pair('A', make_pair(x,y)));
            }
            else if(isSafe(maze, make_pair(x-1,y)))// right
            {
                path.push_back(make_pair('V', make_pair(x,y)));
            }
            break;
        case 'A':
            if(isSafe(maze, make_pair(x+1,y)))// keep
            {
                path.push_back(make_pair('A', make_pair(x+1,y)));
            }
            else if(isSafe(maze, make_pair(x,y+1)))// left
            {
                path.push_back(make_pair('<', make_pair(x,y)));
            }
            else if(isSafe(maze, make_pair(x,y-1)))// right
            {
                path.push_back(make_pair('>', make_pair(x,y)));
            }
            break;
        case '<':
            if(isSafe(maze, make_pair(x,y+1)))// keep
            {
                path.push_back(make_pair('<', make_pair(x,y+1)));
            }
            else if(isSafe(maze, make_pair(x-1,y)))// left
            {
                path.push_back(make_pair('V', make_pair(x,y)));
            }
            else if(isSafe(maze, make_pair(x+1,y)))// right
            {
                path.push_back(make_pair('A', make_pair(x,y)));
            }
            break;
    }

    return false;
}

pair<char, pair<int, int>> Player::next_move(Snake & snake){
    if(!path.empty()){
        return path.back();    
    }
    return make_pair(snake.get_head_direction(), snake.get_head_position());
}

bool Player::food_colision(pair<int, int> food, pair<int, int> head){
    if(food == head){
        visited.clear();
        return true;
    }
    return false;
}

void Player::clear(){
    path.clear();
    visited.clear();
}
