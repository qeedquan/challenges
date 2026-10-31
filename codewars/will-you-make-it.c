/*

You were camping with your friends far away from home, but when it's time to go back, you realize that your fuel is running out and the nearest pump is 50 miles away! You know that on average, your car runs on about 25 miles per gallon. There are 2 gallons left.

Considering these factors, write a function that tells you if it is possible to get to the pump or not.

Function should return true if it is possible and false if not.

*/

#include <assert.h>

bool
zerofuel(double distance, double mpg, double fuel)
{
	return distance <= mpg * fuel;
}

int
main()
{
	assert(zerofuel(50, 25, 2) == true);
	assert(zerofuel(100, 50, 1) == false);
	assert(zerofuel(60, 30, 3) == true);
	assert(zerofuel(70, 25, 1) == false);
	assert(zerofuel(100, 25, 3) == false);

	return 0;
}
