/*

Task
Given any positive integer x ≤ 4000, find the smallest positive integer m such that mx consists of all 9's. Return -1 if no such m exists.

Examples:
allNines(11) -> 9, because 11*9 = 99.

allNines(12) -> -1, because 12 is even, so no multiple of it can be all 9's.

allNines(13) -> 76923, because 13*76923 = 999999, and no smaller positive integer, when multiplied by 13, generates an integer containing only 9's.

NOTE: Although x ≤ 4000, m can be very very LARGE. (x is limited to 4000 because at x = 4327, the value of m exceeds Python's limit (4300 digits) for integer -> string conversion.)

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

typedef unsigned long long uvlong;
typedef long long vlong;

vlong
allnines(uvlong x)
{
	uvlong r;

	if (!(x % 2) || !(x % 5))
		return -1;

	r = 9;
	while (r % x) {
		if (((ULLONG_MAX - 9) / 10) <= r)
			return 0;

		r = (r * 10) + 9;
	}
	return r / x;
}

int
main()
{
	assert(allnines(11) == 9);
	assert(allnines(12) == -1);
	assert(allnines(13) == 76923);

	return 0;
}
