#pragma once
#if !defined(ISBN_VERIFIER_H)
#define ISBN_VERIFIER_H

#include <string>
#include <cctype>

namespace isbn_verifier {
	inline bool is_valid_character(char c);
	bool is_valid(std::string number);
	constexpr int LEN_WITH_DASHES = 13;
	constexpr int LEN_WITHOUT_DASHES = 10;
} // namespace isbn_verifier

#endif // ISBN_VERIFIER_H