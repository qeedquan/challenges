/*

You need to cook pancakes, but you are very hungry. As known, one needs to fry a pancake one minute on each side.
What is the minimum time you need to cook n pancakes, if you can put on the frying pan only m pancakes at a time?
n and m are positive integers between 1 and 1000.

*/

#include <assert.h>
#include <math.h>

int
cookpancakes(int n, int m)
{
	if (n <= m)
		return 2;
	return ceil((2.0 * n) / m);
}

int
main()
{
	assert(cookpancakes(1, 1) == 2);
	assert(cookpancakes(2, 2) == 2);
	assert(cookpancakes(3, 2) == 3);
	assert(cookpancakes(4, 2) == 4);
	assert(cookpancakes(4, 3) == 3);
	return 0;
}
