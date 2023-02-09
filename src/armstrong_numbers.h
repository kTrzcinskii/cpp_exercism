#pragma once
#if !defined(ARMSTRONG_NUMBERS_H)
#define ARMSTRONG_NUMBERS_H

#include <cmath>

namespace armstrong_numbers {
	size_t number_len(unsigned long long n);
	bool is_armstrong_number(unsigned long long n);
}  // namespace armstrong_numbers

#endif // ARMSTRONG_NUMBERS_H