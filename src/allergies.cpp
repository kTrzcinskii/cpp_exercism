#include "allergies.h"

namespace allergies {
	allergy_test::allergy_test(int n)
	{
		for (auto const& x : allergies_codes_) //reference to not copy the map
		{
			//if they have same bit we add the allergy to the list			
			if ((x.first & n) == x.first) allergies_.insert(x.second);
		}
	}

	bool allergy_test::is_allergic_to(std::string allergy) const
	{
		//if iterator returned from find is not equal to end() it means the value is in the set
		return allergies_.find(allergy) != allergies_.end();
	}

	std::unordered_set<std::string> allergy_test::get_allergies() const
	{
		return allergies_;
	}
}