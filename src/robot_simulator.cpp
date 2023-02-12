#include "robot_simulator.h"

namespace robot_simulator {
	Robot::Robot(std::pair<int, int> position, Bearing bearing)
	{
		position_ = position;
		bearing_ = bearing;
	}

	std::pair<int, int> Robot::get_position() const
	{
		return position_;
	}

	Bearing Robot::get_bearing() const
	{
		return bearing_;
	}

	void Robot::turn_right()
	{
		bearing_ = static_cast<Bearing>((static_cast<int>(bearing_) + 1) % 4);
	}

	void Robot::turn_left()
	{
		int temp = static_cast<int>(bearing_) - 1;
		if (temp < 0) temp += 4;
		bearing_ = static_cast<Bearing>(temp);
	}

	void Robot::advance()
	{
		switch (bearing_)
		{
		case Bearing::NORTH:
			position_.second++;
			break;
		case Bearing::EAST:
			position_.first++;
			break;
		case Bearing::SOUTH:
			position_.second--;
			break;
		case Bearing::WEST:
			position_.first--;
			break;
		default:
			break;
		}
	}

	void Robot::execute_sequence(std::string sequence)
	{
		for (auto& letter : sequence)
		{
			switch (letter)
			{
			case 'R':
				turn_right();
				break;
			case 'L':
				turn_left();
				break;
			case 'A':
				advance();
				break;
			default:
				break;
			}
		}
	}
}