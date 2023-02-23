#include "clock.h"

namespace date_independent {
	clock::clock(int h, int min)
	{
		int total = h * 60 + min;
		total %= MIN_IN_DAY;
		if (total < 0)
		{
			total += MIN_IN_DAY;
		}
		hour_ = total / 60;
		minute_ = total % 60;
	}

	clock clock::at(int hour, int minute)
	{
		//call to private constructor
		return clock(hour, minute);
	}

	clock clock::plus(int add)
	{
		return clock(hour_, minute_ + add);
	}

	clock::operator std::string() const
	{
		return (hour_ < 10 ? "0" : "") + std::to_string(hour_) + ":" + (minute_ < 10 ? "0" : "") + std::to_string(minute_);
	}

	bool clock::operator==(const clock& other) const
	{
		return hour_ == other.hour_ && minute_ == other.minute_;
	}

	bool clock::operator!=(const clock& other) const
	{
		return hour_ != other.hour_ || minute_ != other.minute_;
	}
}