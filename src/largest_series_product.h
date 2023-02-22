#pragma once
#if !defined(LARGEST_SERIES_PRODUCT_H)
#define LARGEST_SERIES_PRODUCT_H

#include <string>

namespace largest_series_product {
	unsigned long long larges_product(std::string input, int n);
	bool is_input_valid(std::string input);
} // largest_series_product

#endif // LARGEST_SERIES_PRODUCT_H