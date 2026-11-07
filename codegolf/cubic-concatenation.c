/*

Challenge
Given three non-negative integers a, b and c, decide if the sum of their cubes is equal to the concatenation of those numbers, aka: a^3+b^3+c^3=a⌢b⌢c

Test cases
Truthy

(1,5,3) // 1^3 + 5^3 + 3^3 = 153
(2,2,13)
(4,0,7)
(10,0,0)
(10,0,1)
(22,18,59)
(98,28,27)
(166,500,333)
(828,538,472)
Falsy

(1,2,3) // 1^3 + 2^3 + 3^3 = 32 != 123
(4,5,6)
(6,0,0)
(166,500,334)
(200,0,200)
You can assume there are no leading zeroes.

This is code-golf, so the shortest code wins.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long uvlong;

bool
equivalent(uvlong a, uvlong b, uvlong c)
{
	char s[128];
	uvlong x, y;

	snprintf(s, sizeof(s), "%llu%llu%llu", a, b, c);
	x = (a * a * a) + (b * b * b) + (c * c * c);
	y = strtoull(s, NULL, 10);
	return x == y;
}

int
main()
{
	assert(equivalent(1, 5, 3) == true);
	assert(equivalent(2, 2, 13) == true);
	assert(equivalent(4, 0, 7) == true);
	assert(equivalent(10, 0, 0) == true);
	assert(equivalent(10, 0, 1) == true);
	assert(equivalent(22, 18, 59) == true);
	assert(equivalent(98, 28, 27) == true);
	assert(equivalent(166, 500, 333) == true);
	assert(equivalent(828, 538, 472) == true);

	assert(equivalent(1, 2, 3) == false);
	assert(equivalent(4, 5, 6) == false);
	assert(equivalent(6, 0, 0) == false);
	assert(equivalent(166, 500, 334) == false);
	assert(equivalent(200, 0, 200) == false);

	return 0;
}
