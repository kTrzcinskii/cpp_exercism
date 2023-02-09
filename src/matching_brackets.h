#pragma once
#if !defined(MATCHING_BRACKETS_H)
#define MATCHING_BRACKETS_H

#include <string>
#include <stack>
#include <algorithm>

namespace matching_brackets {
	enum class bracketType
	{
		opening,
		closing
	};

	constexpr char opening_brackets[] = {'(', '[', '{'};
	constexpr char closing_brackets[] = {')', ']', '}'};

	bool check(std::string s);
	bracketType checkBracketType(char c);
	bool isBracket(char c);
	bool matching(char c1, char c2);
}  // namespace matching_brackets

#endif // MATCHING_BRACKETS_H