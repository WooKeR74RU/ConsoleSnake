#include "Game.h"

#include <ctime>

#include "Utility.h"
#include "Direction.h"

Game::Game()
{
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	loseFlag = false;
	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
			field[i][j] = ' ';
	}
	for (int i = 0; i < FRUIT_COUNT; i++)
		placeFruit();

	srand((unsigned int)time(nullptr));

	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);

	char frameTop[CONSOLE_WIDTH];
	char frameBot[CONSOLE_WIDTH];
	for (int i = 1; i < CONSOLE_WIDTH - 1; i++)
		frameTop[i] = frameBot[i] = (char)205;
	frameTop[0] = (char)201;
	frameTop[CONSOLE_WIDTH - 1] = (char)187;
	frameBot[0] = (char)200;
	frameBot[CONSOLE_WIDTH - 1] = (char)188;
	setConsoleString(consoleHandle, 0, 0, frameTop, CONSOLE_WIDTH);
	setConsoleString(consoleHandle, 0, CONSOLE_HEIGHT - 1, frameBot, CONSOLE_WIDTH);
	for (int i = 1; i < CONSOLE_HEIGHT - 1; i++)
	{
		setConsoleCharacter(consoleHandle, 0, i, (char)186);
		setConsoleCharacter(consoleHandle, CONSOLE_WIDTH - 1, i, (char)186);
	}
}

void Game::placeFruit()
{
	Fruit fruit;
	while (true)
	{
		int x = rand() % FIELD_WIDTH;
		int y = rand() % FIELD_HEIGHT;
		if (field[y][x] == ' ')
		{
			fruit.x = x;
			fruit.y = y;
			field[y][x] = Fruit::fruitChar;
			break;
		}
	}
	fruits.insert(fruit);
}

void Game::update()
{
	move(snake.x, snake.y, snake.dir, FIELD_HEIGHT, FIELD_WIDTH);
	snake.lastFrameDir = snake.dir;

	snake.tail.push_back(snake.dir);
	int tailX = snake.x;
	int tailY = snake.y;
	for (int i = snake.tail.size() - 1; 0 <= i; i--)
	{
		moveBack(tailX, tailY, snake.tail[i], FIELD_HEIGHT, FIELD_WIDTH);
		if (i == 0)
		{
			field[tailY][tailX] = ' ';
		}
		else
		{
			field[tailY][tailX] = snake.getTailChar(snake.tail[i - 1], snake.tail[i]);
			if (tailY == snake.y && tailX == snake.x)
				loseFlag = true;
		}
	}
	if (snake.tailLength < (int)snake.tail.size())
		snake.tail.pop_front();

	field[snake.y][snake.x] = Snake::headChar;

	for (auto it = fruits.begin(); it != fruits.end(); it++)
	{
		if (snake.y == it->y && snake.x == it->x)
		{
			snake.tailLength++;
			placeFruit();
			fruits.erase(it);
			break;
		}
	}
}

void Game::render()
{
	char str[CONSOLE_WIDTH - 2];
	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
			str[2 * j] = str[2 * j + 1] = field[i][j];
		setConsoleString(consoleHandle, 1, i + 1, str, CONSOLE_WIDTH - 2);
	}
}

void Game::run()
{
	int lastTime = clock();
	int updateTime = 0;
	while (true)
	{
		snake.inputHandling();

		int curTime = clock();
		int deltaTime = curTime - lastTime;
		lastTime = curTime;

		updateTime += deltaTime;
		if (updateTime >= CLOCKS_PER_SEC / FPS)
		{
			if (loseFlag)
				return;
			update();
			render();
			updateTime = 0;
		}
	}
}