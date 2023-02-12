#pragma once
#if !defined(ROMAN_NUMERALS_H)
#define ROMAN_NUMERALS_H

#include <string>
#include <map>

namespace roman_numerals {
	std::string convert(int n);
	const std::map<int, std::string> arabic_to_roman{
		{1, "I"},
		{4, "IV"},
		{5, "V"},
		{9, "IX"},
		{10, "X"},
		{40, "XL"},
		{50, "L"},
		{90, "XC"},
		{100, "C"},
		{400, "CD"},
		{500, "D"},
		{900, "CM"},
		{1000, "M"},
	};
}  // namespace roman_numerals

#endif // ROMAN_NUMERALS_H