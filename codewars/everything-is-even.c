/*

Here at Conformity Inc. we only like even things. We need you to put a stop to anything that does not conform to our strict even only policy.

Write a function that will convert any number to its nearest even number. When the number is halfway between two even numbers it should round away from zero.

Examples

1    => 2

0.5  => 0

-1   => -2

-0.5  => 0

*/

#include <assert.h>
#include <math.h>

int
ensureeven(double n)
{
	int m;

	m = trunc(n);
	if (!(m & 1))
		return m;
	m = (n < 0) ? -1 : 1;
	return trunc(n + m);
}

int
main()
{
	assert(ensureeven(1) == 2);
	assert(ensureeven(0.5) == 0);
	assert(ensureeven(-1) == -2);
	assert(ensureeven(-0.5) == 0);
	assert(ensureeven(1.356) == 2);
	assert(ensureeven(0) == 0);
	assert(ensureeven(11.3) == 12);
	assert(ensureeven(11.0) == 12);
	assert(ensureeven(10.9) == 10);

	return 0;
}
