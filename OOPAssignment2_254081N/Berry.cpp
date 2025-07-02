#include "Berry.h"

Berry::Berry(int startX, int startY)
    : x(startX), y(startY), symbol('B') {
}

int Berry::getX() const { return x; }
int Berry::getY() const { return y; }
char Berry::getSymbol() const { return symbol; }
