#include "two_fer.h"

std::string two_fer::two_fer()
{
	return "One for you, one for me.";
}

std::string two_fer::two_fer(std::string name)
{
	return "One for " + name + ", one for me.";
}