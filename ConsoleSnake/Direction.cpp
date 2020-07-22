#include "Direction.h"

void move(int& x, int& y, DIRECTION dir, int fieldHeight, int fieldWidth)
{
	if (dir == DIRECTION::UP)
	{
		y--;
		if (y == -1)
			y = fieldHeight - 1;
	}
	if (dir == DIRECTION::RIGHT)
	{
		x++;
		if (x == fieldWidth)
			x = 0;
	}
	if (dir == DIRECTION::DOWN)
	{
		y++;
		if (y == fieldHeight)
			y = 0;
	}
	if (dir == DIRECTION::LEFT)
	{
		x--;
		if (x == -1)
			x = fieldWidth - 1;
	}
}
void moveBack(int& x, int& y, DIRECTION dir, int fieldHeight, int fieldWidth)
{
	if (dir == DIRECTION::UP)
	{
		y++;
		if (y == fieldHeight)
			y = 0;
	}
	if (dir == DIRECTION::RIGHT)
	{
		x--;
		if (x == -1)
			x = fieldWidth - 1;
	}
	if (dir == DIRECTION::DOWN)
	{
		y--;
		if (y == -1)
			y = fieldHeight - 1;
	}
	if (dir == DIRECTION::LEFT)
	{
		x++;
		if (x == fieldWidth)
			x = 0;
	}
}