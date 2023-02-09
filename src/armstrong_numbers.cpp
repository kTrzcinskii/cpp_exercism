#include "armstrong_numbers.h"

#include <iostream>

size_t armstrong_numbers::number_len(unsigned long long n)
{
	size_t len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return len;
}

bool armstrong_numbers::is_armstrong_number(unsigned long long n)
{
	unsigned long long sum_of_digits = 0;
	unsigned long long number = n;
	size_t len = number_len(n);
	while (n > 0)
	{
		int k = n % 10;
		sum_of_digits += pow(k, len);
		n /= 10;
	}
	return sum_of_digits == number;
}

int main()
{
	std::cout << armstrong_numbers::is_armstrong_number(110);

	return 0;
}