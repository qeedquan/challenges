/*

Given an integer n, your task is to determine whether it is a perfect square that when reversed, is still a perfect square. You may assume n is always positive.

When numbers such as 100 (10x10) are reversed the result may have leading zeros (001) In this case, ignore the leading zeros and treat it as 1 (1x1).

Test cases
1 => True
4 => True
9 => True
441 => True
1234567654321 => True
100 => True

3 => False
25 => False
1784 => False
Shortest code wins!

*/

#include <assert.h>
#include <stdbool.h>
#include <math.h>

typedef unsigned long long uvlong;

uvlong
rev(uvlong n)
{
	uvlong r;

	for (r = 0; n > 0; n /= 10)
		r = (r * 10) + (n % 10);
	return r;
}

bool
sq(uvlong n)
{
	uvlong s;

	s = sqrt(n);
	return s * s == n;
}

// https://oeis.org/A061457
bool
rsq(uvlong n)
{
	return sq(n) && sq(rev(n));
}

int
main(void)
{
	assert(rsq(1) == true);
	assert(rsq(4) == true);
	assert(rsq(9) == true);
	assert(rsq(441) == true);
	assert(rsq(1234567654321ULL) == true);
	assert(rsq(100) == true);

	assert(rsq(3) == false);
	assert(rsq(25) == false);
	assert(rsq(1784) == false);

	return 0;
}
