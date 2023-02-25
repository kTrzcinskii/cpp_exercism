#include <cctype>
#include "acronym.h"

std::string acronym::format_string(std::string input)
{
	size_t pos = input.find("-");
	//switch "-" to whitespace
	while (pos != std::string::npos)
	{
		input.replace(pos, 1, " ");
		pos = input.find("-", pos + 1);
	}
	//remove additional chars
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!isalnum(input[i]) && !isspace(input[i]))
		{
			input.erase(i, 1);
			i--;
		}
	}
	//remove more than one whitespace in a row
	pos = input.find(" ");
	size_t pos2 = input.find(" ", pos + 1);
	while (pos2 == pos + 1)
	{
		input.erase(pos, 1);
		pos = input.find(" ");
		pos2 = input.find(" ", pos + 1);
	}
	//trim left
	while (input.size() > 0 && isspace(input.front()))
	{
		input.erase(0, 1);
	}
	//trim right
	while (input.size() > 0 && isspace(input.back()))
	{
		input.pop_back();
	}
	return input;
}

std::string acronym::acronym(const std::string& input)
{
	std::string formatted = format_string(input);
	std::string output{};
	//add first word
	output += toupper(formatted[0]);
	size_t pos = formatted.find(" ");
	while (pos != std::string::npos)
	{
		//add nex word
		output += toupper(formatted[pos + 1]);
		pos = formatted.find(" ", pos + 1);
	}
	return output;
}
