/*

You are given positive integers, a and b (a<b).

Find a positive integer k such that gcd(a+k,b+k) is maximized.

If there are multiple values of k that satisfy the condition above, return the smallest one.

Here gcd(x,y) means the greatest common divisor of x and y.

Constraints

1≤a<b≤10^18

*/

#include <assert.h>
#include <stdlib.h>

typedef long long vlong;

vlong
getk(vlong a, vlong b)
{
	vlong k, m;

	if (a == b)
		return 0;

	m = llabs(a - b);
	k = (m - (a % m)) % m;
	return (k) ? k : m;
}

int
main()
{
	assert(getk(5, 7) == 1);
	assert(getk(2, 10) == 6);
	assert(getk(100, 200) == 100);
	assert(getk(123, 456) == 210);

	return 0;
}
