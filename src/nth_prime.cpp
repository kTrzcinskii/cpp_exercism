#include "nth_prime.h"
#include <stdexcept>
#include <cmath>

bool nth_prime::is_prime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

int nth_prime::nth(int n)
{
	if (n <= 0) throw std::domain_error("Number must be greater than 0");

	int primes = 0;
	int nth_prime = 0;
	int i = 2;
	while (primes != n)
	{
		if (is_prime(i))
		{
			primes++;
			nth_prime = i;
		}
		i++;
	}
	return nth_prime;
}