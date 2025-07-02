#include "Game.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Berry.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#include <iostream>
using namespace std;

Game::Game(int size) : s(size) {
    for (int i = 0; i < MAX_OBJECTS; ++i) {
        gameObjects[i] = nullptr;
    }
}

Game::~Game() {
    for (int i = 0; i < MAX_OBJECTS; ++i) {
        delete gameObjects[i];
        gameObjects[i] = nullptr;
    }
}

void Game::initGame() {
    // Create Pacman at (0,0)
    gameObjects[0] = new Pacman(0, 0);
    Pacman* pacman = dynamic_cast<Pacman*>(gameObjects[0]);
    if (pacman) pacman->setBoardSize(s, s);

    // Create Berry
    gameObjects[1] = new Berry();

    // Create multiple ghosts
    gameObjects[2] = new Ghost(5, 5);
    gameObjects[3] = new Ghost(10, 8);
	gameObjects[4] = new Berry(15, 15); // Optional: another Berry for variety
    // Set board size for ghosts
    for (int i = 2; i <= 3; ++i) {
        Ghost* ghost = dynamic_cast<Ghost*>(gameObjects[i]);
        if (ghost) ghost->setBoardSize(s, s);
    }
}

void Game::drawWorld() {
   
    cout << "+";
    for (int i = 0; i < s * 2; ++i) cout << "-";
    cout << "+\n";

    // Allocate board grid
    char** space = new char* [s];
    for (int i = 0; i < s; ++i) {
        space[i] = new char[s];
        for (int j = 0; j < s; ++j) {
            space[i][j] = ' ';
        }
    }

    // Place all game objects on the board
    for (int i = 0; i < MAX_OBJECTS; ++i) {
        if (gameObjects[i]) {
            int x = 0, y = 0;
            char symbol = ' ';

            if (Pacman* p = dynamic_cast<Pacman*>(gameObjects[i])) {
                x = p->getX();
                y = p->getY();
                symbol = p->getSymbol();
            }
            else if (Ghost* g = dynamic_cast<Ghost*>(gameObjects[i])) {
                x = g->getX();
                y = g->getY();
                symbol = g->getSymbol();
            }
            else if (Berry* b = dynamic_cast<Berry*>(gameObjects[i])) {
               
                x = b->getX();
                y = b->getY();
                symbol = b->getSymbol();
            }

            if (x >= 0 && x < s && y >= 0 && y < s) {
                space[y][x] = symbol;
            }
        }
    }

    // Draw board rows with side walls
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            cout << "|" << space[i][j];
        }
        cout << "|\n";
    }

    cout << "+";
    for (int i = 0; i < s * 2; ++i) cout << "-";
    cout << "+\n";

    // Clean up
    for (int i = 0; i < s; ++i) {
        delete[] space[i];
    }
    delete[] space;
}

Game::GameState Game::doTurn(char command) {
    Pacman* pacman = dynamic_cast<Pacman*>(gameObjects[0]);
  
    Berry* berry = dynamic_cast<Berry*>(gameObjects[1]);

    if (pacman) {
        pacman->move(command);
        PlaySound(TEXT("chomp.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    }

    // Ghost movement
    for (int i = 2; i < MAX_OBJECTS; ++i) {
        Ghost* ghost = dynamic_cast<Ghost*>(gameObjects[i]);
        if (ghost) {
            ghost->update();
        }
    }

    // Pacman eats Berry
    if (pacman && berry) {
        if (pacman->getX() == berry->getX() && pacman->getY() == berry->getY()) {
            pacman->setSuper(true);
            delete gameObjects[1];
            gameObjects[1] = nullptr;
            PlaySound(NULL, NULL, 0);
            PlaySound(TEXT("eatfruit.wav"), NULL, SND_FILENAME | SND_ASYNC); // 🎵 power up sound
            cout << "Pacman ate Berry and is now SUPER!\n";
        }
    }

    // Collision with Ghost
    for (int i = 2; i < MAX_OBJECTS; ++i) {
        Ghost* ghost = dynamic_cast<Ghost*>(gameObjects[i]);
        if (ghost && pacman) {
            if (pacman->getX() == ghost->getX() && pacman->getY() == ghost->getY()) {
                PlaySound(NULL, NULL, 0);  // Stop chomp sound

                if (pacman->getSuper()) {
                    delete gameObjects[i];
                    gameObjects[i] = nullptr;

                    PlaySound(TEXT("eatghost.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    cout << "Pacman ate a Ghost!\n";
                   
                }
                else {
                    PlaySound(TEXT("death.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    cout << "Pacman was caught by a Ghost! Game Over.\n";
                    return GameState::Lost;
                }

            }
        }
    }
 

    if (gameObjects[2]==nullptr&&gameObjects[3] == nullptr) {
        cout << "All ghosts eaten! You win!\n";
        return GameState::Won;
    }
    
    return GameState::Running;
}
