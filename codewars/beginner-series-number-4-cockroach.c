/*

The cockroach is one of the fastest insects. Write a function which takes its speed in km per hour and returns it in cm per second, rounded down to the integer (= floored).

For example:

1.08 --> 30
Note! The input is a Real number (actual type is language dependent) and is >= 0. The result should be an Integer.

*/

#include <assert.h>

int
cockroachspeed(double speed)
{
	return 27.7778 * speed;
}

int
main()
{
	assert(cockroachspeed(1.08) == 30);
	assert(cockroachspeed(1.09) == 30);
	assert(cockroachspeed(0) == 0);
	return 0;
}
