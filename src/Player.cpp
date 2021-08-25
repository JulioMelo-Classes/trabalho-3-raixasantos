#include "Player.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool Player::find_solution(vector<string> & maze, pair<int, int> head, int currentDirection){
    int x = head.first,
        y = head.second;

    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[i].size(); j++){
            switch (currentDirection)
            {
            case 0:
                if(maze[x][y-1] == ' '){ // left
                    visited.push_back(make_pair(x,y--));
                    nextDirection = LEFT;
                    return true;
                }
                else if(maze[x-1][y] == ' '){ // up
                    visited.push_back(make_pair(x--,y));
                    nextDirection = UP;
                    return true;
                }
                else if(maze[x+1][y] == ' '){ // down
                    visited.push_back(make_pair(x++,y));
                    nextDirection = DOWN;
                    return true;
                }
                break;
            case 1:
                if(maze[x][y+1] == ' '){ // right
                    visited.push_back(make_pair(x,y++));
                    nextDirection = RIGHT;
                    return true;
                }
                else if(maze[x-1][y] == ' '){ // up
                    visited.push_back(make_pair(x--,y));
                    nextDirection = UP;
                    return true;
                }
                else if(maze[x+1][y] == ' '){ // down
                    visited.push_back(make_pair(x++,y));
                    nextDirection = DOWN;
                    return true;
                }
                break;
            case 2:
                if(maze[x-1][y] == ' '){ // up
                    visited.push_back(make_pair(x--,y));
                    nextDirection = UP;
                    return true;
                }
                else if(maze[x][y-1] == ' '){ // left
                    visited.push_back(make_pair(x,y--));
                    nextDirection = LEFT;
                    return true;
                }
                else if(maze[x][y+1] == ' '){ // right
                    visited.push_back(make_pair(x,y++));
                    nextDirection = RIGHT;
                    return true;
                }
                break;
            case 3:
                if(maze[x+1][y] == ' '){ // up
                    visited.push_back(make_pair(x++,y));
                    nextDirection = DOWN;
                    return true;
                }
                else if(maze[x][y-1] == ' '){ // left
                    visited.push_back(make_pair(x,y--));
                    nextDirection = LEFT;
                    return true;
                }
                else if(maze[x][y+1] == ' '){ // right
                    visited.push_back(make_pair(x,y++));
                    nextDirection = RIGHT;
                    return true;
                }
                break;
            }
            /*if(maze[x-1][y] == ' '){ // up
                visited.push_back(make_pair(x--,y));
                nextDirection = UP;
                return true;
            }
            else if(maze[x+1][y] == ' '){ // down
                visited.push_back(make_pair(x++,y));
                nextDirection = DOWN;
                return true;
            }
            else if(maze[x][y-1] == ' '){ // left
                visited.push_back(make_pair(x,y--));
                nextDirection = LEFT;
                return true;
            }
            else if(maze[x][y+1] == ' '){ // right
                visited.push_back(make_pair(x,y++));
                nextDirection = RIGHT;
                return true;
            }*/
        }
    }

    return false;
}

int Player::next_move(){
    return nextDirection;
}

bool Player::food_colision(pair<int, int> food, pair<int, int> head){
    if(food == head){
        return true;
    }
    return false;
}
