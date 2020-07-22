#pragma once

class Fruit
{
public:
	static const char fruitChar = 'F';
	int x;
	int y;
	bool operator<(const Fruit& other) const;
};