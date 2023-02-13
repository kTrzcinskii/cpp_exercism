#pragma once
#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H

#include <string>
#include <unordered_set>

namespace robot_name {
	class robot {
	public:
		robot();
		std::string name() const;
		void reset();
	private:
		std::string get_random_name();
		std::string name_;
		static std::unordered_set<std::string> all_names_;
	};
}  // namespace robot_name

#endif // ROBOT_NAME_H