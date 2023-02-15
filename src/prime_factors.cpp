#include "prime_factors.h"
#include <cmath>

std::vector<int> prime_factors::of(unsigned int n)
{
	std::vector<int> result{};

	for (unsigned int i = 2; i <= sqrt(n); i++)
	{
		//add every number that is a divisor of n
		//we are sure that it's prime, as we start from 2
		if (n % i == 0)
		{
			n /= i;
			result.push_back(i);
			i--;
		}
	}

	//we have to add the n itself after all the division
	//but only if its greater than 1
	if (n > 1) result.push_back(n);

	return result;
}