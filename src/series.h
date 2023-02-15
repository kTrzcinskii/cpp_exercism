#pragma once
#if !defined(SERIES_H)
#define SERIES_H

#include <vector>
#include <string>

namespace series {
	std::vector<std::string> slice(const std::string& number, int n);
}  // namespace series

#endif // SERIES_H