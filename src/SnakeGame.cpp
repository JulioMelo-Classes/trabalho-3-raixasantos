#include "SnakeGame.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

using namespace std;

SnakeGame::SnakeGame(int argc, char *argv[]){
    choice = "";
    currentLevel = 0;
    start = false;
    process_command_line(argc, argv);
    initialize_game();
}

/**
 * @brief função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms){
    this_thread::sleep_for(chrono::milliseconds(ms));
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

void SnakeGame::process_command_line(int argc, char *argv[]){
    GameMapsFile = "../data/maze1.txt"; 
    mode = PACMAN;

    if(argc == 3){
        if(string(argv[1]) == "CLASSIC"){ // TODO: ajeitar
            mode = CLASSIC;
        }
        if(argv[2] != ""){
            GameMapsFile = argv[2];
        }
    }
}

void SnakeGame::initialize_game(){
    Level level;
    bool MapConfig = true;
    int posStartCount = 0; 
    ifstream levelFile(GameMapsFile); 
    int lineCount = 0;
    string line;

    if(levelFile.is_open()){
        while(getline(levelFile, line)){ 
            if(lineCount == 0){
                posStartCount = 0;
                MapConfig = level.verify_map_settings(line);  
            }               
            if(lineCount > 0 && lineCount < level.get_rows()+1){
                for(int i = 0; i < line.size(); i++){
                    if(line[i] == '*'){
                        posStartCount++;
                        level.set_start_position(lineCount-1, i);
                    }
                }
                maze.push_back(line);
            }
            if(lineCount == level.get_rows()){
                if(posStartCount != 1){
                    cout << "Formatação do mapa inválida! Tente novamente..." << endl;
                    MapConfig = false;
                }
            }

            lineCount++;

            if(lineCount == level.get_rows()+1){
                if(MapConfig){
                    mazes.push_back(maze);
                    levels.push_back(level);
                }     
                lineCount = 0;
                maze.clear();
            }
        }
    }
    if(!MapConfig || posStartCount != 1 || levels.size() == 0){
        state = GAME_OVER;
    }
    else{
        state = RUNNING;
        levelsCount = levels.size();
        maze = mazes[currentLevel];
        currentLevel = 1;
    }
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
        case WAITING_USER_NEXT_LEVEL: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
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
            if(!start){
                levels[currentLevel-1].set_food_location(maze);
                snake.set_head_position(levels[currentLevel-1].get_start_position().first,
                                        levels[currentLevel-1].get_start_position().second);
                start = true;
            }

            player.find_solution(maze, snake.get_head_position(), snake.get_head_direction());
            snake.set_next_direction(player.next_move());

            if(player.food_colision(levels[currentLevel-1].get_foodLocation(), snake.get_head_position())){
                snake.food_eaten();
                levels[currentLevel-1].set_food_location(maze);
                if(mode == CLASSIC){
                    snake.add_tail();
                }
            }

            if(snake.get_foodEaten() == levels[currentLevel-1].get_foodsToEat()){
                if(currentLevel == levelsCount){
                    state = GAME_OVER;
                }
                else{
                    currentLevel++;
                    state = WAITING_USER;
                    // resetar as coisas
                }
            }
            break;
        
        case WAITING_USER_NEXT_LEVEL: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if(choice == "0"){
                mode = PACMAN;
            }
            else if(choice == "1"){
                mode = PACMAN;
            }
            state = RUNNING;
            break;
            
        case WAITING_USER: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if(choice == "n"){
                state = GAME_OVER;
                game_over();
            }
            else{
                // TODO: continuar
                // se choice == 1: PACMAN
                // se choice == 2: CLASSIC
                state = RUNNING;
            }
            break;
        
        default:
            //nada pra fazer aqui
            break;
    }
}

void SnakeGame::render(){
    clearScreen();
    switch(state){
        case RUNNING:        
            cout << "     Boas vindas ao SNAZE   " << endl // if(start == true && currentLevel == 1)
                << "------------------------------------------------------------------------" << endl
                << "Níveis carregados: " << levelsCount 
                << "| Vidas da snake: 5" 
                << "| Maçãs a serem comidas: " << levels[currentLevel-1].get_foodsToEat() << endl; 
            // TODO: separar
            cout << "------------------------------------------------------------------------" << endl
                << "Lives: " << snake.get_lives()
                << "| Score: " 
                << "| Maçãs comidas: " << snake.get_foodEaten() << " de "<< levels[currentLevel-1].get_foodsToEat() << endl
                << "------------------------------------------------------------------------" << endl; 

            cout << mode << endl;
            
            for(int i = 0; i < maze.size(); i++){
                for(int j = 0; j < maze[i].size(); j++){
                    if(snake.draw_snake(i,j))
                        NULL;
                    else if(make_pair(i,j) == levels[currentLevel-1].get_foodLocation())
                        cout << 'F';
                    else{ 
                        if(maze[i][j] == '*')
                            cout << ' ';
                        else
                            cout << maze[i][j];
                    }
                } 
                cout << endl;
            }
            break;
        case WAITING_USER:
            cout<<"Você quer continuar com o jogo? (s/n)"<<endl; // TODO: terminar
            break;
        case WAITING_USER_NEXT_LEVEL:
            cout<<"Você quer continuar no modo PACMAN ou CLASSIC? (0/1)"<<endl; // TODO: terminar
            break;
        case GAME_OVER:
            if(currentLevel == levelsCount){
                cout << "A cobra ganhou!" << endl;
            }
            cout<<"O jogo terminou!"<<endl;
            break;
    }
}

void SnakeGame::game_over(){
    // TODO: terminar
    // resetar as coisas
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(1000);// espera 1 segundo entre cada frame
    }
}
