#pragma once
#if !defined(DARTS_H)
#define DARTS_H

#include <cmath>

namespace darts {
	inline float distance(float x, float y);
	int score(float x, float y);
	struct Circle
	{
		int radius;
		int points;
	};
	constexpr int NUM_OF_CIRCLES = 3;
	const Circle inner = { 1, 10 };
	const Circle middle = { 5, 5 };
	const Circle outer = { 10, 1 };
	const Circle circles[NUM_OF_CIRCLES] = { inner, middle, outer };
} // namespace darts

#endif //DARTS_H