#pragma once
#include "Entity.h"
#include <cstdlib>  // for rand
#include <ctime>    // for srand

class Ghost : public Entity {
public:
    Ghost(int startX = 0, int startY = 0);
    virtual ~Ghost() {}

    void update();    // move the ghost randomly
    void draw();      // draw the ghost symbol

    int getX() const;
    int getY() const;
    char getSymbol() const;

    void setBoardSize(int width, int height);

private:
    int x, y;              // current position on board
    int boardWidth, boardHeight;  // board boundaries
    char symbol;
};
