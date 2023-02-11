#pragma once
#if !defined(LUHN_H)
#define LUHN_H

#include <string>

namespace luhn {
	bool valid(std::string number);
	bool only_digits(std::string number);
	void double_second_digit_r(std::string& number);
	void erase_spaces(std::string& number);
	constexpr size_t MIN_LENGTH = 2;
}  // namespace luhn

#endif // LUHN_H