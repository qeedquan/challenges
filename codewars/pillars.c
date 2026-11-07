/*

There are pillars near the road. The distance between the pillars is the same and the width of the pillars is the same.
Your function accepts three arguments:

1. number of pillars (≥ 1);
2. distance between pillars (10 - 30 meters);
3. width of the pillar (10 - 50 centimeters).

Calculate the distance between the first and the last pillar in centimeters (without the width of the first and last pillar).

*/

#include <assert.h>

int
pillars(int p, int d, int w)
{
	if (p < 2)
		return 0;
	return ((p - 1) * d * 100) + ((p - 2) * w);
}

int
main()
{
	assert(pillars(1, 10, 10) == 0);
	assert(pillars(2, 20, 25) == 2000);
	assert(pillars(11, 15, 30) == 15270);

	return 0;
}
