// Pacman.cpp
#include "Pacman.h"
#include <conio.h>  // Windows only
#include <iostream>

Pacman::Pacman(int startX, int startY)
    : x(startX), y(startY), boardWidth(10), boardHeight(10), symbol('P') {
}

void Pacman::setBoardSize(int w, int h) {
    boardWidth = w;
    boardHeight = h;
}
void Pacman::setSuper(bool val) {
    isSuper = val;
    symbol = isSuper ? 'S' : 'P';  
}

bool Pacman::getSuper() const {
    return isSuper;
}

void Pacman::handleInput() {
    if (_kbhit()) {
        char ch = _getch();
        switch (ch) {
        case 'w': case 'W': if (y > 0) y--; break;              
        case 's': case 'S': if (y < boardHeight - 1) y++; break; 
        case 'a': case 'A': if (x > 0) x--; break;               
        case 'd': case 'D': if (x < boardWidth - 1) x++; break;  
        }
    }
}


void Pacman::update() {
    handleInput();
}
void Pacman::move(char command) {
    int newX = x;
    int newY = y;

    switch (command) {
    case 'w': // move up
        newY -= 1;
        break;
    case 'a': // move left
        newX -= 1;
        break;
    case 's': // move down
        newY += 1;
        break;
    case 'd': // move right
        newX += 1;
        break;
    default:
        return; // invalid input, do nothing
    }

    // Check bounds - assuming you have boardWidth and boardHeight stored in Pacman
    if (newX >= 0 && newX < boardWidth && newY >= 0 && newY < boardHeight) {
        x = newX;
        y = newY;
    }
    // else: ignore movement if out of bounds
}
void Pacman::draw() {
    std::cout << symbol;
}

int Pacman::getX() const { return x; }
int Pacman::getY() const { return y; }
char Pacman::getSymbol() const { return symbol; }
