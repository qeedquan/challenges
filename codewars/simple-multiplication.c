/*

This kata is about multiplying a given number by eight if it is an even number and by nine otherwise.

*/

#include <assert.h>

int
simpmul(int x)
{
	return x * (8 + (x & 1));
}

int
main()
{
	assert(simpmul(2) == 16);
	assert(simpmul(3) == 27);
	return 0;
}
