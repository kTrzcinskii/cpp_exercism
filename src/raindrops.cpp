#include "raindrops.h"

std::string raindrops::convert(int n)
{
	std::string result{};
	for (auto &factor : factors) //using reference to avoid making copy of factors
	{
		if (n % factor.number == 0) result += factor.word;
	}
	if (result.empty()) result = std::to_string(n); //if result is empty then it means we have to return number
	return result;
}