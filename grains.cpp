#include "grains.h"

unsigned long long grains::square(int number)
{
	return pow(2, number - 1);
}

unsigned long long grains::total()
{
	unsigned long long total = 0;
	for (int i = 1; i <= grains::SQUARE_NUMBERS; i++) total += grains::square(i);
	return total;
}
