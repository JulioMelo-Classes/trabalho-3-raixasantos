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
    score = 0;
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
        if(string(argv[1]) == "CLASSIC"){ 
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
        state = STARTING;
        levelsCount = levels.size();
        maze = mazes[currentLevel];
        currentLevel = 1;
    }
}

void SnakeGame::process_actions(){
    switch(state){
        case WAITING_PLAYER:
            cout << "("<<levels[currentLevel-1].get_foodLocation().first<<"|"
                <<levels[currentLevel-1].get_foodLocation().second << ")" << endl;
            player.find_solution(maze, snake, levels[currentLevel-1].get_foodLocation());
            wait(2000);
            snake.set_next_direction(player.next_move(snake));
            state = RUNNING;
            break;
        case WAITING_USER:
            cin>>ws>>choice;
            break;
        case WAITING_USER_NEXT_LEVEL:
            cin>>ws>>choice;
            break;
        default:
            break;
    }
}

void SnakeGame::update(){
    switch(state){
        case STARTING:
            levels[currentLevel-1].set_food_location(maze);
            snake.set_head_position(levels[currentLevel-1].get_start_position().first,
                                    levels[currentLevel-1].get_start_position().second);
            if(currentLevel > 1){
                state = RUNNING;
            }
            break;
        case RUNNING:

            
            if(player.food_colision(levels[currentLevel-1].get_foodLocation(), snake.get_head_position())){
                score += 200;   
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
                    maze = mazes[currentLevel-1];
                    state = WAITING_USER_NEXT_LEVEL;
                }
                game_over();
            }
            break;
        
        case WAITING_USER_NEXT_LEVEL: 
            if(choice == "p"){
                mode = PACMAN;
            }
            else if(choice == "c"){
                mode = CLASSIC;
            }
            state = STARTING;
            break;
            
        case WAITING_USER:
            if(choice == "n"){
                state = GAME_OVER;
                game_over();
            }
            else{
                state = RUNNING;
            }
            break;
        
        default:
            break;
    }
}

void SnakeGame::render(){
    clearScreen();
    switch(state){
        case STARTING: 
            if(currentLevel == 1){
                cout << "-------> Boas vindas ao SNAZE <-------" << endl                
                    << "------------------------------------------------------------------------" << endl
                    << "Níveis carregados: " << levelsCount 
                    << "| Vidas da snake: 5" 
                    << "| Maçãs a serem comidas: " << levels[currentLevel-1].get_foodsToEat() << endl
                    << "Vença todos os níveis para vencer o jogo. Boa sorte!" << endl
                    << "------------------------------------------------------------------------" << endl
                    << ">>>> Pressione <ENTER> para começar o jogo!" << endl;                    
                    fgetc(stdin);
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    state = WAITING_PLAYER;
            } else{
                cout << "Inciando nova fase no modo: " << mode << ". Divirta-se!!"<< endl;
            }             
            break;
        case RUNNING:       
            cout << "----------------------------------------------------" << endl
                << "Vida: " << snake.get_lives()
                << "| Score: " << score
                << "| Maçãs comidas: " << snake.get_foodEaten() << " de "<< levels[currentLevel-1].get_foodsToEat() << endl
                << "----------------------------------------------------" << endl; 
            
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
            state = WAITING_PLAYER;
            break;
        case WAITING_USER:
            cout << "Você quer continuar com o jogo? (s/n)" << endl;
            break;
        case WAITING_USER_NEXT_LEVEL:
            cout << "Você quer continuar no modo PACMAN ou CLASSIC? (p/c)" << endl;
            break;
        case GAME_OVER:
            if(currentLevel == levelsCount){
                cout << "A cobra ganhou!" << endl;
            }
            cout << "O jogo terminou!" << endl;
            break;
    }
}

void SnakeGame::game_over(){
    snake.reset(state);
    if(state == GAME_OVER){
        score = 0;
    }
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(1000);
    }
}
