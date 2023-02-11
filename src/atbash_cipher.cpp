#include "atbash_cipher.h"
#include <cctype>

namespace atbash_cipher {
	char encode(char c)
	{
		//if it's a digit we don't change it
		if (isdigit(c)) return c;
		std::size_t index = originalAlphabet.find(tolower(c));
		//it must be in the alphabet so we dont even check if its != std::string::npos
		return encodedAlphabet[index];
	}

	char decode(char c)
	{
		//rules same as above
		if (isdigit(c)) return c;
		std::size_t index = encodedAlphabet.find(tolower(c));
		return originalAlphabet[index];
	}

	std::string encode(std::string s)
	{
		std::string result{};
		size_t letter_without_spaces = 0;
		for (auto letter : s)
		{
			if (letter_without_spaces % 5 == 0 && letter_without_spaces > 0 && result[result.length() - 1] != ' ') result += ' ';//every 5 characters(excluding spaces) we must add space (but only one)
			if (!isalnum(letter)) continue; //if it isn't letter or digit we skip it
			result += encode(letter);
			letter_without_spaces++;
		}
		if (!result.empty() && result[result.length() - 1] == ' ') result.pop_back(); //if we added the space at the end of the result we need to remove it
		return result;
	}

	std::string decode(std::string s)
	{
		std::string result{};
		for (auto letter : s)
		{
			if (letter == ' ') continue; //we dont copy the spaces to the result
			else result += decode(letter);
		}
		return result;
	}
}