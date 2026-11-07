/*

You can create a list of all rationals 0 < r ≤ 1 by listing them ordered first by denominator and then by numerator:

1  1  1  2  1  3  1  2  3  4  1  5  1  2  3  4  5
-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
1  2  3  3  4  4  5  5  5  5  6  6  7  7  7  7  7
Note that we skip any rational number that already occurred before. E.g. 2/4 is skipped because we already listed 1/2.

In this challenge we're interested in the numerators only. Looking at the list above, write a function or program taking a positive integer n that returns the nth numerator from the list.

Testcases:

1 -> 1
2 -> 1
3 -> 1
4 -> 2
5 -> 1
6 -> 3
7 -> 1
8 -> 2
9 -> 3
50 -> 4
80 -> 15

*/

#include <assert.h>

int
gcd(int a, int b)
{
	int t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

// ported from @AlexRacer solution
int
numerator(int n)
{
	int x, y;

	x = y = 1;
	while (n > 1) {
		x += 1;
		if (x > y) {
			x = 1;
			y += 1;
		}
		if (gcd(x, y) < 2)
			n -= 1;
	}
	return x;
}

int
main(void)
{
	assert(numerator(1) == 1);
	assert(numerator(2) == 1);
	assert(numerator(3) == 1);
	assert(numerator(4) == 2);
	assert(numerator(5) == 1);
	assert(numerator(6) == 3);
	assert(numerator(7) == 1);
	assert(numerator(8) == 2);
	assert(numerator(9) == 3);
	assert(numerator(50) == 4);
	assert(numerator(80) == 15);

	return 0;
}
