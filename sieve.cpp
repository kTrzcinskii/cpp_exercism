#include "sieve.h"

const std::vector<int> sieve::primes(int n)
{
	std::vector<int> primes;

	std::vector<bool> isPrime(n + 1, true);
	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i < n + 1; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * 2; j < n + 1; j += i) isPrime[j] = false;
		}
	}

	for (int i = 0; i < n + 1; i++) if (isPrime[i]) primes.push_back(i);

	return primes;
}