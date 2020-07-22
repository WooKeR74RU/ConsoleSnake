#pragma once

enum class DIRECTION { UP, RIGHT, DOWN, LEFT };

void move(int& x, int& y, DIRECTION dir, int fieldHeight, int fieldWidth);
void moveBack(int& x, int& y, DIRECTION dir, int fieldHeight, int fieldWidth);