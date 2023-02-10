#pragma once
#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <map>
#include <vector>
#include <string>

namespace grade_school {
	class school {
	public:
		std::map<int, std::vector<std::string>> roster() const;
		std::vector<std::string> grade(int gr) const;
		void add(std::string name, int grade);
	private:
		std::map<int, std::vector<std::string>> roster_data{};
		void sortVector(std::vector<std::string>& my_vector);
	};
}  // namespace grade_school

#endif // GRADE_SCHOOL_H