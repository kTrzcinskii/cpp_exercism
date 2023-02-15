#include "series.h"
#include <stdexcept>

std::vector<std::string> series::slice(const std::string& number, int n)
{
	if (n <= 0) throw std::domain_error("Slice length must be greater than 0");
	if (static_cast<size_t>(n) > number.length()) throw std::domain_error("Slice length cannot be greater than number length");

	std::vector<std::string> result{};
	size_t pos{};
	
	while (pos + n <= number.length())
	{
		result.push_back(number.substr(pos, n));
		pos++;
	}

	return result;
}