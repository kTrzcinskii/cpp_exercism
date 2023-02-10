#include "grade_school.h"

namespace grade_school {
	std::map<int, std::vector<std::string>> school::roster() const
	{
		return roster_data;
	}

	std::vector<std::string> school::grade(int gr) const
	{
		auto pointer = roster_data.find(gr);
		//return empty vector if there is no such grade in a roster
		if (pointer == roster_data.end()) return std::vector<std::string> {};
		//return grade
		return pointer->second;
	}

	void school::add(std::string name, int grade)
	{
		auto pointer = roster_data.find(grade);
		if (pointer == roster_data.end())
		{
			//the grade wasn't in the roster so we just add this return from function
			//we dont have to care about proper position because element in map are automatically sorted by key
			roster_data.insert({ grade, std::vector<std::string> {name} });
			return;
		}
		//use reference to work on original of vector
		auto &my_vector = pointer->second;
		my_vector.push_back(name);
		//after adding name to grade we have to sort it again
		sortVector(my_vector);
		//* other option is just calculating right index befor adding, but it seems harder *//
	}

	void school::sortVector(std::vector<std::string>& my_vector)
	{
		//bubble sort :PP
		for (size_t i = 0; i < my_vector.size(); i++)
			for (size_t j = i + 1; j < my_vector.size(); j++)
			{
				//if it's true it means v[i] is lexicographically bigger than v[j]
				//so we swap them with iter_swap, which uses iterators
				if (my_vector[i].compare(my_vector[j]) > 0) std::iter_swap(my_vector.begin() + i, my_vector.begin() + j);
			}
	}
}