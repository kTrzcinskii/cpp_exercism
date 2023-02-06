#include "hexadecimal.h"

bool hexadecimal::isValidSign(char c)
{
	c = tolower(c); //so we dont have to care about case
	if (isalpha(c) && c <= 'f') return true;
	if (isdigit(c)) return true;
	return false;
}

int hexadecimal::getValue(char c)
{
	if (isalpha(c)) return c - 'a' + 10; // then we have a->10, b->11 etc
	return c - '0'; // normal digits
}

int hexadecimal::convert(std::string number)
{
	int result = 0;
	for (int i = 0; i < number.length(); i++)
	{
		char sign = number[i];
		if (!hexadecimal::isValidSign(sign))
		{
			result = 0;
			break;
		}
		result += hexadecimal::getValue(sign) * pow(hexadecimal::BASE, number.length() - 1 - i);
	}
	return result;
}
