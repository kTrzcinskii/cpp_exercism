#include <stdexcept>
#include <algorithm>
#include "say.h"

std::string say::zero_to_nineteen(unsigned int number)
{
	switch (number)
	{
	case 0:
		return "zero";
	case 1:
		return "one";
	case 2:
		return "two";
	case 3:
		return "three";
	case 4:
		return "four";
	case 5:
		return "five";
	case 6:
		return "six";
	case 7:
		return "seven";
	case 8:
		return "eight";
	case 9:
		return "nine";
	case 10:
		return "ten";
	case 11:
		return "eleven";
	case 12:
		return "twelve";
	case 13:
		return "thirteen";
	case 14:
		return "fourteen";
	case 15:
		return "fifteen";
	case 16:
		return "sixteen";
	case 17:
		return "seventeen";
	case 18:
		return "eighteen";
	case 19:
		return "nineteen";
	default:
		return "";
	}
}

std::string say::dozens(unsigned int number)
{
	switch (number / 10 * 10)
	{
	case 20:
		return "twenty";
	case 30:
		return "thirty";
	case 40:
		return "forty";
	case 50:
		return "fifty";
	case 60:
		return "sixty";
	case 70:
		return "seventy";
	case 80:
		return "eighty";
	case 90:
		return "ninety";
	default:
		return "";
	}
}

std::string say::hundreds(unsigned int number)
{
	return zero_to_nineteen(number / 100) + " hundred";
}

std::string say::zero_to_ninety_nine(unsigned int number)
{
	if (number < 20) return zero_to_nineteen(number);
	return dozens(number) + (number % 10 != 0 ? ("-" + zero_to_nineteen(number % 10)) : "");
}

std::string say::up_to_3_digits(unsigned int number)
{
	std::string result{};
	if (number >= 100) result += hundreds(number);
	number %= 100;
	if (number == 0 && result.size()) return result;
	result += ((result.size() ? " " : "") + zero_to_ninety_nine(number));
	return result;
}

std::vector<unsigned int> say::get_groups_of_3(long long number)
{
	std::vector<unsigned int>result{};

	while (number > 0)
	{
		unsigned int a = number % 1000;
		result.push_back(a);
		number /= 1000;
	}

	//now we want to reverse the order, so that the digits connected with biggest values are first
	std::reverse(result.begin(), result.end());
	return result;
}

std::string say::get_value_string(unsigned int n)
{
	switch (n)
	{
	case static_cast<unsigned int>(VALUES::BILLION):
		return "billion";
	case static_cast<unsigned int>(VALUES::MILLION):
		return "million";
	case static_cast<unsigned int>(VALUES::THOUSAND):
		return "thousand";
	default:
		return "";
	}
}

std::string say::in_english(long long number)
{
	//check if number is correct
	if (number < 0 || number > MAX_NUMBER) throw std::domain_error("Number out of range");
	//take care of 0 so we can skip any value that is equal to 0 later
	if (number == 0) return up_to_3_digits(0);
	//split number into groups of 3
	std::vector<unsigned int> groups_of_3 = get_groups_of_3(number);
	std::string result{};
	for (size_t i = 0; i < groups_of_3.size(); i++)
	{
		//change every group of 3 to text + add string value such as "billion" when needed
		if (up_to_3_digits(groups_of_3[i]) != "zero")
		{
			if (result.size()) result += " ";
			result += up_to_3_digits(groups_of_3[i]);
			if (groups_of_3.size() - i >= 2 && groups_of_3.size() - i <= 4) result += (" " + get_value_string(groups_of_3.size() - i));
		}
	}
	return result;
}