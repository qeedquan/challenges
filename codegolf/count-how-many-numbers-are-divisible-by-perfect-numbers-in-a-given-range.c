/*

Given two arbitrary integers a and b, count how many numbers are divisible by perfect numbers in that given range (a and b both are inclusive).

In mathematics, a perfect number is a positive integer that is the sum of its proper positive divisors, that is, the sum of the positive divisors excluding the number itself.Equivalently, a perfect number is a number that is half the sum of all of its positive divisors (including itself), or σ(n)=2n.

Input:

1 100
Output:

18
Use stdin and stdout for Input/Output
Your code must handle big integers, so it is not good enough to hard-code a list of perfect numbers.
Shortest code wins

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
count(uvlong a, uvlong b)
{
	// https://oeis.org/A000396
	static const uvlong tab[] = {
		6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 2305843008139952128
	};

	uvlong c;
	size_t i;

	for (c = 0; a <= b; a++) {
		for (i = 0; i < nelem(tab); i++) {
			if (!(a % tab[i])) {
				c += 1;
				break;
			}
		}
	}
	return c;
}

int
main()
{
	assert(count(1, 100) == 18);

	return 0;
}
