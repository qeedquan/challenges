/*

Create a method called "power" that takes two integers and returns the value of the first argument raised to the power of the second. Return nil if the second argument is negative.

Note: The ** operator has been disabled.

Examples:

power(2, 3) # 8
power(10, 0) # 1
power(-5, 3) # -125
power(-4, 2) # 16

*/

#include <cassert>
#include <cmath>

auto power = pow;

int main()
{
	assert(power(2, 3) == 8);
	assert(power(10, 0) == 1);
	assert(power(-5, 3) == -125);
	assert(power(-4, 2) == 16);
	return 0;
}
