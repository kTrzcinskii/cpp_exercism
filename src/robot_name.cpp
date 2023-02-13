#include "robot_name.h"
#include <random>


namespace robot_name {
	std::unordered_set<std::string> robot::all_names_{};

	robot::robot()
	{
		reset();
	}

	char get_random_letter(std::mt19937& mt)
	{
		std::uniform_int_distribution<> dis('A', 'Z'); // Generate letters between A and Z, inclusive
		return dis(mt);
	}
	
	char get_random_digit(std::mt19937& mt)
	{
		std::uniform_int_distribution<> dis('1', '9'); // Generate numbers between 1 and 9, inclusive
		return dis(mt);
	}

	std::string robot::get_random_name()
	{
		//when I used rand() here there it was significantlly slower//

		std::random_device rd;  // Seed the random number generator
		std::mt19937 mt(rd()); // Use Mersenne Twister algorithm

		return std::string({get_random_letter(mt), get_random_letter(mt), get_random_digit(mt), get_random_digit(mt), get_random_digit(mt)});
	}

	void robot::reset()
	{
		std::string name = get_random_name();
		while (all_names_.find(name) != all_names_.end())
		{
			name = get_random_name();
		}
		name_ = name;
		all_names_.insert(name);
	}

	std::string robot::name() const
	{
		return name_;
	}
}