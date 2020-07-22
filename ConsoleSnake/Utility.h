#pragma once

#include <windows.h>

bool isKeyDown(int key);
void setConsoleCharacter(HANDLE consoleHandle, int x, int y, char c);
void setConsoleString(HANDLE consoleHandle, int x, int y, char str[], int length);