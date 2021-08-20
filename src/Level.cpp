#include "Level.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int Level::get_rows(){
    return rows;
}

bool Level::verify_map_settings(string line_){
    stringstream ss;
    ss << line_;
    ss >> rows;
    if(rows <= 0 || rows > 100){
        cout << "Valor de linhas inválido! Tente novamente..." << endl;
        return false;
    }
    ss << line_;
    ss >> columns;
    if(columns <= 0 || columns > 100){ 
        cout << "Valor de colunas inválido! Tente novamente..." << endl;
        return false;
    }
    ss << line_;
    ss >> foodAmount;
    if(foodAmount <= 0){
        cout << "Valor de comidas no mapa inválido! Tente novamente..." << endl;
        return false;
    }

    return true;
}