#include "Level.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool Level::verify_map_settings(string line){
    stringstream ss;
    ss << line;
    ss >> rows;
    if(rows <= 0 || rows > 100){
        cout << "Valor de linhas inválido! Tente novamente..." << endl;
        return false;
    }
    ss << line;
    ss >> columns;
    if(columns <= 0 || columns > 100){ 
        cout << "Valor de colunas inválido! Tente novamente..." << endl;
        return false;
    }
    ss << line;
    ss >> foodAmount;
    if(foodAmount <= 0){
        cout << "Valor de comidas no mapa inválido! Tente novamente..." << endl;
        return false;
    }

    return true;
}