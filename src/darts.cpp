#include "darts.h"

inline float darts::distance(float x, float y)
{
	return sqrt(x * x + y * y);
}

int darts::score(float x, float y)
{
	float dist = distance(x, y);
	for (int i = 0; i < NUM_OF_CIRCLES; i++)
	{
		if (dist <= static_cast<float>(circles[i].radius)) return circles[i].points;
	}
	return 0;
}