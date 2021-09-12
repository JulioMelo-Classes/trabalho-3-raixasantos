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
    isLooping = false;
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

    if(argc >= 3){
        if(string(argv[1]) == "CLASSIC"){ 
            mode = CLASSIC;
        }
        if(argv[2] != ""){
            GameMapsFile = argv[2];
        }
        if(argc == 4){
            if(string(argv[3]) == "-LOOP"){
                isLooping = true;
            }
        }
        if(argc == 5){
            if(string(argv[3]) == "-RANDOM"){
                // começo em posição aleatória
            }
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
            player.find_solution(maze, snake, snake.get_head_direction(), 
                                snake.get_head_position(), levels[currentLevel-1].get_foodLocation());  
            snake.set_next_direction(player.next_move(snake, maze, levels[currentLevel-1].get_foodLocation()));
            state = RUNNING;
            // wait(800);
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
            levels[currentLevel-1].set_food_location(maze, snake);
            snake.set_head_position(levels[currentLevel-1].get_start_position().first,
                                    levels[currentLevel-1].get_start_position().second);
            if(currentLevel > 1 || isLooping){
                state = RUNNING;
            }
            break;
        case RUNNING:  
            if(player.food_colision(levels[currentLevel-1].get_foodLocation(), snake.get_head_position())){
                score += 200;   
                snake.food_eaten();
                levels[currentLevel-1].set_food_location(maze, snake); 
                player.clear(maze);   
                if(mode == CLASSIC){
                    snake.add_tail();
                }          
            }   
            // colisão com a parede e a própria cobra
            if(player.wall_colision(maze, snake.get_head_position()) 
                || snake.isHere(snake.get_head_position(), 1))
            {
                if(score >= 100){
                    score -= 100;
                }
                snake.hit_wall();
                player.clear(maze);
                game_over();
                snake.set_head_position(levels[currentLevel-1].get_start_position().first,
                                        levels[currentLevel-1].get_start_position().second);
            }
            if(snake.get_lives() == 0){
                state = WAITING_USER; // tava GAME_OVER
                game_over();
            }
            if(snake.get_foodEaten() == levels[currentLevel-1].get_foodsToEat()){ 
                    if(currentLevel == levelsCount){
                        state = WAITING_USER; // tava GAME_OVER
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
            }
            else{
                state = STARTING;
                isLooping = true;
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
            if(currentLevel == 1 && !isLooping)
                print_menu_initially(); 
            break;
        case RUNNING:       
            print_round();
            print_map();  
            state = WAITING_PLAYER;
            break;
        case WAITING_USER:
            if(snake.get_lives() == 0) // rever(por causa da reset antes de chegar aqui) ou tirar
            {
                cout << "A cobra ganhou!" << endl;
            }else
            {
                cout << "A cobra morreu;-;!" << endl;
            }
            cout << "Você deseja jogar novamente? (s/n)" << endl;
            break;
        case WAITING_USER_NEXT_LEVEL:
            cout << "Você quer continuar no modo PACMAN ou CLASSIC? (p/c)" << endl;
            break;
        case GAME_OVER:                                            
            cout << "O jogo terminou!" << endl;
            break;
    }
}

void SnakeGame::game_over(){
    if(state == WAITING_USER){ // tava GAME_OVER
        currentLevel = 1;
        maze = mazes[currentLevel-1];
        score = 0;
    }
    levels[currentLevel-1].set_food_location(maze, snake); 
    snake.reset(state);
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(500);
    }
}

void SnakeGame::print_menu_initially(){
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
}

void SnakeGame::print_map(){
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
}

void SnakeGame::print_round(){
    cout << "----------------------------------------------------" << endl
        << "Nível: " << currentLevel
        << "| Vida: " << snake.get_lives()
        << "| Score: " << score
        << "| Maçãs comidas: " << snake.get_foodEaten() << " de "<< levels[currentLevel-1].get_foodsToEat() << endl
        << "----------------------------------------------------" << endl;             
}
