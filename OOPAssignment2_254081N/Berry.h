#pragma once
#include "Entity.h"

class Berry : public Entity {
public:
    Berry(int x = 3, int y = 3);  // default position

    int getX() const;
    int getY() const;
    char getSymbol() const;

private:
    int x, y;
    char symbol;
};
