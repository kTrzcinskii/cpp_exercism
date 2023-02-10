#pragma once
#if !defined(RAINDROPS_H)
#define RAINDROPS_H

#include <string>

namespace raindrops {
	std::string convert(int n);
	//struct to hold data in easily accessbile way
	struct Factor{
		int number;
		std::string word;
	};
	const Factor FACTOR_3 = { 3, "Pling" };
	const Factor FACTOR_5 = { 5, "Plang" };
	const Factor FACTOR_7 = { 7, "Plong" };
	const Factor factors[3] = { FACTOR_3, FACTOR_5, FACTOR_7 };
}  // namespace raindrops

#endif // RAINDROPS_H