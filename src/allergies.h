#pragma once
#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <string>
#include <unordered_set>
#include <map>

namespace allergies {
	class allergy_test {
	public:
		allergy_test(int n);
		bool is_allergic_to(std::string) const;
		std::unordered_set<std::string> get_allergies() const;
	private:
		std::unordered_set<std::string> allergies_;
		const std::map<int, std::string> allergies_codes_ = {
			{0b1, "eggs"},
			{0b10, "peanuts"},
			{0b100, "shellfish"},
			{0b1000, "strawberries"},
			{0b10000, "tomatoes"},
			{0b100000, "chocolate"},
			{0b1000000, "pollen"},
			{0b10000000, "cats"},
		};
	};
}  // namespace allergies

#endif // ALLERGIES_H