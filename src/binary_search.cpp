#include "binary_search.h"
#include <stdexcept>

size_t binary_search::find(std::vector<int> data, int n)
{
	if (data.size() == 0) throw std::domain_error("Value not found");
	int index = data.size() / 2;
	int middle = data[index];
	if (data.size() == 1 && middle != n) throw std::domain_error("Value not found");
	if (middle == n) return index;
	if (middle < n)
	{
		std::vector<int> newData(data.begin() + index + 1, data.end());
		return static_cast<size_t>(index + 1) + find(newData, n); //beacuse in this case we must add the middle index + 1 as we skip that many elements from original vector
	}
	else
	{
		std::vector<int> newData(data.begin(), data.begin() + index);
		return find(newData, n);
	}
}