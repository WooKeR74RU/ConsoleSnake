#pragma once

#include <deque>

#include "NonCopyable.h"
#include "NonMovable.h"
#include "Direction.h"

class Snake : public NonCopyable, public NonMovable
{
public:
	static const char headChar = 'S';
	int x;
	int y;
	DIRECTION dir;
	DIRECTION lastFrameDir;
	int tailLength;
	std::deque<DIRECTION> tail;

	Snake();
	void inputHandling();
	char getTailChar(DIRECTION cur, DIRECTION next);
};