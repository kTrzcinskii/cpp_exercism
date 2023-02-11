#include "luhn.h"
#include <cctype>

void luhn::erase_spaces(std::string& number)
{
	size_t pos = number.find(' ');
	while (pos != std::string::npos)
	{
		number.erase(number.begin() + pos); //erase character at given pointer (iterator + index)
		pos = number.find(' ');
	}
}

void luhn::double_second_digit_r(std::string& number)
{
	//we start from the second element from the right and go every second element to the left
	for (int i = number.length() - 2; i >= 0; i -= 2)
	{
		int num = (number[i] - '0') * 2;
		if (num >= 10) num -= 9;
		number[i] = num + '0';
	}
}

bool luhn::only_digits(std::string number)
{
	for (auto digit : number)
	{
		if (!isdigit(digit)) return false;
	}
	return true;
}

bool luhn::valid(std::string number)
{
	erase_spaces(number);
	if (number.length() < MIN_LENGTH) return false;
	if (!only_digits(number)) return false;
	double_second_digit_r(number);
	int sum = 0;
	for (auto digit : number)
	{
		sum += digit - '0';
	}
	return (sum % 10 == 0);
}