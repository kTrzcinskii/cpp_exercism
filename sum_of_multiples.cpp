#include "sum_of_multiples.h"

int sum_of_multiples::to(std::vector<int> arr, int limit)
{
	//we use set so we dont have to check if value already exists
	std::set<int> unique_values;

	//for every number we want to get every multiple and add it to set
	for (auto number : arr)
	{
		int a = number;
		while (a < limit) //we add every multiple that is less than limit
		{
			unique_values.insert(a);
			a += number;
		}
	}

	int sum = 0;
	//we sum all the unique values we have in our set
	for (auto number : unique_values) sum += number;
	return sum;
}
