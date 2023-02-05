#include "difference_of_squares.h"

//we can use inline for those 2 functions because they are small and simple
//the compiler will replace the function calls with their bodies
//or at least this is what i believe is happening
inline int difference_of_squares::sum_of_squares(int number)
{
	return number * (number + 1) * (2 * number + 1) / 6; //n(n+1)(2n+1(/6
}

inline int difference_of_squares::square_of_sum(int number)
{
	return (number * (number + 1) / 2) * (number * (number + 1) / 2); //n(n+1)/2
}

int difference_of_squares::difference(int number)
{
	return difference_of_squares::square_of_sum(number) - difference_of_squares::sum_of_squares(number);
}