/*

Wilson primes satisfy the following condition.
Let P represent a prime number.

Then ((P-1)! + 1) / (P * P) should give a whole number.

Your task is to create a function that returns true if the given number is a Wilson prime.

*/

#include <assert.h>

// https://oeis.org/A007540
bool
wilson(int n)
{
	return n == 5 || n == 13 || n == 563;
}

int
main()
{
	assert(wilson(5) == true);
	assert(wilson(13) == true);
	assert(wilson(563) == true);
	return 0;
}
