#include "SnakeGame.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

using namespace std;

SnakeGame::SnakeGame(){
    choice = "";
    frameCount = 0;
    levelMaze = 0;
    initialize_game();
}

/**
 * @brief função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms){
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void SnakeGame::initialize_game(){
    //carrega o nivel ou os níveis
    ifstream levelFile("../data/maze2.txt"); //só dá certo se o jogo for executado dentro da raíz do diretório (vc vai resolver esse problema pegando o arquivo da linha de comando)
    int lineCount = 0;
    string line;

    Level level;
    bool MapConfig = true;
    int posStartcount = 0; 

    if(levelFile.is_open()){
        while(getline(levelFile, line)){ //pega cada linha do arquivo
            if(lineCount == 0){
                posStartcount = 0;
                MapConfig = level.verify_map_settings(line);   
            }               
            if(lineCount > 0 && lineCount < level.get_rows()+1){ //ignora a primeira linha já que ela contem informações que não são uteis para esse exemplo
                for(int i = 0; i < line.size(); i++){
                    if(line[i] == '*'){
                        posStartcount++;
                        snake.set_start_position(lineCount-1, i);
                    }
                }
                maze.push_back(line);
            }
            if(lineCount == level.get_rows()){
                if(posStartcount != 1){
                    cout << "Formatação do mapa inválida! Tente novamente..." << endl;
                    MapConfig = false;
                }
            }
            cout << "Linha da vez: " << line << endl;
            //cout << "Linhas do mapa: " << level.get_rows() << endl; 
            cout << "lineCount: " << lineCount << endl;
            wait(500);
            lineCount++;

            if(lineCount == level.get_rows()+1){
                //maze.clear();
                if(MapConfig){
                    // dá o push_back() do level e do respectivo maze
                    mazes.push_back(maze);
                    levels.push_back(level);
                    // zerar o level e o maze
                    maze.clear();
                    cout << "Inserido o level e o maze" << endl;
                    wait(500);
                }     
                cout << "Estado MapConfig: " << MapConfig << endl;      
                MapConfig = true;                
                lineCount = 0;
            }
        }
    }
    if(!MapConfig || posStartcount != 1){
        state = GAME_OVER;
    }
    else{
        state = RUNNING;
        levelsCount = levels.size();
        cout << "Qtd de niveis: " << levelsCount;
        maze = mazes[levelMaze];
        levelMaze = 1;
    }
    cout << "State: " << state << endl;
}

void SnakeGame::process_actions(){
    //processa as entradas do jogador de acordo com o estado do jogo
    //nesse exemplo o jogo tem 3 estados, WAITING_USER, RUNNING e GAME_OVER.
    //no caso deste trabalho temos 2 tipos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch(state){
        case WAITING_USER: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
            cin>>std::ws>>choice;
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

void SnakeGame::update(){
    //atualiza o estado do jogo de acordo com o resultado da chamada de "process_input"
    switch(state){
        case RUNNING:
            if(frameCount>0 && frameCount%10 == 0) //depois de 10 frames o jogo pergunta se o usuário quer continuar
                state = WAITING_USER;
            break;
        case WAITING_USER: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if(choice == "n"){
                state = GAME_OVER;
                game_over();
            }
            else{
                //pode fazer alguma coisa antes de fazer isso aqui
                state = RUNNING;
            }
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

/**
 * @brief função auxiliar para limpar o terminal
 */
void clearScreen(){
//some C++ voodoo here ;D
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void SnakeGame::render(){
    clearScreen();
    switch(state){
        case RUNNING:
            cout << "----------PAINEL-----------------" << endl
                << "         Level: " << levelMaze << "       " << endl
                << "---------------------------------" << endl;
            //desenha todas as linhas do labirinto

            for(int i = 0; i < maze.size(); i++){
                for(int j = 0; j < maze[i].size(); j++){
                    if(make_pair(i,j) == snake.get_position())
                        cout << '<';
                    else
                        cout << maze[i][j];
                }
                cout << endl;
            }

            break;
        case WAITING_USER:
            cout<<"Você quer continuar com o jogo? (s/n)"<<endl;
            break;
        case GAME_OVER:
            cout<<"O jogo terminou!"<<endl;
            break;
    }
    frameCount++;
}

void SnakeGame::game_over(){
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(1000);// espera 1 segundo entre cada frame
    }
}
