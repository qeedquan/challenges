/*

A triangular number is a number that is the sum of n natural numbers from 1 to n. For example 1 + 2 + 3 + 4 = 10 so 10 is a triangular number.

Given a positive integer (0 < n <= 10000) as input (can be taken as an integer, or as a string), return the smallest possible triangular number that can be added to the input to create another triangular number.

For example given input 26, adding 10 results in 36, which is also a triangular number. There are no triangular numbers smaller than 10 that can be added to 26 to create another triangular number, so 10 is the correct result in this case.

0 is a triangular number, therefore if the input is itself a triangular number, the output should be 0

Testcases
Cases are given in the format input -> output (resulting triangular number)

0     -> 0   (0)
4     -> 6   (10)
5     -> 1   (6)
7     -> 3   (10)
8     -> 28  (36)
10    -> 0   (10)
24    -> 21  (45)
25    -> 3   (28)
26    -> 10  (36)
34    -> 21  (55)
10000 -> 153 (10153)

Scoring
This is code-golf so fewest bytes in each language wins!

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef long long vlong;

vlong
tri(vlong n)
{
	return n * (n + 1) / 2;
}

int
istri(vlong n)
{
	vlong s;

	if (n < 0)
		return 0;

	s = (-1 + sqrt(1 + 8 * n)) / 2;
	return tri(s) == n;
}

vlong
tridep(vlong n)
{
	vlong i, t;

	for (i = 0; i <= n; i++) {
		t = tri(i);
		if (istri(n + t))
			return t;
	}
	return -1;
}

int
main(void)
{
	assert(tridep(0) == 0);
	assert(tridep(4) == 6);
	assert(tridep(5) == 1);
	assert(tridep(7) == 3);
	assert(tridep(8) == 28);
	assert(tridep(10) == 0);
	assert(tridep(24) == 21);
	assert(tridep(25) == 3);
	assert(tridep(26) == 10);
	assert(tridep(34) == 21);
	assert(tridep(10000) == 153);

	return 0;
}
