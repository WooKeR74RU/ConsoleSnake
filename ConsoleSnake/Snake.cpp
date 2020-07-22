#include "Snake.h"

#include "Utility.h"

Snake::Snake()
{
	x = 0;
	y = 0;
	tailLength = 15;
	dir = lastFrameDir = DIRECTION::RIGHT;
}
void Snake::inputHandling()
{
	if (isKeyDown('W') && lastFrameDir != DIRECTION::DOWN)
		dir = DIRECTION::UP;
	if (isKeyDown('D') && lastFrameDir != DIRECTION::LEFT)
		dir = DIRECTION::RIGHT;
	if (isKeyDown('S') && lastFrameDir != DIRECTION::UP)
		dir = DIRECTION::DOWN;
	if (isKeyDown('A') && lastFrameDir != DIRECTION::RIGHT)
		dir = DIRECTION::LEFT;
}
char Snake::getTailChar(DIRECTION cur, DIRECTION next)
{
	if (cur == DIRECTION::UP && next == DIRECTION::UP || cur == DIRECTION::DOWN && next == DIRECTION::DOWN)
		return (char)179;
	if (cur == DIRECTION::RIGHT && next == DIRECTION::RIGHT || cur == DIRECTION::LEFT && next == DIRECTION::LEFT)
		return (char)196;
	if (cur == DIRECTION::UP && next == DIRECTION::RIGHT || cur == DIRECTION::LEFT && next == DIRECTION::DOWN)
		return (char)218;
	if (cur == DIRECTION::UP && next == DIRECTION::LEFT || cur == DIRECTION::RIGHT && next == DIRECTION::DOWN)
		return (char)191;
	if (cur == DIRECTION::RIGHT && next == DIRECTION::UP || cur == DIRECTION::DOWN && next == DIRECTION::LEFT)
		return (char)217;
	if (cur == DIRECTION::DOWN && next == DIRECTION::RIGHT || cur == DIRECTION::LEFT && next == DIRECTION::UP)
		return (char)192;
}