#pragma once

#include <windows.h>
#include <set>

#include "NonCopyable.h"
#include "NonMovable.h"
#include "Snake.h"
#include "Fruit.h"

class Game : public NonCopyable, public NonMovable
{
public:
	static const int FPS = 5;
	static const int CONSOLE_HEIGHT = 30;
	static const int CONSOLE_WIDTH = 120;
	HANDLE consoleHandle;

	static const int FIELD_HEIGHT = CONSOLE_HEIGHT - 2;
	static const int FIELD_WIDTH = (CONSOLE_WIDTH - 2) / 2;
	char field[FIELD_HEIGHT][FIELD_WIDTH];

	bool loseFlag;

	Snake snake;

	static const int FRUIT_COUNT = 3;
	std::set<Fruit> fruits;

	Game();
	void placeFruit();
	void update();
	void render();
	void run();
};