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

bool Player::find_solution(vector<string> & maze, char character, pair<int, int> pos, pair<int, int> food){
        int x = pos.first,
            y = pos.second;
        
    if(pos == food){
        path.push_back(make_pair(character, pos));
        int i = 0;
        for(auto move:path){
            cout << i << ": " << move.first <<" | (" << (move.second).first << "," << (move.second).second << ")" << endl;
            i++;
        }
        return true;
    }
    for(auto posi:passou){
        if(posi == path.back()){
            return false;
        }
    }
    visited.push_back(pos);
    passou.push_back(make_pair(character, pos));

    switch (character){
        case 'V':
            if(isSafe(maze, make_pair(x-1,y)))// keep
            {
                path.push_back(make_pair('V', make_pair(x-1,y)));
                if(find_solution(maze, (path.back()).first,  (path.back()).second, food)){
                    return true;
                }
                else
                    path.pop_back();
            }
            else if(isSafe(maze, make_pair(x,y-1)))// left
            {
                path.push_back(make_pair('>', make_pair(x,y)));
                if(find_solution(maze, (path.back()).first,  (path.back()).second, food)){
                    return true;
                }
                else
                    path.pop_back();
            }
            else if(isSafe(maze, make_pair(x,y+1)))// right
            {
                path.push_back(make_pair('<', make_pair(x,y)));
                if(find_solution(maze, (path.back()).first,  (path.back()).second, food)){
                    return true;
                }
                else                    
                    path.pop_back();
            }
            break;
        case '>':
            if(isSafe(maze, make_pair(x,y-1)))// keep
            {
                path.push_back(make_pair('>', make_pair(x,y-1)));
                if(find_solution(maze, (path.back()).first,  (path.back()).second, food)){
                    return true;
                }
                else
                    path.pop_back();
            }
            else if(isSafe(maze, make_pair(x+1,y)))// left
            {
                path.push_back(make_pair('A', make_pair(x,y)));
                if(find_solution(maze, (path.back()).first,  (path.back()).second, food)){
                    return true;
                }
                else
                    path.pop_back();
            }
            else if(isSafe(maze, make_pair(x-1,y)))// right
            {
                path.push_back(make_pair('V', make_pair(x,y)));
                if(find_solution(maze, (path.back()).first,  (path.back()).second, food)){
                    return true;
                }
                else
                    path.pop_back();
            }
            break;
        case 'A':
            if(isSafe(maze, make_pair(x+1,y)))// keep
            {
                path.push_back(make_pair('A', make_pair(x+1,y)));
                if(find_solution(maze, (path.back()).first,  (path.back()).second, food)){
                    return true;
                }
                else
                    path.pop_back();
            }
            else if(isSafe(maze, make_pair(x,y+1)))// left
            {
                path.push_back(make_pair('<', make_pair(x,y)));
                if(find_solution(maze, (path.back()).first,  (path.back()).second, food)){
                    return true;
                }
                else
                    path.pop_back();
            }
            else if(isSafe(maze, make_pair(x,y-1)))// right
            {
                path.push_back(make_pair('>', make_pair(x,y)));
                if(find_solution(maze, (path.back()).first,  (path.back()).second, food)){
                    return true;
                }
                else 
                    path.pop_back();
            }
            break;
        case '<':
            if(isSafe(maze, make_pair(x,y+1)))// keep
            {
                path.push_back(make_pair('<', make_pair(x,y+1)));
                if(find_solution(maze, (path.back()).first,  (path.back()).second, food)){
                    return true;
                }
                else 
                    path.pop_back();
            }
            else if(isSafe(maze, make_pair(x-1,y)))// left
            {
                path.push_back(make_pair('V', make_pair(x,y)));
                if(find_solution(maze, (path.back()).first,  (path.back()).second, food)){
                    return true;
                }
                else 
                    path.pop_back();
            }
            else if(isSafe(maze, make_pair(x+1,y)))// right
            {
                path.push_back(make_pair('A', make_pair(x,y)));
                if(find_solution(maze, (path.back()).first,  (path.back()).second, food)){
                    return true;
                }
                else 
                    path.pop_back();
            }
            break;
    }

    return false;
}

pair<char, pair<int, int>> Player::next_move(Snake & snake){
    auto path_ = path.front();
    if(!path.empty()){
        path.erase(path.begin());
        return path_;    
    }
    else{
        auto random = snake.get_head_position();
        random.first--;
        return make_pair('V', random);
    }
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
    passou.clear();
}
