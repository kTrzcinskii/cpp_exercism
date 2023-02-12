#pragma once
#if !defined(ROBOT_SIMULATOR_H)
#define ROBOT_SIMULATOR_H

#include <tuple>
#include <string>

namespace robot_simulator {
	enum class Bearing {
		NORTH,
		EAST,
		SOUTH,
		WEST
	};

	class Robot {
	public:
		Robot(std::pair<int, int> position = {0, 0}, Bearing bearing = Bearing::NORTH);
		std::pair<int, int> get_position() const;
		Bearing get_bearing() const;
		void turn_right();
		void turn_left();
		void advance();
		void execute_sequence(std::string sequence);
	private:
		std::pair<int, int> position_;
		Bearing bearing_;
	};
}  // namespace robot_simulator

#endif // ROBOT_SIMULATOR_H