/*

You certainly can tell which is the larger number between 2^10 and 2^15.

But what about, say, 2^10 and 3^10? You know this one too.

Things tend to get a bit more complicated with both different bases and exponents: which is larger between 3^9 and 5^6?

Well, by now you have surely guessed that you have to build a function to compare powers, returning -1 if the first member is larger, 0 if they are equal, 1 otherwise; powers to compare will be provided in the [base, exponent] format:

compare_powers([2,10],[2,15])==1
compare_powers([2,10],[3,10])==1
compare_powers([2,10],[2,10])==0
compare_powers([3,9],[5,6])==-1
compare_powers([7,7],[5,8])==-1

Only positive integers will be tested, including bigger numbers - you are warned now, so be diligent try to implement an efficient solution not to drain too much on CW resources ;)!

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
cmp(int x1, int p1, int x2, int p2)
{
	double v1, v2;

	v1 = log(x1) * p1;
	v2 = log(x2) * p2;
	if (v1 > v2)
		return -1;
	if (v1 == v2)
		return 0;
	return 1;
}

int
main()
{
	assert(cmp(2, 10, 2, 15) == 1);
	assert(cmp(2, 10, 3, 10) == 1);
	assert(cmp(2, 10, 2, 10) == 0);
	assert(cmp(3, 9, 5, 6) == -1);
	assert(cmp(7, 7, 5, 8) == -1);

	return 0;
}
