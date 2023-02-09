#pragma once
#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

namespace space_age {
	class space_age
	{
	public:
		space_age(unsigned long long sec);
		unsigned long long seconds() const;
		double on_mercury() const;
		double on_venus() const;
		double on_earth() const;
		double on_mars() const;
		double on_jupiter() const;
		double on_saturn() const;
		double on_uranus() const;
		double on_neptune() const;
	private:
		unsigned long long time_in_seconds;
		const unsigned long long EARTH_YEAR_IN_SECONDS = 31557600;
		const double MERCURY_EARTH_RATIO = 0.2408467;
		const double VENUS_EARTH_RATIO = 0.61519726;
		const double MARS_EARTH_RATIO = 1.8808158;
		const double JUPITER_EARTH_RATIO = 11.862615;
		const double SATURN_EARTH_RATIO = 29.447498;
		const double URANUS_EARTH_RATIO = 84.016846;
		const double NEPTUN_EARTH_RATIO = 164.79132;
	};
}  // namespace space_age

#endif // SPACE_AGE_H