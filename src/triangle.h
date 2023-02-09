#pragma once
#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#include <stdexcept>

namespace triangle {
	enum class flavor
	{
		equilateral,
		isosceles,
		scalene,
	};

	void checkTriangle(double a, double b, double c);
	flavor kind(double a, double b, double c);
}  // namespace triangle

#endif // TRIANGLE_H