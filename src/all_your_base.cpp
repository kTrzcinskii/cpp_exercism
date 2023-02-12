#include "all_your_base.h"
#include <cmath>
#include <stdexcept>
#include <algorithm>

std::vector<unsigned int> all_your_base::convert(unsigned int b_from, std::vector<unsigned int> in_digits, unsigned int b_to)
{
	//check if base are correct
	if (b_from <= 1 || b_to <= 1) throw std::invalid_argument("Base must be greater than 1");
	std::vector<unsigned int> out_digits{};
	unsigned long long actual_number_in_b10 = 0;
	//convert to ull in base 10
	for (size_t i = 0; i < in_digits.size(); i++)
	{
		if (in_digits[i] >= b_from) throw std::invalid_argument("Digit cannot be greater than the base"); //check if digit is correct regarding given base
		actual_number_in_b10 += pow(b_from, in_digits.size() - 1 - i) * in_digits[i];
	}
	//if our number is 0 we return empty vector
	if (actual_number_in_b10 == 0) return out_digits;
	//conver to vector with digits from b_to
	while (actual_number_in_b10)
	{
		out_digits.push_back(actual_number_in_b10 % b_to);
		actual_number_in_b10 /= b_to;
	}
	//we must reverse vector as we were appending digits to the back
	std::reverse(out_digits.begin(), out_digits.end());
	return out_digits;
}