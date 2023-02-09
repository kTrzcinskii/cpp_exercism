#include "triangle.h"

void triangle::checkTriangle(double a, double b, double c)
{
	if (a <= 0 || b <= 0 || c <= 0) throw std::domain_error("Triangle's sides cannot be negative");
	if (a + b <= c || a + c <= b || b + c <= a) throw std::domain_error("Triangle does not satisfy triangle ineqaulity");
}

triangle::flavor triangle::kind(double a, double b, double c)
{
	checkTriangle(a, b, c);
	if (a == b && b == c) return flavor::equilateral;
	if (a == b || b == c || a == c) return flavor::isosceles;
	return flavor::scalene;
}