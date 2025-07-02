#include "Game.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
using namespace std;

int main() {
    const int boardSize = 20;
    Game game(boardSize);

    game.initGame();


    char command;
  /*  while (true) {
        game.drawworld();*/
     /*   cout << "enter wasd): ";
        cin >> command;
        cout << command;
        if (command == 'q') {
            cout << "quitting game.\n";
            break;
        }}*/

  
       
        Game::GameState state = Game::GameState::Running;

        while (state == Game::GameState::Running) {
            game.drawWorld();
           
            cout << "enter WASD): ";
            cin >> command;
           
            if (command == 'q') {
                cout << "quitting game.\n";
                break;

        
                /*     std::this_thread::sleep_for(std::chrono::milliseconds(200));*/
            }
           state =game.doTurn(command);
        }
            cout << "Game over! Press any key to exit...";
            _getch();

            return 0;



      
 
}
