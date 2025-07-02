#pragma once
#include "Entity.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Berry.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

class Game {
public:
    static const int MAX_OBJECTS = 8;
    Entity* gameObjects[MAX_OBJECTS];
    int s;  // board size

    Game(int size = 10);
    ~Game();
    enum class GameState {
        Running,
        Won,
        Lost
    };

    void initGame();
    void drawWorld();
   GameState doTurn(char command);
};
