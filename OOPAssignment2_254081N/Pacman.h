#pragma once
#include "Entity.h"

class Pacman : public Entity {
    // add after includes and public methods:


public:
    Pacman(int startX = 0, int startY = 0);
    virtual ~Pacman() {}
    void setSuper(bool val);
    bool getSuper() const;

    bool update() ;   // move based on keyboard input
    void draw() ;     // draw the Pacman symbol

    int getX() const;
    int getY() const;
    char getSymbol() const;
    void move(char command);
    void setBoardSize(int w, int h);

private:
    int x, y;
    int boardWidth, boardHeight;
    char symbol;
    bool isSuper = false;
    void handleInput();
};
