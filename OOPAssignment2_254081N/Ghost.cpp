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

void Ghost::update() {
    int oldX = x;
    int oldY = y;

    int dir = rand() % 4;
    switch (dir) {
    case 0: if (x > 0) x--; break;               // move left
    case 1: if (x < boardWidth - 1) x++; break; // move right
    case 2: if (y > 0) y--; break;               // move up
    case 3: if (y < boardHeight - 1) y++; break;// move down
    }

  
    std::cout << "Ghost moved from (" << oldX << ", " << oldY << ") to (" << x << ", " << y << ")\n";
}

void Ghost::draw() {
    std::cout << symbol;
}

int Ghost::getX() const { return x; }
int Ghost::getY() const { return y; }
char Ghost::getSymbol() const { return symbol; }
