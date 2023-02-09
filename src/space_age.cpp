#include "space_age.h"

namespace space_age {
	space_age::space_age(unsigned long long sec)
	{
		time_in_seconds = sec;
	}

	unsigned long long space_age::seconds() const
	{
		return time_in_seconds;
	}

	double space_age::on_mercury() const
	{
		return on_earth() / MERCURY_EARTH_RATIO;
	}

	double space_age::on_venus() const
	{
		return on_earth() / VENUS_EARTH_RATIO;
	}

	double space_age::on_earth() const
	{
		return static_cast<double>(time_in_seconds) / EARTH_YEAR_IN_SECONDS;
	}

	double space_age::on_mars() const
	{
		return on_earth() / MARS_EARTH_RATIO;
	}

	double space_age::on_jupiter() const
	{
		return on_earth() / JUPITER_EARTH_RATIO;
	}

	double space_age::on_saturn() const
	{
		return on_earth() / SATURN_EARTH_RATIO;
	}

	double space_age::on_uranus() const
	{
		return on_earth() / URANUS_EARTH_RATIO;
	}

	double space_age::on_neptune() const
	{
		return on_earth() / NEPTUN_EARTH_RATIO;
	}
}