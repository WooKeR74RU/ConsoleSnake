#include "Fruit.h"

bool Fruit::operator<(const Fruit & other) const
{
	if (x != other.x)
		return x < other.x;
	return y < other.y;
}