#pragma once
#if !defined(HEXADECIMAL_H)
#define HEXADECIMAL_H

#include <string>
#include <cctype>
#include <cmath>

namespace hexadecimal {
	constexpr int BASE = 16;

	bool isValidSign(char c);
	int getValue(char c);
	int convert(std::string number);
}  // namespace hexadecimal

#endif // HEXADECIMAL_H