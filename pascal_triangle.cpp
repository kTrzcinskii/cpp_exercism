#include "pascal_triangle.h"

std::vector<std::vector<int>> pascals_triangle::generate_rows(int n)
{
	//the algorithm is my own idea
	//probably there is a less complex and faster way to do it

	std::vector<std::vector<int>> rows;
	
	for (size_t i = 0; i < n; i++)
	{
		std::vector<int> current_row;
		current_row.push_back(1); //every row has 1 on first position
		if (i > 1)
		{
			for (size_t k = 0; k < rows[i - 1].size() - 1 /*because we dont care about last element*/; k++)
			{
				current_row.push_back(rows[i - 1][k] + rows[i - 1][k + 1]); //add the sum of two next elements from previous row
			}
		}
		if (i > 0) current_row.push_back(1); //every row except first has 1 at the end
		rows.push_back(current_row);
	}

	return rows;
}