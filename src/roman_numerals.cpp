#include "roman_numerals.h"

std::string roman_numerals::convert(int n)
{
	std::string result{};
	//rbegin and rend are used to iterate over a map from right to left
	auto iter = arabic_to_roman.rbegin();
	while (iter != arabic_to_roman.rend())
	{
		if (n == 0) break;
		if (n >= iter->first)
		{
			n -= iter->first;
			result += iter->second;
		}
		else {
			iter++;
		}
	}
	return result;
}