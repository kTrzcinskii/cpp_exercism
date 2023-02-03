#include "reverse_string.h"

std::string reverse_string::reverse_string(std::string s)
{
	for (int i = 0; i < s.length() / 2; i++)
	{
		std::swap(s[i], s[s.length()- 1 - i]);
	}
	return s;
}
