#include "Level.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Level::Level(){
    columns = 0;
    rows = 0;
    foodAmount = 0;
    snakePosStart = make_pair(-1,-1);
}

void Level::set_start_position(int x, int y){
    snakePosStart = make_pair(x, y);
}

pair<int, int> Level::get_start_position(){
    return snakePosStart;
}

int Level::get_columns(){
    return columns;
}

int Level::get_rows(){
    return rows;
}

int Level::get_foodsToEat(){
    return foodAmount;
}

pair<int, int> Level::get_foodLocation(){
    return foodLocation;
}

bool Level::verify_map_settings(string line_){
    stringstream ss;
    ss << line_;
    
    ss >> rows;
    if(rows <= 0 || rows > 100){
        cout << "Valor de linhas inválido! Tente novamente..." << endl;
        return false;
    }
    ss >> columns;
    if(columns <= 0 || columns > 100){ 
        cout << "Valor de colunas inválido! Tente novamente..." << endl;
        return false;
    }
    ss >> foodAmount;
    if(foodAmount <= 0){
        cout << "Valor de comidas no mapa inválido! Tente novamente..." << endl;
        return false;
    }

    return true;
}

void Level::set_food_location(vector<string> & maze, Snake & snake){
    vector<pair<int, int> > empty;

    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[i].size(); j++){
            if(!snake.isHere(make_pair(i, j), 0)){ 
                if(maze[i][j] == ' ' || maze[i][j] == '*')
                    empty.push_back(make_pair(i,j));
            }
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,empty.size()-1);
    int num = dist(gen);
    
    foodLocation = empty[num];
}

