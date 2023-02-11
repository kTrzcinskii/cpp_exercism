#include "collatz_conjecture.h"

int collatz_conjecture::steps(int n)
{
	if (n <= 0) throw std::domain_error("Number must be greater than 0");
	int counter = 0;
	while (n != 1)
	{
		if (n % 2 == 0) n /= 2;
		else n = 3 * n + 1;
		counter++;
	}
	return counter;
}