/*

Mubashir needs your help to find next integral perfect square after the one passed as a parameter.

Create a function which takes a given number n and returns next integral perfect square number. Return None if the given number is not a perfect square.

Examples
next_square(121) ➞ 144

next_square(625) ➞ 676

next_square(114) ➞ None
# 114 is not a perfect square

Notes
N/A

*/

#include <assert.h>
#include <math.h>

typedef long long vlong;

vlong
nextsquare(vlong n)
{
	vlong s;

	if (n < 0)
		return -1;

	s = sqrt(n);
	if (s * s != n)
		return -1;

	return (s + 1) * (s + 1);
}

int
main(void)
{
	assert(nextsquare(121) == 144);
	assert(nextsquare(625) == 676);
	assert(nextsquare(319225) == 320356);
	assert(nextsquare(15241383936) == 15241630849);
	assert(nextsquare(155) == -1);
	assert(nextsquare(342786627) == -1);

	return 0;
}
