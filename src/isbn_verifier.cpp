#include "isbn_verifier.h"

inline bool isbn_verifier::is_valid_character(char c)
{
	return isdigit(c) || c == 'X';
}

bool isbn_verifier::is_valid(std::string number)
{
	//check if the number has possibly right length
	if (number.length() != LEN_WITHOUT_DASHES && number.length() != LEN_WITH_DASHES) return false;

	int sum = 0;
	int i = 10;

	for (size_t k = 0; k < number.length(); k++)
	{
		char digit = number[k];
		if (digit == '-') continue; //dont care about dash
		if (!is_valid_character(digit)) return false;
		//add value to the sum, with X treated as 10
		if (digit == 'X')
		{
			if (k != number.length() - 1) return false; // X can only be the last digit of isbn
			sum += 10 * i;
		}
		else
		{
			sum += std::stoi(&digit) * i;
		}
		i--;
	}

	//if i != 0 then we didnt use 10 digits, so it cannot be valid isbn
	if (i != 0) return false;

	return (sum % 11 == 0);
}