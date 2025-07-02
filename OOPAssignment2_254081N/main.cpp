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
//#ifdef _WIN32
//            system("cls");
//#else
//            system("clear");
//#endif
          
            cout << "Controls: W A S D to move. Try to eat all ghosts!\n";
            game.drawWorld();

            cout << "enter WASD): ";
            cin >> command;
            
            if (command == 'q') {
                cout << "quitting game.\n";
                break;
            }
                state = game.doTurn(command);


         /*   }
            std::this_thread::sleep_for(std::chrono::milliseconds(200));*/
            cout << "Status: " << game.getMessage() << "\n";
           
            

            
        }
      
            cout << "Game over! Press any key to exit...";
            _getch();

            return 0;



      
 
}
