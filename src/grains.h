#pragma once
#if !defined(GRAINS_H)
#define GRAINS_H

#include <cmath>

namespace grains {
	constexpr int SQUARE_NUMBERS = 64;
	unsigned long long square(int number);
	unsigned long long total();
}  // namespace grains

#endif // GRAINS_H