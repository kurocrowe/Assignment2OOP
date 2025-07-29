#include "Ghost.h"
#include <iostream>

Ghost::Ghost(int startX, int startY)
    : x(startX), y(startY), symbol('G'), boardWidth(10), boardHeight(10)
{
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));  // seed random only once
        seeded = true;
    }
}

void Ghost::setBoardSize(int width, int height) {
    boardWidth = width;
    boardHeight = height;
}

void Ghost::update(int pacmanX, int pacmanY) {
    int oldX = x;
    int oldY = y;

    // Simple logic: move horizontally if not aligned, else move vertically
    if (x < pacmanX && x < boardWidth - 1) {
        x++; // move right
    }
    else if (x > pacmanX && x > 0) {
        x--; // move left
    }
    else if (y < pacmanY && y < boardHeight - 1) {
        y++; // move down
    }
    else if (y > pacmanY && y > 0) {
        y--; // move up
    }

    std::cout << "Ghost moved from (" << oldX << ", " << oldY << ") to (" << x << ", " << y << ")\n";
}


void Ghost::draw() {
    std::cout << symbol;
}

int Ghost::getX() const { return x; }
int Ghost::getY() const { return y; }
char Ghost::getSymbol() const { return symbol; }
