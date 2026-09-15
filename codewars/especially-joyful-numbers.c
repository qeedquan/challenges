/*

Positive integers that are divisible exactly by the sum of their digits are called Harshad numbers. The first few Harshad numbers are: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 18, ...

We are interested in Harshad numbers where the product of its digit sum s and s with the digits reversed, gives the original number n. For example consider number 1729:

its digit sum, s = 1 + 7 + 2 + 9 = 19
reversing s = 91
and 19 * 91 = 1729 --> the number that we started with.
Complete the function which tests if a positive integer n is Harshad number, and returns True if the product of its digit sum and its digit sum reversed equals n; otherwise return False.

*/

#include <assert.h>

// https://oeis.org/A110921
bool
joyful(int n)
{
	switch (n) {
	case 1:
	case 81:
	case 1458:
	case 1729:
		return true;
	}
	return false;
}

int
main()
{
	assert(joyful(1997) == false);
	assert(joyful(1998) == false);
	assert(joyful(1729) == true);
	assert(joyful(18) == false);

	return 0;
}
