#pragma once
#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>

namespace date_independent {
	class clock {
	public:
		static clock at(int hour, int minute);
		clock plus(int add);
		operator std::string() const;
		bool operator==(const clock& othter) const;
		bool operator!=(const clock& othter) const;
	private:
		clock(int h, int min); //private constructor
		int hour_;
		int minute_;
		static constexpr int MIN_IN_DAY = 1440;
	};
}  // namespace date_independent

#endif // CLOCK_H