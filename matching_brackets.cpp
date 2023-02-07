#include "matching_brackets.h"

bool matching_brackets::isBracket(char c)
{
	//check if c is in first array
	const char* pointer = std::find(std::begin(opening_brackets), std::end(opening_brackets), c);
	if (pointer != std::end(opening_brackets)) return true;
	//check if c is in the second array
	pointer = std::find(std::begin(closing_brackets), std::end(closing_brackets), c);
	if (pointer != std::end(closing_brackets)) return true;
	return false;
}

matching_brackets::bracketType matching_brackets::checkBracketType(char c)
{
	const char* pointer = std::find(std::begin(opening_brackets), std::end(opening_brackets), c);
	if (pointer != std::end(opening_brackets)) return bracketType::opening;
	return bracketType::closing;
}

bool matching_brackets::matching(char c1, char c2)
{
	if (c1 == '(' && c2 == ')') return true;
	if (c1 == '[' && c2 == ']') return true;
	if (c1 == '{' && c2 == '}') return true;
	return false;
}

bool matching_brackets::check(std::string s)
{
	std::stack<char> brackets;

	for (auto c : s)
	{
		//dont care if c isnt bracket
		if (!isBracket(c)) continue;
		bracketType currentBracket = checkBracketType(c);

		//if c is opening bracket we put it on top of our stack
		if (currentBracket == bracketType::opening)
		{
			brackets.push(c);
		}

		//if c is closing bracket we check if it matches lastly used opening bracket
		//if it does then everything's allrgith
		//if it doesnt or stack is empty then brackets dont match
		else
		{
			if (brackets.empty()) return false;
			if (matching(brackets.top(), c)) brackets.pop();
			else return false;
		}
	}

	//if stack is not empty then there are some brackets that dont match
	return brackets.empty();
}
