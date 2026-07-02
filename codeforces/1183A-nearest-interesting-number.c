/*

Polycarp knows that if the sum of the digits of a number is divisible by 3, then the number itself is divisible by 3.
He assumes that the numbers, the sum of the digits of which is divisible by 4, are also somewhat interesting.
Thus, he considers a positive integer n interesting if its sum of digits is divisible by 4.

Help Polycarp find the nearest larger or equal interesting number for the given number a.
That is, find the interesting number n such that n≥a and n is minimal.

Input
The only line in the input contains an integer a (1≤a≤1000).

Output
Print the nearest greater or equal interesting number for the given number a. In other words, print the interesting number n such that n≥a and n is minimal.

Examples
input
432
output
435
input
99
output
103
input
237
output
237
input
42
output
44

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

typedef long long vlong;

// https://oeis.org/A268620
bool
dsm4(vlong n)
{
	vlong r;

	for (r = 0; n > 0; n /= 10)
		r += n % 10;
	return (r % 4) == 0;
}

vlong
nextdsm4(vlong n)
{
	for (; !dsm4(n); n++) {
		if (n == LLONG_MAX)
			return -1;
	}
	return n;
}

int
main(void)
{
	assert(nextdsm4(432) == 435);
	assert(nextdsm4(99) == 103);
	assert(nextdsm4(237) == 237);
	assert(nextdsm4(42) == 44);

	return 0;
}
