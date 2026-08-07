/*

You are an aerial firefighter (someone who drops water on fires from above in order to extinguish them) and your goal is to work out the minimum amount of bombs you need to drop in order to fully extinguish the fire (the fire department has budgeting concerns and you can't just be dropping tons of bombs, they need that money for the annual christmas party).

The given string is a 2D plane of random length consisting of two characters:

x representing fire
Y representing buildings.
Water that you drop cannot go through buildings and therefore individual sections of fire must be addressed separately.

Your water bombs can only extinguish contiguous sections of fire up to a width (parameter w).

You must return the minimum number of waterbombs it would take to extinguish the fire in the string.

Note: all inputs will be valid.

Examples
"xxYxx" and w = 3      -->  2 waterbombs needed
"xxYxx" and w = 1      -->  4
"xxxxYxYx" and w = 5   -->  3
"xxxxxYxYx" and w = 2  -->  5

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
waterbombs(const char *f, int w)
{
	int c, v;
	size_t i;

	c = 0;
	v = w;
	for (i = 0; f[i]; i++) {
		if ((f[i] == 'Y' && v != w) || (v == 1 && f[i] != 'Y')) {
			c += 1;
			v = w;
		} else if (f[i] == 'x')
			v -= 1;
	}
	if (v < w)
		c += 1;
	return c;
}

int
main()
{
	assert(waterbombs("xxxxYxYx", 4) == 3);
	assert(waterbombs("xxYxx", 3) == 2);
	assert(waterbombs("xxYxx", 1) == 4);
	assert(waterbombs("xxxxYxYx", 5) == 3);
	assert(waterbombs("xxxxxYxYx", 2) == 5);

	return 0;
}
