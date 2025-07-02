#ifndef GAME_H
#define GAME_H
#include "Game.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Berry.h"
#include "Entity.h"
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#include <iostream>
using namespace std;
#include <string>

class GameObject;   // Forward declaration
class Pacman;
class Ghost;
class Berry;

class Game {
public:
    enum class GameState {
        Running,
        Won,
        Lost
    };

    static const int MAX_OBJECTS = 10;

private:
    int s;  // board size
    int turn = 0;
    Entity* gameObjects[MAX_OBJECTS];
    std::string message;  // stores message to display

public:
    Game(int size);
    ~Game();

    void initGame();
    void drawWorld();
    GameState doTurn(char command);

    // Message management
    void setMessage(const std::string& msg) { message = msg; }
    const std::string& getMessage() const { return message; }
};

#endif // GAME_H
