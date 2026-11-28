/*

You were given a string of integer temperature values. Create a function lowest_temp(t) and return the lowest value or None/null/Nothing if the string is empty.

*/

#include <assert.h>
#include <stdlib.h>
#include <limits.h>

long
min(long a, long b)
{
	return (a < b) ? a : b;
}

long
lowest(const char *s)
{
	char *ep;
	long r;

	if (!*s)
		return LONG_MIN;

	for (r = LONG_MAX; *s; s = ep)
		r = min(r, strtol(s, &ep, 10));
	return r;
}

int
main()
{
	assert(lowest("") == LONG_MIN);
	assert(lowest("-1 50 -4 20 22 -7 0 10 -8") == -8);
	return 0;
}
