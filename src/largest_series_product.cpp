#include "largest_series_product.h"
#include <stdexcept>
#include <cctype>

bool largest_series_product::is_input_valid(std::string input)
{
	if (input == "") return false;
	for (const auto& c : input)
	{
		if (!isdigit(c)) return false;
	}
	return true;
}

unsigned long long largest_series_product::larges_product(std::string input, int n)
{
	if (n < 0) throw std::domain_error("Lenght cannot be negative!");
	if (n == 0) return 1;
	if (!is_input_valid(input)) throw std::domain_error("Invalid input");
	if (input.length() > n) throw std::domain_error("Input length cannot be greater than series length");

	unsigned long long largest = 0;
	for (int i = 0; i <= input.length() - n; i++)
	{
		unsigned long long prod = 1;
		for (int j = 0; j < n; j++)
		{
			prod *= std::stoull(input.substr(static_cast<size_t>(i + j), 1));
		}
		if (prod > largest) largest = prod;
	}
	return largest;
}
