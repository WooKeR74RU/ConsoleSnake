#include "Utility.h"

bool isKeyDown(int key)
{
	return (GetKeyState(key) & (1 << 15)) != 0;
}
void setConsoleCharacter(HANDLE consoleHandle, int x, int y, char c)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	char tmp[1] = { c };
	DWORD dword;
	WriteConsoleOutputCharacter(consoleHandle, tmp, 1, coord, &dword);
}
void setConsoleString(HANDLE consoleHandle, int x, int y, char str[], int length)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	DWORD dword;
	WriteConsoleOutputCharacter(consoleHandle, str, length, coord, &dword);
}